#include <cassert>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

struct chest {
	int k;
	vector<int> c;
};

int main()
{
#define SAMPLE_NAME "D"
	if( freopen(SAMPLE_NAME "-large.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-large.out", "wt", stdout);
	} else 	if( freopen(SAMPLE_NAME "-small-attempt2.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		cerr << case_num << endl;
		int K, N, cop = 0;
		cin >> K >> N;
		map<int,int> keys;
		map<int,int> key_copy[21];
		int order_copy[20];
		fill(&order_copy[0], &order_copy[N], -1);
		vector<chest> cs;
		int order[20] = {0};
		cs.resize(N);

		for(int i = 0; i < K; ++i) { int k; cin >> k; keys[k]++; }
		for(int i = 0; i < N; ++i) {
			order[i] = i;
			int nn;
			cin >> cs[i].k >> nn;
			cs[i].c.resize(nn);
			for(int j = 0; j < nn; ++j) cin >> cs[i].c[j];
			//k2c[cs[i].k].push_back(i);
		}
		bool solved = false;

		key_copy[0] = keys;
		int max_try = 5 * 1000 * 1000;
		do {
			int i = 0;
			i = mismatch(&order[0], &order[N], &order_copy[0]).first - &order[0];

			solved = true;
			map<int, int> ks(key_copy[i]);
			for(;i < N; ++i) {
				int d = order[i];
				if(ks[ cs[d].k ]) {
					--ks[ cs[d].k ];
					for(vector<int>::iterator it = cs[d].c.begin(); it != cs[d].c.end(); ++it) ks[*it]++;
					order_copy[i] = order[i];
					key_copy[i+1] = ks;
				} else {
					reverse(&order[i+1], &order[N]);
					solved = false;
					break;
				}
			}
			if(solved || (0 == max_try--) ) break;
		} while(next_permutation(&order[0], &order[N]) );
		if(!solved) cout << "Case #" << case_num << ": IMPOSSIBLE" << endl;
		else {
			cout << "Case #" << case_num << ':';
			for(int i = 0; i < N; ++i) cout << ' ' << (1 + order[i]);
			cout << endl;
		}
	}
 	return 0;
}
