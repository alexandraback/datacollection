// __________ AUTHOR INFO __________
// Name/    Khaled Alam
// Email/   khaledalam.net@gmail.com
// Insta/   @MrKhaledAlam
// Twitter/ @Mr_KhaledAlam
// Website/ KhaledAlam.net
//__________________________________


#include <bits/stdc++.h>

/*
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
*/

//____________________
using namespace std;

#define UI  unsigned int
#define LL  long long
#define ULL unsigned long long
#define V   vector
#define oo   I (1e9)
#define MOD  I (1e9+7)
#define PI  3.14159265358979323846;
#define SZ(X) (int)X.size()
#define FI first
#define SE second
#define PB push_back
#define PF push_front
#define MP make_pair
#define ODD(n)  (n&1)
#define ONES(N) __builtin_popcount((LL)N)
#define ALL(C)  C.begin(), C.end()
#define rALL(C) C.rbegin(), C.rend()
#define rSORT(C) sort(ALL(C), std::greater<LL>())
#define FOR(V,A,Z,P)   for(LL V=A; V<Z;  V+=P)
#define FORe(V,A,Z,P)  for(LL V=A; V<=Z; V+=P)
#define rFOR(V,A,Z,P)  for(LL V=A; V>Z;  V-=P)
#define rFORe(V,A,Z,P) for(LL V=A; V>=Z; V-=P)
#define IOS ios_base::sync_with_stdio(0)
#define SET(A,V) memset(A,(typeof(V))V,sizeof(A))
#define iFILE(N) freopen(#N, "r", stdin)
#define oFILE(N) freopen(#N, "w", stdout)
#define TM cerr<<"Time elapsed: "<<clock()<<" ms\n";
//#define MX
//I vis[100];

typedef long long int ll;

ll b,m;
ll ans[50][50];
ll dp[50];

void init()
{
	for(ll i=0;i<50;i++)
	{
		for(ll j=0;j<50;j++)
			ans[i][j]=0;
		dp[i]=0;
	}

}

void build()
{
	ll i,j;
	for(i=b;i>=0;i--)
	{
		for(j=i+1;j<=b;j++)
		{
			if(m>=dp[j]+dp[i])
			{
				ans[i][j]=1;
				dp[i]+=dp[j];

				if(dp[i]==m)
				break;

			}
		}
	}

}


int main(){
iFILE(input.txt);
oFILE(output.txt);


	ll tc;cin>>tc;

	for(ll t=1;t<=tc;t++)
	{

		cin>>b>>m;
		init();
		b--;
		dp[b]=1;
		build();

		cout<<"Case #"<<t<<": ";

		if(dp[0]==m)
		{
			cout<<"POSSIBLE\n";

			for(ll i=0;i<=b;i++)
			{
				for(ll j=0;j<=b;j++)
				{
					cout<<ans[i][j];
				}
				cout<<"\n";
			}
		}

		else
		{

			cout<<"IMPOSSIBLE\n";

		}

	}

	return 0;
}
