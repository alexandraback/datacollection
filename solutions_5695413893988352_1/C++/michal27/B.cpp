#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

string s1,s2;
ll v1=-1000000000000000000ll,v2=1000000000000000000ll;

void ries(ll c, ll j, int n, int typ) {
    //printf("%lld %lld %d %d\n",c,j,n,typ);
    if(n==s1.length()) {
        if(abs(c-j)<abs(v2-v1)) {
            v1=c; v2=j;
        }
        else if(abs(c-j)==abs(v2-v1)) {
            if(c<v1 || (c==v1 && j<v2)) {
                v1=c; v2=j;
            }
        }
        return;
    }
    c*=10; j*=10;
    if(typ==0) {
        if(s1[n]=='?' && s2[n]=='?') {
            ries(c,j,n+1,0);
            ries(c+1,j,n+1,1);
            ries(c,j+1,n+1,2);
        }
        else if(s1[n]=='?') {
            int p=s2[n]-'0';
            ries(c+p,j+p,n+1,0);
            if(p!=0) ries(c+p-1,j+p,n+1,2);
            if(p!=9) ries(c+p+1,j+p,n+1,1);
        }
        else if(s2[n]=='?') {
            int p=s1[n]-'0';
            ries(c+p,j+p,n+1,0);
            if(p!=9) ries(c+p,j+p+1,n+1,2);
            if(p!=0) ries(c+p,j+p-1,n+1,1);
        }
        else {
            if(s1[n]>s2[n]) ries(c+s1[n]-'0',j+s2[n]-'0',n+1,1);
            else if(s1[n]<s2[n]) ries(c+s1[n]-'0',j+s2[n]-'0',n+1,2);
            else ries(c+s1[n]-'0',j+s2[n]-'0',n+1,0);
        }
    }
    if(typ==1) {
        if(s1[n]=='?' && s2[n]=='?') {
            ries(c+0,j+9,n+1,1);
        }
        else if(s1[n]=='?') {
            int p=s2[n]-'0';
            ries(c,j+p,n+1,1);
        }
        else if(s2[n]=='?') {
            int p=s1[n]-'0';
            ries(c+p,j+9,n+1,1);
        }
        else {
            ries(c+s1[n]-'0',j+s2[n]-'0',n+1,1);
        }
    }
    if(typ==2) {
        if(s1[n]=='?' && s2[n]=='?') {
            ries(c+9,j+0,n+1,2);
        }
        else if(s1[n]=='?') {
            int p=s2[n]-'0';
            ries(c+9,j+p,n+1,2);
        }
        else if(s2[n]=='?') {
            int p=s1[n]-'0';
            ries(c+p,j+0,n+1,2);
        }
        else {
            ries(c+s1[n]-'0',j+s2[n]-'0',n+1,2);
        }
    }
}

void solve(int por) {
    char C[100],D[100];
    scanf(" %s %s",C,D);
    s1=C; s2=D;
    v1=-1000000000000000000ll; v2=1000000000000000000ll;
    ries(0,0,0,0);
    vector<int> V1,V2;
    //printf("%lld %lld\n",v1,v2);
    while(v1>0) {
        V1.push_back(v1%10);
        v1/=10;
    }
    while(v2>0) {
        V2.push_back(v2%10);
        v2/=10;
    }
    while(V1.size() != s1.length()) V1.push_back(0);
    while(V2.size() != s2.length()) V2.push_back(0);
    reverse(V1.begin(),V1.end());
    reverse(V2.begin(),V2.end());
    printf("Case #%d:",por);
    printf(" "); For(i,V1.size()) printf("%d",V1[i]);
    printf(" "); For(i,V2.size()) printf("%d",V2[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d",&n);
    For(i,n) solve(i+1);
}
