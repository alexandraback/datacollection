#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

#define FIN

using namespace std;

typedef long long LL;

const int MAXN = 11;

int E,R,N;
int v[MAXN];
int dp[MAXN][6];

int doit() {
	int i,j,k,w,f;
	
	for(i=0;i<=N;i++)
	for(j=0;j<=E;j++)
	dp[i][j]=-1;
	
	int res=0;
	dp[0][E]=0;
	for(i=0;i<N;i++)
	for(j=0;j<=E;j++)
	if(dp[i][j]!=-1) {
		for(k=0;k<=j;k++) {
			w=dp[i][j]+k*v[i];
			f=min(j-k+R,E);
			if(w>dp[i+1][f])
			{
				dp[i+1][f]=w;
				if(w>res) res=w;
			}
		}
	}
	return res;
}

int main()
{
    #ifdef FIN
        freopen("B-small-attempt0.in","r",stdin);
        freopen("B-small-attempt0.out","w",stdout);
    #endif
    int cas,T;
    cin>>T;
    for(cas=1;cas<=T;cas++) {
        cin>>E>>R>>N;
        for(int i=0;i<N;i++)
        scanf("%d",&v[i]);
        cout<<"Case #"<<cas<<": "<<doit()<<endl;
    }
    return 0;
}

