#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <algorithm>
using namespace std;
#define N 1000000007
typedef unsigned long long ULL;

int solve() {
	int n, m, k, t;
	t = n;
	n = min(n, m);
	m = max(t, m);
	cin >> n >> m >> k;
	if(n <= 2 || m <= 2) {
		return k;
	}
	if(k<=3) {
		return k;
	}
	if(k==n * m) {
		return (n + m - 2) * 2;
	}
	if(k<=5) {
		return 4;
	}
	if(k==6) {
		return 5;
	}
	if(k==7) {
		return 6;
	}
	if(k==8) {
		if(n>3||m>3) {
			return 6;
		}
		return 7;
	}
	if(k==9) {
		return 7;
	}
	if(k==10) {
		return 8;
	}
	if(k==11) {
		if(m>=4 || n >= 4) {
			return 8;
		}
		return 9;
	}
	if(k==12) {
		if(m>=4 && n>=4) {
			return 8;
		}
		if(m > 3 || n > 3){
			return 9;
		}
	}
	if(k==13) {
		if(n==3 || m==3) {
			return 10;
		}
		return 9;
	}
	if(k==14) {
		if(n==3 && m==5) {
			return 11;
		}
		if(n==3 || m == 3){
			return 10;
		}
		return 10;
	}
	return -1;
}

int main() {
    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        cout << "Case #" << i << ": ";
        cout << solve() << endl;
    }
    return 0;
}