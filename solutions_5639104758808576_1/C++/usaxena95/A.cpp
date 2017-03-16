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
string S;
bool tell(int X)
{
	for(int i=0;i<=N;++i)
	{
		if(X<i)
			return 0;
		X=X + (S[i]-'0');
	}
	return 1;
}
int bin(int i,int j)
{
	if(i==j)
		return i;
	int mid=(i+j)/2;
	if(tell(mid))
		return bin(i,mid);
	else
		return bin(mid+1,j);
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("0.out","w",stdout);
	int t;
	cin>>t;
	for(int T=1;T<=t;++T)
	{
		cin>>N>>S;
		printf("Case #%d: %d\n",T,bin(0,1000000));
	}
}
