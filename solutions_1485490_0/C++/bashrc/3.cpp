#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#define PR(x) printf(#x"=%d\n",x)
#define READ2(x,y) scanf("%d %d",&x,&y)
#define REP(i,a) for(int i=0;i<a;i++)
#define READ(x) scanf("%d",&x)
#define PRARR(x,n) for(int i=0;i<n;i++)printf(#x"[%d]=\t%d\n",i,x[i])
using namespace std;
const int MAX=201;
typedef long long LL;
int t,n,m;
LL dpstates[2][MAX];
LL IMP[2][MAX],bst[MAX][MAX];
LL ANS;
inline void btrack(int i,int j,LL cost) {
    ANS=max(ANS,cost);
    if(cost<bst[i][j]) return;
    bst[i][j]=cost;
    if(i>n || j>m) return;
    if(dpstates[0][i]==dpstates[1][j]) {
        LL tmp=min(IMP[0][i],IMP[1][j]);
        
        
        if(IMP[0][i]<IMP[1][j]) 
        {
            IMP[1][j]-=tmp;
            btrack(i+1,j,cost+tmp);
            IMP[1][j]+=tmp;
        }
        else if(IMP[0][i]==IMP[1][j]) btrack(i+1,j+1,cost+tmp);
        else 
        {
            IMP[0][i]-=tmp;
            btrack(i,j+1,cost+tmp);
            IMP[0][i]+=tmp;
        }
    }
    btrack(i+1,j,cost);
    btrack(i,j+1,cost);
}
 
int main()
{
   
   int t;
   scanf("%d",&t);
    int j=0;
    while(t--)
     {
     	printf("Case #%d: ",j+1);j++;
        scanf("%d %d",&n,&m);
        memset(bst,0,sizeof(bst));
        for(int i=1; i<=n;i++) scanf("%lld %lld",&IMP[0][i],&dpstates[0][i]);
        for(int i=1; i<=m;i++) scanf("%lld %lld",&IMP[1][i],&dpstates[1][i]);
        ANS=0;
        btrack(1,1,0);
        printf("%lld\n",ANS);
      }
    return 0;
}
