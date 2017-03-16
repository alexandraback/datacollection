#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <bitset>
#include <list>

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define bitcnt(x) __builtin_popcountll(x)
#define rt return

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

const int INF = (int)1e9 + 37;
const ld PI = acos(-1.0);
const int MAXN = 5115;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const char dir[4] = {'L', 'U', 'R', 'D'};


map <pair <int, int>, int> jp, js, ps;

bool check (int k){
	for (auto it : jp){
		if (it.Y > k){
			return 0;
		}
	}
	
	for (auto it : js){
		if (it.Y > k){
			return 0;
		}
	}
	
	for (auto it : ps){
		if (it.Y > k){
			return 0;
		}
	}
	
	return 1;
}

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;
	for (int Test = 1; Test <= T; Test++){
		
		int j, p, s, k;
		cin >> j >> p >> s >> k;
		vector <pair <int, pair <int, int> > > a;
		for (int ii=1;ii<=j;ii++){
			for (int jj=1;jj<=p;jj++){
				for (int kk=1;kk<=s;kk++){
					a.pb(mp(ii, mp(jj, kk)));
				}	
			}
		}
		int sz = (int)a.size();
		int ans = 0;
		sort(a.begin(), a.end());
		vector <pair <int, pair <int, int> > > best;
		for (int it=0;it<200000;it++){
			jp.clear();
			js.clear();
			ps.clear();
			random_shuffle(a.begin(), a.end());
			int num = 0;
			while (num < sz){
				jp[mp(a[num].X, a[num].Y.X)]++;
				js[mp(a[num].X, a[num].Y.Y)]++;
				ps[mp(a[num].Y.X, a[num].Y.Y)]++;
				if (!check(k)){
					break;
				}
				num++;
			}
			if (num > ans){
				best = a;
				ans = num;
			}
		}	
					
		printf("Case #%d: %d\n", Test, ans);
		for (int i=0;i<ans;i++){
			cout << best[i].X << ' ' << best[i].Y.X << ' ' << best[i].Y.Y << endl;
		}
	}
	
	
    rt 0;
}
