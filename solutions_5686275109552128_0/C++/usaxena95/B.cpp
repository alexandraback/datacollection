/*
-----------------------------------------------------------------------------
Author :            ---------------------------------------------------------
    UTKAR$H $AXENA  ---------------------------------------------------------
    IIT INDORE      ---------------------------------------------------------
-----------------------------------------------------------------------------
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre 	freopen("0.in","r",stdin),freopen("0.out","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define M 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
int N;
int A[1005];
int tell()
{
	int MAX=0;

	for(int i=1;i<=N;++i)
		MAX=max(MAX,A[i]);

	int ans=M;
	for(int X=1;X<=MAX;++X)
	{
		int tmp=0;
		for(int i=1;i<=N;++i)
		{
			tmp+=(A[i]/X+(A[i]%X!=0))-1;
		}
		ans=min(ans,X+tmp);
	}
	return ans;
}
int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("JAM.out","w",stdout);
	int t;
	cin>>t;
	for(int T=1;T<=t;++T)
	{
		cin>>N;
		for(int i=1;i<=N;++i)
		{
			scan(A[i]);
		}
		printf("Case #%d: %d\n",T,tell());

	}
}
