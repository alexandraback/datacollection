#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
 
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ size()
#define read(filename) freopen(filename, "r", stdin)
#define write(filename) freopen(filename, "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 1<<29
#define mod(a) (a>0?a:-a)
#define pf printf
 
using namespace std;

unsigned long long twolist[] = {1, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656};

unsigned long long limit(int x) {
	unsigned long long r = 1;
	loop(i, x) {
		r *= 2;
	}
	return r;
}

int main()
{
    int T;
    getint(T); 

    int B;
    unsigned long long M;
    loop(k, T) {
    	getint(B);
    	cin >> M;

    	vector<string> r;
    	loop(x, B) {
    		string tmp = "";
    		loop(y, B) {
    			if (y > x) {
    				if (y == B-1) {
    					tmp += "0";
    				} else {
    					tmp += "1";
    				}
    			} else {
    				tmp += "0";
    			}
    		}
    		r.push_back(tmp);
    	}

    	if (M > limit(B - 2)) {
    		cout << "Case #" << k+1 << ": IMPOSSIBLE" << endl;
    		continue;
    	}

    	int i = 0;
    	while (M != 0) {
    		for (i = 49; i >= 0; i--) {
				if (M >= twolist[i]) {
					if (i == B-1) {
						continue;
					}
					if (r[i][B-1] != '1') {
						M -= twolist[i];
						r[i][B-1] = '1';
					}
				}
			}
    	}

    	cout << "Case #" << k+1 << ": POSSIBLE" << endl;
    	loop(i, B) {
    		cout << r[i] << endl;
    	}
    }
    return 0;
}