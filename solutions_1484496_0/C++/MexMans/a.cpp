#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
int a[20],s[20],x[20],y[20],n,xc,yc,X,Y;
bool ok;
void dfs(int v)
{
	if (X == Y && xc != 0 && yc != 0)
	{
		ok = true;
		return;
	}
	if (v == n) return;
	if (X > Y && X > Y + s[v]) return;
	if (Y > X && Y > X + s[v]) return;
	dfs(v + 1);
	if (ok) return;
	X += a[v];
	x[xc++] = a[v];
	dfs(v + 1);
	if (ok) return;
	X -= a[v];
	xc--;
	Y += a[v];
	y[yc++] = a[v];
	dfs(v + 1);
	if (ok) return;
	Y -= a[v];
	yc--;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	for(int t = 1; t <= T; t++)
	{
		cin>>n;
		for(int i = 0; i < n; i++)
			cin>>a[i];
		s[n - 1] = a[n - 1];
		for(int i = n - 2; i >= 0; i--)
			s[i] = a[i] + s[i + 1];
		xc = 0;
		yc = 0;
		X = 0;
		Y = 0;
		ok = false;
		dfs(0);
		printf("Case #%d:\n",t);
		if (ok)
		{
			for(int i = 0; i < xc; i++)
			{
				if (i > 0) cout<<" ";
				cout<<x[i];
			}	
			cout<<endl;
			for(int i = 0; i < yc; i++)
			{
				if (i > 0) cout<<" ";
				cout<<y[i];
			}	
			cout<<endl;		
		} else printf("Impossible\n");
	}
	return 0;
}
