#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <functional>
#include <cmath>

using namespace std;

vector<int> z_function (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

int recalc(int symnum, int l, int shift) {
    if (symnum < l) {
        return 0;
    }
    symnum -= l;
    return 1 + symnum / shift;
}

static long long sum1 = 0, sum2 = 0;

void solve_t(int k, int l, int s, string &kb, string &p, string buf) {
    if (buf.length() == s) {
        for (int i = 0; i < s; ++i) {
            if (buf.substr(i, l) == p) {
                ++sum1;
            }
        }
        ++sum2;
        return;
    }
    for (int i = 0; i < k; ++i) {
        solve_t(k, l, s, kb, p, buf + kb[i]);
    }
}

double solve() {
    double ans = 0;
    int k, l, s;

    cin >> k >> l >> s;
    string kb, p;
    cin >> kb >> p;

    sum1 = sum2 = 0;
    solve_t(k, l, s, kb, p, "");
    double sum_prob = static_cast<double>(sum1) / sum2;

    int cnt[256];
    for (char z = 'A'; z <= 'Z'; ++z) {
        cnt[z] = 0;
    }
    for (int i = 0; i < kb.length(); ++i) {
        ++cnt[kb[i]];
    }

    for (int i = 0; i < l; ++i) {
        if (!cnt[p[i]]) {
            return 0.0;
        }
    }

    vector<int> zf = z_function(p);
    int shift = l;
    for (int i = 1; i < l; ++i) {
        if (zf[i] == l - i) {
            shift = i;
            break;
        }
    }

    ans = 1 + (s - l) / shift;

    string p2 = p;
    while (p2.length() < 3 * s) {
        if (shift < l) {
            p2 += p.substr(l - shift);
        } else {
            p2 += p;
        }
    }

    map<pair<int, int>, double> e;
    e[make_pair(0, 0)] = 1.0;
    for (int i = 0; i < s; ++i) {
        map<pair<int, int>, double> e2;
        //cout << "iter " << i << endl;
        for (auto &i : e) {
            int symnum = i.first.first;
            int ccnt = i.first.second;
            double prob = i.second;
            //cout << symnum << " " << ccnt << " " << prob << endl;
            char sym = p2[symnum];
            double other = 1.0 - static_cast<double>(cnt[sym]) / k;
            if (e2.count(make_pair(symnum + 1, ccnt))) {
                e2[make_pair(symnum + 1, ccnt)] += prob * cnt[sym] / k;
            } else {
                e2[make_pair(symnum + 1, ccnt)] = prob * cnt[sym] / k;
            }
            if (sym != p2[0]) {
                if (e2.count(make_pair(1, ccnt + recalc(symnum, l, shift)))) {
                    e2[make_pair(1, ccnt + recalc(symnum, l, shift))] += prob * cnt[p2[0]] / k;
                } else {
                    e2[make_pair(1, ccnt + recalc(symnum, l, shift))] = prob * cnt[p2[0]] / k;
                }
                other = 1.0 - static_cast<double>(cnt[p2[0]]) / k;
            }
            if (e2.count(make_pair(0, ccnt + recalc(symnum, l, shift)))) {
//                if (!recalc(symnum, l, shift))
//                cout << prob * other << endl;
                e2[make_pair(0, ccnt + recalc(symnum, l, shift))] += prob * other;
            } else {
//                if (!recalc(symnum, l, shift))
//                cout << prob * other << endl;
                e2[make_pair(0, ccnt + recalc(symnum, l, shift))] = prob * other;
            }
        }
        e = e2;
    }

    //cout << "iter last" << endl;
    for (auto &i : e) {
        int symnum = i.first.first;
        int ccnt = i.first.second;
        double prob = i.second;
        //cout << symnum << " " << ccnt << " " << prob << endl;
        ans -= prob * (ccnt + recalc(symnum, l, shift));
    }

    double ans_t = 1 + (s - l) / shift - sum_prob;

    //cout << ans - ans_t << endl;

//    if (abs(ans - ans_t) > 1e-8) {
//        cerr <<"!" << endl;
//    }
    return ans_t;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        double r = solve();
        cout << "Case #" << i + 1 << ": " << setprecision(16) << r << endl;
    }
    return 0;
}
