#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define pb push_back
#define FOREACH(x,y) for(typeof(y.begin()) x = y.begin() ; x != y.end() ; x++)
#define DEB(v) cout << "#v = " << endl;

long long MOD = (long long)1000000007;

int main() {
	int T;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for(int tc = 1 ; tc <= T ; tc++) {
		int n;
		cin >> n;
		bool arr[1001][1001];
		FOR(i,0,1001) {
			FOR(j,0,1001) {
				arr[i][j] = false;
			}
		}
		FOR(i,0,n) {
			int m;
			cin>>m;
			FOR(j,0,m) {
				int c;
				cin>>c;
				arr[c-1][i] = true;
			}
		}
		bool ans = false;
		FOR(k,0,n) {
			FOR(i,0,n) {
				FOR(j,0,n) {
					if(arr[i][k] == true && arr[k][j] == true) {
						if(arr[i][j] == true) {
							ans = true;
						} else {
							arr[i][j] = true;
						}
					}
				}
			}
		}
		if(ans == false)
			cout << "Case #" << tc << ": " << "No" << endl;
		else
			cout << "Case #" << tc << ": " << "Yes" << endl;
	}
	return (0);
}