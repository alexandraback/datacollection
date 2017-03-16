
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <list>

using namespace std;
typedef pair<int, int> P;
typedef long long ll;
typedef unsigned long long ull;
inline ll toInt(string s) { ll v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
template<class T> inline T sqr(T x) { return x*x; }


#define For(i,a,b)	for(int (i) = (a);i < (b);(i)++)
#define rep(i,n)	For(i,0,n)
#define clr(a)		memset((a), 0 ,sizeof(a))
#define mclr(a)		memset((a), -1 ,sizeof(a))
#define all(a)		(a).begin(),(a).end()
#define rall(a)		(a).rbegin(), (a).rend()
#define sz(a)		(sizeof(a))
#define Fill(a,v)	fill((int*)a,(int*)(a+(sz(a)/sz(*(a)))),v)

bool cheak(int x, int y, int xMax, int yMax){ return x >= 0 && y >= 0 && xMax > x && yMax > y; }
const int dx[3] = { -1, -1, 0 }, dy[3] = { -1, 0, -1};
const int mod = 1000000007;
const int INF = 1e9;

int d[1000010];

int main()
{
	int N;
	cin >> N;

	Fill(d, INF);
	d[1] = 1;
	for (int i = 1; i <= 1e6; i++){
		if (d[i] != INF){
			d[i + 1] = min(d[i + 1], d[i] + 1);
			string t = toString(i);
			if (t[0] != '0'){
				reverse(all(t));
				d[toInt(t)] = min(d[toInt(t)], d[i] + 1);
			}
		}
	}

	rep(Case, N){
		ll ans = 1;
		string n;
		cin >> n;
		ans = d[toInt(n)];
		cout << "Case #" << Case + 1 << ": " << ans << endl;
	}
	
	return 0;
}
