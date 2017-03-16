#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);

bool check(int init, int n, string str) {
	for (int i = 0; i <= n; i++) {
		if (str[i] != '0') {
			if (init < i) {
				return false;
			} else {
				init += (str[i] - '0');
			}
		}		
	}

	return true;
}

int n;
string str;
int tc;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> n >> str;

    	int lb = 0, rb = n;
    	while (lb < rb) {
    		int mid = (lb + rb) / 2;

    		if (check(mid, n, str))
    			rb = mid;
    		else
    			lb = mid + 1;
    	}

    	cout << "Case #" << tnum + 1 << ": " << lb << endl;
    }

    return 0;
}