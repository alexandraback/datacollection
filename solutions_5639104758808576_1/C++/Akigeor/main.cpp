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
int main()
{
	int T,z;
	cin(T);
	fo(z,1,T)
	{
		int n,i,j,k;
		cin(n);
		char s[1005];
		scanf("%s",s);
		j=s[0]-'0';
		k=0;
		fo(i,1,n)
		{
			if (j<i)
			{
				k+=i-j;
				j=i;
			}
			j+=s[i]-'0';
		}
		printf("Case #%d: %d\n",z,k);
	}
}
