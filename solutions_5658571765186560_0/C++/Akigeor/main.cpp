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
	int T,z,s[7];
	cin(T);
	fo(z,1,T)
	{
		int X,R,C;
		cin>>X>>R>>C;
		if (R>C) swap(R,C);
		if (R*C%X!=0 || max(R,C)<X || X>=7)
		{
			printf("Case #%d: RICHARD\n",z);
		}
		else if (X==1 || X==2)
		{
			printf("Case #%d: GABRIEL\n",z);
		}
		else if (X==3)
		{
			if (R==1)
			{
				printf("Case #%d: RICHARD\n",z);
			}
			else
			{
				printf("Case #%d: GABRIEL\n",z);
			}
		}
		else if (X==4)
		{
			if (R==1 || (R==2 && C<=4))
			{
				printf("Case #%d: RICHARD\n",z);
			}
			else
			{
				printf("Case #%d: GABRIEL\n",z);
			}
		}
		else if (X==5)
		{
			if (R<=2)
			{
				printf("Case #%d: RICHARD\n",z);
			}
			else
			{
				printf("Case #%d: GABRIEL\n",z);
			}
		}
		else if (X==6)
		{
			if (R<=3)
			{
				printf("Case #%d: RICHARD\n",z);
			}
			else
			{
				printf("Case #%d: GABRIEL\n",z);
			}
		}
		else
		{
			printf("Case #%d: RICHARD\n",z);
		}
	}
}
