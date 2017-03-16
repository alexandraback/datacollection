#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <functional>
#include <math.h>
#include <utility>
#include <sstream>
#pragma comment(linker, "/STACK:133217728")

using namespace std;

string a[33], b[33];
string x[33], y[33];
int main() {  
	freopen("in.txt", "r", stdin);
	freopen("ans.txt", "w", stdout);
	
	int T;
	cin >> T;
	

	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		for(int i=0; i<n; i++)
			cin >> a[i] >> b[i];

		int ans = 0;
		for(int mask = 0; mask < (1 << n); mask++) {
			//map <string, bool> mp1;
			//map <string, bool> mp2;

			int cnt = 0;
			int p = 0;
			for(int i=0; i<n; i++)
				if(!(mask & (1 << i))) {
					x[p] = a[i];
					y[p++] = b[i];
				}
			int one = 0, two = 0;
			for(int i=0; i<n; i++) {
				if(mask & (1 << i)) {
					for(int j=0; j<p; j++) {
						if(x[j] == a[i]) one++;
						if(y[j] == b[i]) two++;
						if(one && two) break;
					}
					if(one && two) cnt++;
				}				
			}
			
			ans = max(ans, cnt);
		}
		cout << ans << endl;
		//cout << endl;
	}
	
	return 0;
}