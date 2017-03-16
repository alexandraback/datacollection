#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <vector>
#include <iterator>
#include <set>
#include <bitset>
#include <ctime>
#include <iomanip>
#include <map>

using namespace std;

const int K = 20;
int a[K + 2];

void precompute() {
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;
	a[5] = 4;
	a[6] = 6;
	a[7] = 6;
	a[8] = 6;
	a[9] = 8;
	a[10] = 8;
	a[11] = 8;
	a[12] = a[13] = a[14] = a[15] = a[16] = 10;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	precompute();
	for(int test = 1; test <= t; test++) {
		int n, m, k;
		cin>>n>>m>>k;
		int ans = 0;
		int nm = n*m;
		if(k > nm - 4) 		ans = k;
		else {
			if(m < 3) 		ans = k;
			else if(m >= 3) {
				ans = a[k];
			}
		}
		cout<<"Case #"<<test<<": "<<ans<<"\n";
	}
	return 0;
}