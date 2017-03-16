#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <utility>
#include <set>
#include <functional>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
using namespace std;

#define FOR(_i,_n) for(int (_i)=0;(_i)<(_n);(_i)++)
#define iss istringstream
#define oss ostringstream
#define mp make_pair
#define pb push_back
#define px first
#define py second
#define pi 3.141592653589793
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> Pair;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	cin >> T;
	for(int tt=1;tt<=T;tt++) {
		int64 N, score, a[111], cnt = 0;
		cin >> score >> N;
		for(int i=0;i<N;i++) {
			cin >> a[i];
		}
		
		sort(a, a+N);
		
		if(score == 1) {
			cout << "Case #" << tt << ": " << N << endl;
			continue;
		}
		
		int res = 1111111;
		for(int i=0;i<=N;i++) {
			int cnt1 = 0;
			int cnt2 = N - i;
			int64 cur = score;
			for(int j=0;j<i;j++){
				if(a[j] < cur) {
					cur += a[j];
				} else {
					while (cur <= a[j]) {
						cur += cur - 1;
						cnt1 ++;
					}
					cur += a[j];
				}
			}
			res = min(cnt1 + cnt2, res);
		}
		
		cout << "Case #" << tt << ": " << res << endl;
	}

	return 0;
}
