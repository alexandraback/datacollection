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
		int arr[51][51];
		FOR(i,0,51) {
			FOR(j,0,51) {
				arr[i][j] = 0;
			}
		}
		FOR(i,0,n) {
			int m;
			cin>>m;
			FOR(j,0,m) {
				int c;
				cin>>c;
				arr[c-1][i] = 1;
			}
		}
		FOR(k,0,n) {
			FOR(i,0,n) {
				FOR(j,0,n) {
					if(arr[i][k] != 0 && arr[k][j] != 0) {
						arr[i][j]++;
					}
				}
			}
		}
		bool ans = false;
		FOR(i,0,n) {
			FOR(j,0,n) {
				if(arr[i][j] > 1) {
					ans = true;
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