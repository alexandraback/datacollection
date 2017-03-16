#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <string.h>

using namespace std;

#define pb push_back
#define sz(v) ((int)v.size())
#define mp make_pair

vector <int> v1, v2;
vector <int> val;
int N;

void print_res() {
	for (int i = 0; i < sz(v1); ++i)
		cout << v1[i] << " ";
	cout << "\n";
	for (int i = 0; i < sz(v2); ++i)
		cout << v2[i] << " ";
	cout << "\n";
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		printf("Case #%d:\n",t + 1);
		cin >> N;
		val.clear();
		val.resize(N);
		long long max_m = 1;
		for (int i = 0; i < N; ++i) {
			cin >> val[i];
			max_m *= 3;
		}
		for (long long tm = 1; tm < max_m; ++tm) {
			long long m = tm;
			v1.clear();
			v2.clear();
			int sum1 = 0, sum2 = 0;
			for (int i = 0; i < N; ++i) {
				if (m % 3 == 1) {
					v1.pb(val[i]);
					sum1 += val[i];
				}
				else if (m % 3 == 2) {
					v2.pb(val[i]);
					sum2 += val[i];
				}
				m /= 3;
			}
			if ((sum1 == sum2) && sz(v1) && sz(v2)) {
				max_m = -1;
				print_res();
				break;
			}
		}
		if (max_m > 0)
			cout << "Impossible\n";
	}

		


	return 0;
}