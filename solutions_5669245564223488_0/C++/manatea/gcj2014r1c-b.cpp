#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

ll MOD = 1000000007;
bool chk[200];
ll kj[200];

void solve()
{
	kj[1] = 1;
	for (int i = 2; i < 100; ++i) {
		kj[i] = kj[i - 1] * i % MOD;
	}

	char tmp[256];
	int N;
	scanf("%d", &N);
	vector<string> carslist;
	for (int i = 0; i < N; ++i) {
		scanf("%s", tmp);
		carslist.push_back(tmp);
	}

	// check
	int last_idx[26];
	vector<set<int> > start, end, mid;
	set<int> eset;
	for (int i = 0; i < 26; ++i) {
		start.push_back(eset);
		end.push_back(eset);
		mid.push_back(eset);
	}
	for (int i = 0; i < N; ++i) {
		string cars = carslist[i];
		memset(last_idx, -1, sizeof(last_idx));
		int len = cars.length();
		for (int j = 0; j < len; ++j) {
			char ch = cars[j];
			int id = ch - 'a';
			int lid = last_idx[id];
			if (j == 0) {
				start[id].insert(i);
			}
			if (j == len - 1) {
				end[id].insert(i);
			}
			if (j != 0 && j != len - 1 && lid == -1) {
				mid[id].insert(i);
			}
			if (lid == -1) {
				last_idx[id] = j;
			} else if (lid != j - 1) {
				printf("0");
				return;
			} else {
				last_idx[id] = j;
			}
		}
	}

	// check2
	for (int i = 0; i < 26; ++i) {
		//cout << mid[i] << endl;
		if (mid[i].size() > 0) {
			if (start[i].size() > 0 || end[i].size() > 0 || mid[i].size() > 1) {
				printf("0");
				return;
			}
		}
		if (start[i].size() > 1 || end[i].size() > 1) {
			if (abs((int)start[i].size() - (int)end[i].size()) > 1) {
				printf("0");
				return;
			}
		}
	}

	vector<pcc> selist;
	map<pcc, int> secnt;
	for (int i = 0; i < N; ++i) {
		string cars = carslist[i];
		int len = cars.length();
		selist.push_back(make_pair<char>(cars[0], cars[len - 1]));
	}
	memset(chk, 0, sizeof(chk));
	for (int i = 0; i < N; ++i) {
		pcc se = selist[i];
		if (se.first == se.second) {
			int cntsame = 1;
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;
				if (se == selist[j]) {
					cntsame++;
					chk[j] = true;
				}
			}
			if (cntsame > 1) {
				secnt[se] = cntsame;
				chk[i] = true;
			}
		}
	}
	bool cont = true;
	while (cont) {
		cont = false;
		for (int i = 0; i < selist.size(); ++i) {
			if (chk[i]) continue;
			for (int j = i + 1; j < selist.size(); ++j) {
				if (chk[j]) continue;
				pcc se = selist[i];
				pcc se2 = selist[j];
				if (se.first == se2.second) {
					selist[i] = make_pair<char>(se2.first, se.second);
					chk[j] = true;
					cont = true;
				} else if (se.second == se2.first) {
					selist[i] = make_pair<char>(se.first, se2.second);
					chk[j] = true;
					cont = true;
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		if (chk[i] == false) secnt[selist[i]] = 1;
	}

	ll ans = 1;
	map<pcc, int>::iterator mi = secnt.begin();
	int gcnt = 0;
	while (mi != secnt.end()) {
		ans = ans * kj[mi->second] % MOD;
		++gcnt;
		++mi;
	}
	ans = ans * kj[gcnt] % MOD;
	//cout << gcnt << endl;
	printf("%lld", ans);

    return;
}

int main()
{
    int nCases = 0;
    scanf("%d", &nCases);
    for (int i = 1; i <= nCases; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
