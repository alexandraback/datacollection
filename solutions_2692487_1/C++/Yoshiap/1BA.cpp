#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("1BA.out");
ifstream fin ("1BA.in");

int main() {
int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		ll A,N;
		ll value[105];
		fin >> A >> N;
		for (int i = 0; i < N; i++) {
			fin >> value[i];
		}
		sort(value,value+N);
		ll ans = 9999;
		int ind = 0;
		int cnt = 0;
		if (A == 1) {
			ans = N;
		}
		else {
			while (ind < N) {
				if (A > value[ind]) {
					A += value[ind];
					ind++;
				}
				else {
					ans = min(ans,cnt+N-ind);
					cnt++;
					A += A-1;
				}
			}
			ans = min(ans,(ll)cnt);
		}
		fout << "Case #" << t << ": " << ans << endl;
	}
    return 0;
}