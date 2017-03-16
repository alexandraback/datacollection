#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<list>
#include<queue>
#include<stack>
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
using namespace std;

void sss(vector<int>& v, const char s[])
{
    char a[50];
    strcpy(a, s);

    int len = 0;
    for(; a[len]; len++)if(a[len] == '?')a[len] = '0';
    v.push_back(atoi(a));
    
    
    int dd = 1;
    for(int i=len-1; i>=0; i--){
        if(s[i] == '?'){
            int n = v.size();
            for(int in = 0; in < n; in++){
                for(int k=1; k<=9; k++) v.push_back( v[in] + dd * k );
            }
        }
        dd*=10;
    }
    sort(v.begin(), v.end());
    
    //printf("vvv ");
    //for(int i=0; i<v.size(); i++)printf("%d ", v[i]);
    //printf("\n");
}

int m ;
int i, ia, ib;
vector<int> va;
vector<int> vb;
vector<int>::iterator p;

void ttt(int a){
    int v = abs(a - *p);
    if(m > v || (m == v && ib>=0 && vb[ib] > *p)){
        m = v;
        ia = i;
        ib = p - vb.begin();
    }
}

void q(){
    char A[30];
    char B[30];
    RS(A);
    RS(B);
    
    //printf("\n%s %s\n", A, B);
    /*
    char la, lb;
    int ll = -1;
    for(int i=0; A[i]; i++){
        //printf("-0 %d %c %c\n", i, A[i], B[i]);
        if(A[i] == '?' && B[i] == '?'){
            la = A[i];
            lb = B[i];
            ll = i;
            A[i] = '0';
            B[i] = '0';
            continue;
        }
        if(A[i] == '?'){
            la = A[i];
            lb = B[i];
            ll = i;
            A[i] = B[i];
            continue;
        }
        if(B[i] == '?'){
            la = A[i];
            lb = B[i];
            ll = i;
            B[i] = A[i];
            continue;
        }
        if(A[i] == B[i]) continue;
        if(ll >= 0){
            A[ll] = la;
            B[ll] = lb;
        }
        break;
    }*/
    //printf("\n%s %s\n", A, B);
    
    va.clear();
    vb.clear();
    
    sss(va, A);
    sss(vb, B);
    
    m = 0x7fffffff;
    ib = -1;

    for(i = 0; i<va.size(); i++){
        p = lower_bound(vb.begin(), vb.end(), va[i]);
        if(p != vb.end()){
            p++;
            if(p != vb.end())ttt(va[i]);
            p--;
            ttt(va[i]);
        }
        if(p != vb.begin()){
            p--;
            ttt(va[i]);
        }
    }
    
    int n = strlen(A);
    char fmt[30];
    sprintf(fmt, "%%0%dd %%0%dd\n", n, n);
    printf(fmt, va[ia], vb[ib]);
}
    

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
        fflush(stdout);
    }
    return 0;
}

