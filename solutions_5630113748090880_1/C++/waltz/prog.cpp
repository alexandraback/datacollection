#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

template <class T>
void read(T &x)
{
	char ch;
	for (ch=getchar();(ch<'0'||ch>'9')&&ch!='-';) ch=getchar();
	x=0;int t=1;if (ch=='-') {ch=getchar();t=-1;}
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	x*=t;
}

int a[2510];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int test;read(test);
	for (int T=1;T<=test;T++)
	{
		int n;read(n);
		memset(a,0,sizeof(a));
		for (int i=1;i<2*n;i++)
			for (int j=1;j<=n;j++)
			{
				int x;read(x);a[x]^=1;
			}
		printf("Case #%d:",T);
		for (int i=1;i<=2500;i++) if (a[i]) printf(" %d",i);
		puts("");
	}
	return 0;
}

