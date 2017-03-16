#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <limits>
#include <numeric>
#include <map>
#define FOREACH(it, C) for(typeof((C).begin()) it = (C).begin(); it != (C).end(); ++it)
using namespace std;
typedef long long int ll;
typedef long double ld;
const ld EPS = 1E-9L;

ostream& operator<<(ostream& os, const vector<ld>& v) {
    if(v.size() > 0) {
        for(size_t i = 0; i < v.size() - 1; ++i) {
            os << v[i] << " ";
        }
        os << v[v.size() - 1];
    }
    return os;
}


vector<ld> solve(int n, vector<ld>& scores) {
    vector<ld> result(n);
    ld sum = accumulate(scores.begin(), scores.end(), 0.0L);
    for(int i = 0; i < n; ++i) {
        ld l = 0;
        ld r = 1.0L;
        while(l < r - EPS) {
            ld m = (l + r) / 2.0L;
            //cout << l << " " << m << " " << r << endl;
            ld cur_score = m * sum + scores[i];
            ld rest = 1.0L - m;
            for(int j = 0; j < n; ++j) {
                if(i == j)
                    continue;
                if(cur_score > scores[j])
                    rest -= (cur_score - scores[j]) /  sum;
            }
            if(rest <= 0.0L) {
               r = m - EPS;
            } else {
                l = m + EPS;
            }
        }
        result[i] = l * 100.0L;
    }
    return result;
}

int main() {
    int numberOfCases;
	cin >> numberOfCases;
	for(int testCase = 1; testCase <= numberOfCases; ++testCase) {
        int n;
        cin >> n;
        vector<ld> scores(n);
        for(int i = 0; i < n; ++i) {
            cin >> scores[i];
        }
		cout << "Case #" << testCase << ": " << fixed << setprecision(6) << solve(n, scores) << endl;
	}
}
