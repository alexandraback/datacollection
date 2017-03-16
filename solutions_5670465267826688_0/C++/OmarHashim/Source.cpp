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

int arr[10010][10010];

//i =2 j=3 k=4     -i=-2    -j=-3   -k=-4
int W[4][4] = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };
int main()
{
	R_W;
	int T, L, X,n,cnt=0;
	ss data,temp;
	cin >> T;
	lop(k, T)
	{
		cin >> L >> X;
		cin >> temp;
		data = "";
		lop(i, X)data += temp;
		n = L*X;
		memset(arr, 0, sizeof arr);
		for (int i = 0; i < n; i++)
		{
			if (data[i] == 'i')arr[i][1] = 2;
			if (data[i] == 'j')arr[i][1] = 3;
			if (data[i] == 'k')arr[i][1] = 4;
		}
		for (int s = 2; s <= n; s++)//size of substring
		{
			for (int i = 0; i + s - 1 < n; ++i)//start of substring
			{
				if (arr[i][s - 1] < 0)
				{
					switch (data[i+s-1])
					{
					case 'i': arr[i][s] = -1*W[-1*arr[i][s - 1]-1][1];
						break;
					case 'j': arr[i][s] = -1*W[-1*arr[i][s - 1]-1][2];
						break;
					case 'k': arr[i][s] = -1*W[-1*arr[i][s - 1]-1][3];
						break;
					}
				}
				else
				{
					switch (data[i+s-1])
					{
					case 'i': arr[i][s] = W[arr[i][s - 1]-1][1];
						break;
					case 'j': arr[i][s] = W[arr[i][s - 1]-1][2];
						break;
					case 'k': arr[i][s] = W[arr[i][s - 1]-1][3];
						break;
					}
				}
			}
		}
		for (int i = 1; i < n; i++)//last element i-1
		{
			if (arr[0][i] == 2)
			{
				for (int j = 1; i + j < n; j++)//last element i+j-1
				{
					if (arr[i][j] == 3 && arr[i + j][n - i - j] == 4)
					{
						printf("Case #%d: YES\n", ++cnt);
						goto next;
					}
				}
			}
		}
		printf("Case #%d: NO\n", ++cnt);
	next:;
	}
}