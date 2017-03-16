#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int T,panjang;
long long hasil1,hasil2,pangkat[20],best;
char angka1[20],angka2[20];
pair<long long,long long> jawab;

long long abso(long long x) {
    return (x >= 0)? x : -x;
}

void check1(int mulai,long long a1,long long a2) {
    for (int i=mulai;i<panjang;++i) {
        if (angka1[i] == '?') a1 += 0LL*pangkat[panjang-1-i];
        else a1 += pangkat[panjang-1-i] * (angka1[i]-'0');
        if (angka2[i] == '?') a2 += 9LL*pangkat[panjang-1-i];
        else a2 += pangkat[panjang-1-i] * (angka2[i]-'0');
    }
    //cout<<a1<<" "<<a2<<endl;
    
    if (best == -1 || abso(a1-a2) < best) {
        best = abso(a1-a2);
        jawab = make_pair(a1,a2);
    } else if (abso(a1-a2) == best) jawab = min(jawab,make_pair(a1,a2));
}

void check2(int mulai,long long a1,long long a2) {
    for (int i=mulai;i<panjang;++i) {
        if (angka1[i] == '?') a1 += 9LL*pangkat[panjang-1-i];
        else a1 += pangkat[panjang-1-i] * (angka1[i]-'0');
        if (angka2[i] == '?') a2 += 0LL*pangkat[panjang-1-i];
        else a2 += pangkat[panjang-1-i] * (angka2[i]-'0');
    }
    //cout<<a1<<" "<<a2<<endl;
    
    if (best == -1 || abso(a1-a2) < best) {
        best = abso(a1-a2);
        jawab = make_pair(a1,a2);
    } else if (abso(a1-a2) == best) jawab = min(jawab,make_pair(a1,a2));
}

void print_ans(long long x) {
    int idx = panjang-1;
    printf(" ");
    while (idx > 0 && pangkat[idx] > x) {
        printf("0");
        --idx;
    }
    printf("%I64d",x);
}

int main() {
    pangkat[0] = 1;
    for (int i=1;i<=18;++i) pangkat[i] = 10LL*pangkat[i-1];
    
    scanf("%d",&T);
    for (int l=1;l<=T;++l) {
        scanf("%s %s",angka1,angka2);
        panjang = strlen(angka1);
        best = -1;
        
        for (int i=0;i<=panjang;++i) {
            //Check if possible to set every digit in front of i same.
            hasil1 = hasil2 = 0;
            bool flag = true;
            for (int j=0;j<i;++j) {
                if (angka1[j] != '?' && angka2[j] != '?') {
                    if (angka1[j] != angka2[j]) {
                        flag = false;
                        break;
                    } else {
                        hasil1 += pangkat[panjang-1-j]*(angka1[j]-'0');
                        hasil2 += pangkat[panjang-1-j]*(angka2[j]-'0');
                    }
                } else if (angka1[j] != '?') {
                    hasil1 += pangkat[panjang-1-j]*(angka1[j]-'0');
                    hasil2 += pangkat[panjang-1-j]*(angka1[j]-'0');                    
                } else if (angka2[j] != '?') {
                    hasil1 += pangkat[panjang-1-j]*(angka2[j]-'0');
                    hasil2 += pangkat[panjang-1-j]*(angka2[j]-'0');                
                } else {
                    //Nothing, just use 0.               
                }
            }
            
            if (!flag) break;
            if (i == panjang) {
                check1(panjang,hasil1,hasil2);
                break;
            }
            
            //Try to make angka1 bigger, just
            if (angka1[i] != '?' && angka2[i] != '?') {
                if (angka1[i] > angka2[i]) {
                    check1(i+1,hasil1+pangkat[panjang-1-i]*(angka1[i]-'0')
                              ,hasil2+pangkat[panjang-1-i]*(angka2[i]-'0'));
                }
            } else if (angka1[i] != '?') {
                if (angka1[i] > '0') {
                    check1(i+1,hasil1+pangkat[panjang-1-i]*(angka1[i]-'0')
                              ,hasil2+pangkat[panjang-1-i]*(angka1[i]-'0'-1));                    
                }                
            } else if (angka2[i] != '?') {
                if (angka2[i] < '9') {
                    check1(i+1,hasil1+pangkat[panjang-1-i]*(angka2[i]-'0'+1)
                              ,hasil2+pangkat[panjang-1-i]*(angka2[i]-'0'));
                }                
            } else {
                check1(i+1,hasil1+pangkat[panjang-1-i],hasil2);                
            }
            
            //Now angka2
            if (angka1[i] != '?' && angka2[i] != '?') {
                if (angka1[i] < angka2[i]) {
                    check2(i+1,hasil1+pangkat[panjang-1-i]*(angka1[i]-'0')
                              ,hasil2+pangkat[panjang-1-i]*(angka2[i]-'0'));
                }
            } else if (angka1[i] != '?') {
                if (angka1[i] < '9') {
                    check2(i+1,hasil1+pangkat[panjang-1-i]*(angka1[i]-'0')
                              ,hasil2+pangkat[panjang-1-i]*(angka1[i]-'0'+1));                    
                }                
            } else if (angka2[i] != '?') {
                if (angka2[i] > '0') {
                    check2(i+1,hasil1+pangkat[panjang-1-i]*(angka2[i]-'0'-1)
                              ,hasil2+pangkat[panjang-1-i]*(angka2[i]-'0'));
                }                
            } else {
                check2(i+1,hasil1,hasil2+pangkat[panjang-1-i]);                
            }            
        }
        
        printf("Case #%d:",l);
        print_ans(jawab.first);
        print_ans(jawab.second);
        printf("\n");
    }
    return 0;
}
