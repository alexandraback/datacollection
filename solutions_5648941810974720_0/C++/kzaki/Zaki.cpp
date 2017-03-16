#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<bitset>
#define pii pair<int,int>
#define A first
#define B second
using namespace std;
int n,a[27],c[10];
char s[20001];
void Do(){
    scanf("%s",s);
    for(int i='a'-'a';i<='z'-'a';i++) a[i] = 0;
    for(int i=0;i<10;i++) c[i] = 0;
    for(int i=0;s[i]!='\0';i++)
        a[s[i]-'A']++;
    while(a['Z'-'A'] != 0){
        c[0]++;
        a['Z'-'A']--; a['E'-'A']--;
        a['R'-'A']--; a['O'-'A']--;
    }
    while(a['W'-'A'] != 0){
        c[2]++;
        a['T'-'A']--; a['W'-'A']--; a['O'-'A']--;
    }
    while(a['X'-'A'] != 0){
        c[6]++;
        a['S'-'A']--; a['I'-'A']--; a['X'-'A']--;
    }
    while(a['G'-'A'] != 0){
        c[8]++;
        a['E'-'A']--; a['I'-'A']--; a['G'-'A']--;
        a['H'-'A']--; a['T'-'A']--;
    }
    while(a['T'-'A'] != 0){
        c[3]++;
        a['T'-'A']--; a['H'-'A']--; a['R'-'A']--;
        a['E'-'A']--; a['E'-'A']--;
    }
    while(a['U'-'A'] != 0){
        c[4]++;
        a['F'-'A']--; a['O'-'A']--; a['U'-'A']--; a['R'-'A']--;
    }
    while(a['F'-'A'] != 0){
        c[5]++;
        a['F'-'A']--; a['I'-'A']--; a['V'-'A']--; a['E'-'A']--;
    }
    while(a['V'-'A'] != 0){
        c[7]++;
        a['S'-'A']--; a['E'-'A']-=2; a['V'-'A']--; a['N'-'A']--;
    }
    while(a['O'-'A'] != 0){
        c[1]++;
        a['O'-'A']--; a['N'-'A']--; a['E'-'A']--;
    }
    while(a['N'-'A'] != 0){
        c[9]++;
        a['N'-'A']--; a['I'-'A']--; a['N'-'A']--; a['E'-'A']--;
    }
    for(int i=0;i<=9;i++)
        for(int j=0;j<c[i];j++) printf("%d",i);
}
int main(){
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int rr=1;rr<=T;rr++){
        printf("Case #%d: ",rr);
        Do();
        printf("\n");
    }
    return 0;
}
