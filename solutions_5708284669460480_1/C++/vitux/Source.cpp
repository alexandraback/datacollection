#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <sstream>
#include <fstream>
#define lol long long
using namespace std;



ifstream in("B-large.in");
ofstream out("outIG.txt");


#define cin in
#define cout out
/**/


vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int k, l, s;
        cin >> k >> l >> s;
        string keys;
        vector<lol> tm(26, 0);
        string pattern;
        cin >> keys >> pattern;
        for (char c: keys)
            ++tm[c - 'A'];
        vector<int> pr = prefix_function(pattern);
        int mp = 0;
        int mx = (pattern.length() <= s);
        for (int i = 0; i < pr.size(); ++i)
            mp = max(mp, pr[i]);
        int p = pattern.length();
        while (p <= s)
        {
            p += pattern.length() - mp;
            if (p <= s)
                ++mx;
        }
        vector<vector<pair<int, double> > > dp(pattern.length() + 1, vector<pair<int, double> >());
        pattern += "#";
        dp[0].push_back(make_pair(0, 1));
        for (int i = 0; i < s; ++i)
        {
            vector<vector<pair<int, double> > > dp2(pattern.length(), vector<pair<int, double> >());
            for (int ch = 0; ch < 26; ++ch)
            {
                if (!tm[ch])
                    continue;
                for (int j = 0; j < dp.size(); ++j)
                {
                    int nxt = j;
                    while (pattern[nxt] != ch + 'A')
                    {
                        if (nxt == 0)
                        {    
                            nxt = -1;
                            break;
                        }
                        nxt = pr[nxt - 1];
                    }
                    for (pair<int, double> pp : dp[j])
                    {
                        double pr = pp.second * tm[ch] * 1. / keys.length();
                        if (pr < 0.00001)
                            continue;
                        if (!dp2[nxt + 1].empty() && dp2[nxt + 1].back().first == pp.first + (nxt  + 1 == pattern.length() - 1))
                            dp2[nxt + 1].back().second += pr;
                        else
                            dp2[nxt + 1].push_back(make_pair(pp.first + (nxt  + 1 == pattern.length() - 1), pr));
                    }
                }
            }
            swap(dp, dp2);
        }
        double sm = 0;
        for (int i = 0; i < dp.size(); ++i)
            for (int j = 0; j < dp[i].size(); ++j)
            {
                mx = max(mx, dp[i][j].first);
                sm += dp[i][j].second * dp[i][j].first;
            }
        cout << "Case #" << i + 1 << ": ";
        cout.precision(10);
        cout << fixed << mx - sm << endl;
    }
}