#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MP make_pair
#define PB push_back
#define XX first
#define YY second
#define ALL(x) x.begin(), x.end()
typedef pair<int, int> PII;
int main() 
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T, i, j;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		int a[1010], b[1010];
		vector<PII> v1, v2;
		for(i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
			v1.push_back(MP(a[i], i));
			v2.push_back(MP(b[i], i));
		}
		int star = 0, ans = 0;
		sort(ALL(v1));
		sort(ALL(v2));
		while(star < 2 * n) {
			ans++;
			if(v2.size() > 0 && v2[0].first <= star) {
				int ind = v2[0].YY;
				star++;
				v2.erase(v2.begin());
				for(j = 0; j < v1.size(); j++) if(v1[j].YY==ind) break;
				if(j < v1.size()) {
					v1.erase(v1.begin()+j);
					star++;
				}
			} else {
				int ind = -1, sec = -1;
				for(j = 0; j < v1.size(); j++) {
					if(v1[j].XX <= star && b[v1[j].YY] > sec) {
						sec = b[v1[j].YY];
						ind = j;
					}
				}
				if(ind == -1) break;
				star++;
				v1.erase(v1.begin()+ind);
			}
		}
		if(star < 2 * n) {
			printf("Case #%d: Too Bad\n", t);
			continue;
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
