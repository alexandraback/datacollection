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
#define sgn(x) ((x)>0?(1):-(1))
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
map<pii ,int> mp;
int P[10000+5],S[10000+5],A[10000+5];
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("ans.out","w",stdout);
	int t;
	mp[mpa(1,1)]=1;
	mp[mpa(2,2)]=-1;
	mp[mpa(3,3)]=-1;
	mp[mpa(4,4)]=-1;

	mp[mpa(1,2)]=2;
	mp[mpa(1,3)]=3;
	mp[mpa(1,4)]=4;

	mp[mpa(2,1)]=2;
	mp[mpa(2,3)]=4;
	mp[mpa(2,4)]=-3;

	mp[mpa(3,1)]=3;
	mp[mpa(3,2)]=-4;
	mp[mpa(3,4)]=2;

	mp[mpa(4,1)]=4;
	mp[mpa(4,2)]=3;
	mp[mpa(4,3)]=-2;

	cin>>t;
	for(int T=1;T<=t;++T)
	{
		int N,X;
		string ST;
		cin>>N>>X>>ST;
		string L="";
		for(int i=1;i<=X;++i)
			L+=ST;

		for(int i=1;i<=N*X;++i)
		{
			A[i]=(int)(L[i-1]-'i'+2);
		}
		P[1]=A[1];
		for(int i=2;i<=N*X;++i)
		{
			P[i]=mp[mpa(abs(P[i-1]),A[i])]*sgn(P[i-1]);
		}
		S[N*X]=A[N*X];

		for(int i=N*X-1;i>=1;--i)
		{
			S[i]=mp[mpa(A[i],abs(S[i+1]))]*sgn(S[i+1]);
		}

		int ans=0,found=0;
		for(int i=1;i<N*X;++i)
		{
			if(P[i]==4 and S[i+1]==4 and found==1)
				ans=1;
			if(P[i]==2)
				found=1;
		}
		if(ans)
			printf("Case #%d: YES\n",T);
		else
			printf("Case #%d: NO\n",T);
	}
}
