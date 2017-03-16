// Template by Akigeor
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define ff first
#define ss second
#define pb push_back
#define PII pair<int,int>
#define rep(i,n) for (i=0;i<(n);i++)
#define fo(i,L,R) for (i=(L);i<=(R);i++)
#define cls(x) memset(x,0,sizeof(x))
#define cin(x) scanf("%d",&x)
#define mINF 0x3f
#define INF 0x3f3f3f3f
#define MOD7 1000000007
#define MOD9 1000000009
#define PI acos(-1.0)
using namespace std;
bool f[35];
int main()
{
	int t,z;
	cin(t);
	fo(z,1,t)
	{
		int C,D,V,i,j,k,l;
		cin(C); cin(D); cin(V);
		cls(f);
		f[0]=1;
		rep(l,D)
		{
			cin(k);
			for (i=V;i>=0;i--)
			{
				if (f[i])
				{
					f[i+k]=1;
				}
			}
		}
		int ans=0;
		fo(i,1,V)
		{
			if (!f[i])
			{
				ans++;
				k=i;
				for (i=V;i>=0;i--)
				{
					if (f[i])
					{
						f[i+k]=1;
					}
				}
			}
		}
		printf("Case #%d: %d\n",z,ans);
	}
}
