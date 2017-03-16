#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<stdlib.h>
#include<iterator>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<bitset>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>

using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define lop(i,n)        for(int i=0;i<n;i++)
#define loop(i,f,l)     for(int i=f;i<l;i++)
#define R_(s)         freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define INF                       1000000000
#define PI                 3.141592653589793
#define DFS_GRAY  -1
#define DFS_WHITE  0
#define DFS_BLACK  1

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<ss, int>     si;
typedef pair<int, ss>     is;
typedef pair<char, int>  chi;
typedef pair<ss, ss>     pss;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<ss>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll sq(ll x){ lop(i, x)if ((ll)i*i > x) return (i - 1); return 1; }
ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }


int T, D, v, mx , cnt = 0;
vi  plates(10);

int solve(int i,vi vec)
{
	if (i == 1)return 1;
	int m = INF;
	for (int k = 1;k<i; k++)
	{
		vec[k] += vec[i];
		vec[i - k] += vec[i];
		for (int j = i - 1; j > 0; j--)
		{
			if (vec[j] > 0)
			{
				m=min(m, solve(j, vec));
				break;
			}
		}
		vec[k] -= vec[i];
		vec[i - k] -= vec[i];
	}
	int ret = min(m+vec[i], i);
	for (int j = 0; j < i; j++)
	{
		vec[j]=vec[j+1];
	}
	for (int j = i-1; j > 0; j--)
	{
		if (vec[j] > 0)
		{
			ret = min(ret, 1+solve(j, vec));
			break;
		}
	}
	return ret;
}

int main()
{
	R_W;
	
	cin >> T;
	lop(i, T)
	{
		lop(i, 10)plates[i] = 0;
		mx = -1;
		cin >> D;
		lop(i, D)
		{
			cin >> v;
			++plates[v];
			mx = max(v, mx);
		}
		cout << "Case #" << ++cnt << ": " << solve(mx,plates) << endl;
	}
}