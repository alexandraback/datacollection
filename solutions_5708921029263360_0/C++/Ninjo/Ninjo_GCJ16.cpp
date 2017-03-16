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
/*
1 2 3

1 1 1
1 1 2
1 1 3
1 2 1
1 2 2
1 2 3
*/


int xy[9],xz[9],yz[9],arr[27][3],top=-1,k,all;

void dfs(int x,int y,int z)
{
	int i,j,l;
	i=(x-1)*3+(y-1);
	j=(x-1)*3+(z-1);
	l=(y-1)*3+(z-1);
	xy[i]++;
	xz[j]++;
	yz[l]++;

	if(xy[i]<=k && xz[j]<=k && yz[l]<=k)
	{
		//cout<<xy[i]<<" "<<xz[j]<<" "<<yz[l]<<" "<<k<<endl;
		top++;
		arr[top][0]=x;
		arr[top][1]=y;
		arr[top][2]=z;
		++all;
	}
	else
	{
		xy[i]--;
	xz[j]--;
	yz[l]--;
	}

}

int main(){
iFILE(input.txt);
oFILE(output.txt);

	int t,m,n,o,j,p,s,itr=1,a;
	cin>>t;
	while(t-- >0)
	{
		all=0;
		top=-1;
		cin>>j>>p>>s>>k;
		for(a=0;a<9;a++)
		{
			xy[a]=0;
			yz[a]=0;
			xz[a]=0;
		}
		for(m=1;m<=j;m++)
		{
			for(n=1;n<=p;n++)
			{
				for(o=1;o<=s;o++)
				{
					dfs(m,n,o);
				}
			}
		}
		cout<<"Case #"<<itr<<": "<<all<<endl;
		for(a=0;a<=top;a++)
			cout<<arr[a][0]<<" "<<arr[a][1]<<" "<<arr[a][2]<<endl;

		itr++;
	}
}
