#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <map>
#include <string.h>
#include <assert.h>
#include <set>
#include <cmath>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define inf 1000000007
#define mod 1000000007
#define x first
#define y second
#define pi acos(-1.0)
#define DBG(x) cerr<<(#x)<<"="<<x<<"\n";
//#define dprintf(...) 
#define hash _hash
//#define dprintf(...) fprintf(outFile,__VA_ARGS__)
 
#define FOREACH(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ull unsigned long long
#define ll long long
#define N 135010
 
template <class T,class U>inline void Max(T &a,U b){if(a<b)a=b;}
template <class T,class U>inline void Min(T &a,U b){if(a>b)a=b;}
 
//FILE* outFile;
 
inline void add(int &a,int b){a+=b;while(a>=mod)a-=mod;}
 
int pow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*(ll)a%mod;
        a=(ll)a*a%mod;b>>=1;
    }
    return ans;
}

char s[][9]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int v[256];
char t[2002];
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int m,j,k,i,T,n,ca=0;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++ca);
        scanf("%s",t);
        n=strlen(t);
        memset(v,0,sizeof(v));
        rep(i,0,n)v[t[i]]++;
        int a[10];
        memset(a,0,sizeof(a));
        if(v['Z']){
            a[0]=v['Z'];
            for(i=0;s[0][i];i++){
                v[s[0][i]]-=a[0];
            }
        }
        if(v['W']){
            a[2]=v['W'];
            for(i=0;s[2][i];i++){
                v[s[2][i]]-=a[2];
            }
        }
        if(v['U']){
            a[4]=v['U'];
            for(i=0;s[4][i];i++){
                v[s[4][i]]-=a[4];
            }
        }
        if(v['G']){
            a[8]=v['G'];
            for(i=0;s[8][i];i++){
                v[s[8][i]]-=a[8];
            }
        }
        if(v['O']){
            a[1]=v['O'];
            for(i=0;s[1][i];i++){
                v[s[1][i]]-=a[1];
            }
        }
        if(v['F']){
            a[5]=v['F'];
            for(i=0;s[5][i];i++){
                v[s[5][i]]-=a[5];
            }
        }
        if(v['V']){
            a[7]=v['V'];
            for(i=0;s[7][i];i++){
                v[s[7][i]]-=a[7];
            }
        }
        a[3]=v['T'],a[6]=v['S'];a[9]=v['N']/2;
        rep(i,0,10)rep(j,0,a[i])printf("%d",i);puts("");
    }
    //cerr<<1.*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}