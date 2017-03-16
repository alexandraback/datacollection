#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#define sz(a) ((int)(a).size())
#define foreach(i, Type, v) for(Type::iterator i=v.begin(); i!=v.end(); i++)
using namespace std;
typedef long long llong;
typedef pair<int, int> Item;

const int Maxn = 1000+10;
const int INF = 0x7f7f7f7f;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int compareTo(double a, double b) { return (a>b+eps) ? 1 : ((a+eps<b)?-1:0); }

int a[20], f[20][10];

int main()
{
	int cas, E, R, N;
	ios::sync_with_stdio(0);
	freopen("aaa.in", "r", stdin);
	freopen("aaa.out", "w", stdout);

	cin>>cas;
	for(int c=1; c<=cas; c++)
	{
		cin>>E>>R>>N;
		for(int i=0; i<N; i++)
			cin>>a[i];

		memset(f, 0, sizeof(f));
		for(int i=0; i<=E; i++)
			f[0][min(E, E-i+R)] = max(f[0][min(E, E-i+R)], i*a[0]);
		for(int i=0; i<N-1; i++)
			for(int j=0; j<=E; j++)
				for(int k=0; k<=j; k++)
				{
					int t = min(E, j-k+R);
					f[i+1][t] = max(f[i+1][t], f[i][j]+k*a[i+1]);
				}
		int ans = 0;
		for(int j=0; j<=E; j++)
			ans = max(ans, f[N-1][j]);
		printf("Case #%d: %d\n", c, ans);
	}

	return 0;
}
