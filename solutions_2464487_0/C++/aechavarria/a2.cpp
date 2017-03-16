using namespace std;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

int main(){
	int cases;
	cin >> cases;
	for (int run = 1; run <= cases; ++run){
		long long r, t;
		cin >> r >> t;
		long long ans = 0;
		while (t >= 2 * r + 1){
			//D(t); D(r);
			t -= 2 * r + 1;
			r += 2;
			ans++;
			//D(t);
		}
		
		printf("Case #%d: ", run);
		cout << ans << endl;
		//if (run >= 3) break;
	}
	
    return 0;
}
