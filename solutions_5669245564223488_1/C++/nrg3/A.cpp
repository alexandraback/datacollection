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

void make_neat(string &s) {
	while (s.size() > 1 && s[s.size() - 1] == s[s.size() - 2]) {
		s.pop_back();
	}

	reverse(s.begin(), s.end());
	while (s.size() > 1 && s[s.size() - 1] == s[s.size() - 2]) {
		s.pop_back();
	}
	reverse(s.begin(), s.end());

	if (s.size() > 2) {
		string begc; begc += s[0];
		string endc; endc += s.back();
			
		string mid = s.substr(1, s.size() - 1 - 1);

		sort(mid.begin(), mid.end());
		mid.resize(unique(mid.begin(), mid.end()) - mid.begin());

		s = begc + mid + endc;
	}
}

long long fact[1000];

long long solve(vector<string>& s) {
	int n = s.size();

	bool has[105][300] = {0,};

	for (int i = 0; i < s.size(); ++i) {
		if (!ok(s[i])) {
			return 0;
		}

		make_neat(s[i]);

		for (int z = 0; z < s[i].size(); ++z) {
			has[i][s[i][z]] = 1; 
		}
	}

	long long ans = 1;

	vector<int> component(n, -1);
	
	for (char current = 'a'; current <= 'z'; ++current) {
		int end_q = 0, end_id = -1, start_q = 0, start_id = -1, one_char = 0;
		int in_mid = 0;

		for (int i = 0; i < n; ++i) {

			if (has[i][current] && component[i] == -1) {
				if (s[i].size() == 1) {
					++one_char;
					continue;
				}

				if (s[i][0] == current) {
					++start_q;
					start_id = i;
					continue;
				}

				if (s[i].back() == current) {
					++end_q;
					end_id = i;
					continue;
				}

				++in_mid;		
			}
		}

		if (in_mid != 0 && (end_q != 0 || start_q != 0 || one_char != 0)) {
			return 0;
		}

		if (end_q >= 2 || start_q >= 2) {
			return 0;
		}

		ans = (ans * fact[one_char]) % MOD;

		if (end_id != -1) {
			if (start_id != -1) {
				component[start_id] = end_id;

				s[end_id] += s[start_id];
				if (!ok(s[end_id])) {
					return 0;
				}

				make_neat(s[end_id]);

				for (int z = 0; z < s[end_id].size(); ++z) {
					has[end_id][s[end_id][z]] = 1;
				}
			}
			for (int i = 0; i < n; ++i) {
				if (has[i][current] && s[i].size() == 1) {
					component[i] = end_id;			
				}
			}
			continue;
		}

		if (start_id != -1) {
			for (int i = 0; i < n; ++i) {
				if (has[i][current] && s[i].size() == 1) {
					component[i] = start_id;			
				}
			}
			continue;
		}

		int first = -1;
		for (int i = 0; i < n; ++i) {
			if (has[i][current] && s[i].size() == 1) {
				if (first == -1) {
					first = i;
				} else {
					component[i] = first;			
				}					
			}
		}
	}

	int r = 0;
	for (int i = 0; i < n; ++i) {
		r += component[i] == -1;
	}

	ans = (ans * fact[r]) % MOD;
	
	return ans;
}

void solver() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T; cin >> T;
	for (int test = 1; test <= T; ++test) {
		printf("Case #%d: ", test);
		fprintf(stderr, "Test %d\n", test);

		int n; cin >> n;
		vector<string> s(n);
		for (int i = 0; i < s.size(); ++i) {
			cin >> s[i];
		}

		cout << solve(s) << endl;
	}
}

long long brute(vector<string> s) {
	int n = s.size();
	vector<int> p(n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		
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
	return ans;
}

void tester() {
	freopen("good_input.txt","r",stdin);	

	FILE *f = fopen("good_output.txt", "r");

	int T; cin >> T;
	for (int test = 1; test <= T; ++test) {
		//printf("Case #%d: ", test);
		fprintf(stderr, "Test %d\n", test);

		int n; cin >> n;
		vector<string> s(n);
		for (int i = 0; i < s.size(); ++i) {
			cin >> s[i];
		}

		long long my = brute(s);
		cerr << solve(s) << endl;

		long long ans;
		char tp[1000];
		fscanf(f, "%s %s %lld\n", tp, tp, &ans);

		if (my != ans) {
			cout << "ERR";
			exit(0);
		}		
	}	
}


void random_tester() {
	srand(321);
	for (int test = 0; ; ++test) {
		int n = 8;
		vector<string> s(n);
		for (int i = 0; i < n; ++i) {
			s.resize(rand() % 4 + 1);
			for (int z = 0; z < s.size(); ++z) {
				s[i][z] = rand() % 4 + 'a';
			}
		}

		long long ans = brute(s);
		long long my = solve(s);

		if (ans != my) {
			cout << test << endl;
			cout << "ERR";
			exit(0);
		}

		if (test % 100000 == 0) {
			cerr << test << endl;
		}
	}
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

	fact[0] = 1;
	for (int i = 1; i < 1000; ++i) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
	//tester();
	//random_tester();
	solver();


	
	cerr << endl << endl << "Time: " << (double)(clock() - _start) / CLOCKS_PER_SEC << endl;
	return 0;
}