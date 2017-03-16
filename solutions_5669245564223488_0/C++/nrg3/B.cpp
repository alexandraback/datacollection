#pragma comment(linker, "/STACK:256000000")

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;

bool ok(const string& s) {
	bool had[256] = {0,};
	char prev = '#';
	for (int i = 0; i < s.size(); ++i) {
		if (had[s[i]] && prev != s[i]) {
			return 0;
		}
		prev = s[i];
		had[s[i]] = 1;
	}
	return 1;
}

int main() {
	int _start = clock();
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	/*
#ifndef ONLINE_JUDGE
    
    freopen("output.txt","w",stdout);
#else
#define taskname "cutting"
	//freopen(taskname".in","r",stdin);
    //freopen(taskname".out","w",stdout);
#endif
*/

	int T; cin >> T;
	for (int test = 1; test <= T; ++test) {
		printf("Case #%d: ", test);
		fprintf(stderr, "Case #%d: \n", test);
		long long ans = 0;
		int n; cin >> n;
		vector<string> s(n);
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			cin >> s[i];

			if (!ok(s[i])) {
				goto globend;
			}

			while (s[i].size() > 1 && s[i][s[i].size() - 1] == s[i][s[i].size() - 2]) {
				s[i].pop_back();
			}

			reverse(s[i].begin(), s[i].end());
			while (s[i].size() > 1 && s[i][s[i].size() - 1] == s[i][s[i].size() - 2]) {
				s[i].pop_back();
			}
			reverse(s[i].begin(), s[i].end());



			if (s[i].size() > 2) {

				string begc; begc += s[i][0];
				string endc; endc += s[i].back();

				

				string::iterator start = s[i].begin();
				++start;
				string::iterator end = s[i].end();
				--end;

				string mid = s[i].substr(1, s[i].size() - 1 - 1);

				sort(mid.begin(), mid.end());
				mid.resize(unique(mid.begin(), mid.end()) - mid.begin());

				s[i] = begc + mid + endc;
			}
		}

		
		for (int i = 0; i < p.size(); ++i) {
			p[i] = i;
		}


		do {

			bool bad = 0;
			

			bool had[256] = {0,};
			char prev = '#';
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < s[p[i]].size(); ++j) {
					char cur = s[p[i]][j];
					if (had[cur] && prev != cur) {
						bad = 1;
						goto end;
					}
					had[cur] = 1;
					prev = cur;
				}
			}

			end:;

			if (!bad) {
				++ans;
			}

		} while (next_permutation(p.begin(), p.end()));

		globend:;
		cout << ans << endl;
	}


	
	cerr << endl << endl << "Time: " << (double)(clock() - _start) / CLOCKS_PER_SEC << endl;
	return 0;
}