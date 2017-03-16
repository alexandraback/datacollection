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
		int ans,R,C,W;
		cin(R); cin(C); cin(W);
		if (C%W==0)
		{
			ans=R*(C/W)+W-1;
		}
		else
		{
			ans=R*(C/W)+W;
		}
		printf("Case #%d: %d\n",z,ans);
	}
}
