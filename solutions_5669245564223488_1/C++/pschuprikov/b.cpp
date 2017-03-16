#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int const MOD = 1e9 + 7;
int const ALPHABET = 26;

int msum(int a, int b) {
    return (a + b) % MOD;
}

int mmul(long long a, long long b) {
    return (a * b) % MOD;
}



int main() {
    vector<int> fac(101);
    fac[0] = 1;
    for (int i = 1; i < fac.size(); i++) 
	fac[i] = mmul(fac[i - 1], i);
    int tests; cin >> tests;
    for (int test = 0; test < tests; test++) {
	cout << "Case #" << (test + 1) << ": ";
	int n; cin >> n;
	vector<int> next(ALPHABET, -1);
	vector<int> left(ALPHABET);
	vector<int> right(ALPHABET);
	vector<int> fill(ALPHABET);
	vector<int> mid(ALPHABET);
	bool bad = false;
	for (int i = 0; !bad && i < n; i++) {
	    string s; cin >> s;
	    string ls;
	    for (int j = 0; j < s.size(); j++) {
		if (!ls.empty() && s[j] != ls.back() && find(ls.begin(), ls.end(), s[j]) != ls.end()) {
		    bad = true; break;
		}
		if (ls.empty() || s[j] != ls.back()) {
		    ls.push_back(s[j]);
		} 
	    }
	    if (bad)
		break;
	    if (ls.size() == 1)
		fill[ls.front() - 'a']++;
	    else {
		left[ls.front() - 'a']++;
		right[ls.back() - 'a']++;
		next[ls.front() - 'a'] = ls.back() - 'a';
		for (int i = 1; i < ls.size() - 1; i++) {
		    mid[ls[i] - 'a']++;
		}
	    }
	}
	for (int i = 0; i < ALPHABET; i++) {
	    if (left[i] > 1 || right[i] > 1 || mid[i] > 1)
		bad = true;
	    if (mid[i] != 0 && (left[i] != 0 || right[i] != 0 || fill[i] != 0))
		bad = true;
	}
	if (bad) {
	    cout << "0\n";
	    continue;
	}
	int numcc = 0;
	int incc = 1;
	set<int> sym;
	for (int i = 0; i < ALPHABET; i++) {
	    if (left[i] != 0 || right[i] != 0 || fill[i] != 0)
		sym.insert(i);
	}
	bool finished = false;
	while (!finished) {
	    finished = true;
	    for (int i = 0; i < ALPHABET; i++) {
		if (sym.count(i) && right[i] == 0) {
		    for (int u = i; u != -1; u = next[u]) {
			sym.erase(u);
			incc = mmul(incc, fac[fill[u]]);
		    }
		    finished = false;
		    numcc++;
		    break;
		}
	    }
	}
	if (!sym.empty())
	    bad = true;
	if (bad) {
	    cout << "0\n";
	} else {
	    incc = mmul(incc, fac[numcc]);
	    cout << incc << "\n";
	}
    }
}
