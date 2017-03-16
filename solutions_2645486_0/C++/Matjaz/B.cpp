#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

int T;

int dp[100][100];
int e,r,n;
int v[100];

int find(int x,int E){
    if (x==n-1) return v[x]*E;
    if (dp[x][E]!=-1) return dp[x][E];
    if (E>0) dp[x][E]=find(x,E-1)+v[x];
    dp[x][E]=max(dp[x][E],find(x+1,min(E+r,e)));
    return dp[x][E];
    }


int solve(){
    memset(dp,-1,sizeof dp);
    scanf("%d %d %d",&e,&r,&n);
    for (int i=0;i<n;i++) scanf("%d",&v[i]);
    return find(0,e);    
    }

int main(){
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        printf("Case #%d: %d\n",i+1,solve());
        }
    return 0;
    }
