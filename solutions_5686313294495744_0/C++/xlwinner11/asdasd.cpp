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
const int MAXN = (int)5e4 + 222;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const char dir[4] = {'L', 'U', 'R', 'D'};


int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;
	for (int Test=1;Test<=T;Test++){
		
		int n;
		cin >> n;
		vector <pair <string, string> > a(n);
		for (int i=0;i<n;i++){
			cin >> a[i].X >> a[i].Y;
		}	
		int ans = 0;
		for (int i=0;i<(1 << n);i++){
			int cnt = 0;
			bool ok = 1;
			vector <int> mask;
			for (int j=0;j<n;j++){
				mask.pb(1 & (i >> j));
				cnt += mask[j];
			}
			for (int j=0;j<n;j++){
				if (mask[j] == 1){
					bool found1 = 0, found2 = 0;
					for (int ii=0;ii<n;ii++){
						if (mask[ii] == 1){
							continue;
						} else {
							if (a[ii].X == a[j].X){
								found1 = 1;
							}
							if (a[ii].Y == a[j].Y){
								found2 = 1;
							}
						}
					}
					if (!(found1 && found2)){
						ok = 0;
					}
				}
			}
			if (ok){
				ans = max(ans, cnt);
			}			
		}
		
		printf("Case #%d: ", Test);
		cout << ans << endl;		
	}
				
    rt 0;
}
