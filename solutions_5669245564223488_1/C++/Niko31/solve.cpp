#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

const int MOD = 1000000007;

long long solve()
{
	int n;
		cin >> n;
		vector<string> s(n);
		vector<vector<bool> > used(n, vector<bool>(256));
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			for (int j = 0; j < s[i].size(); j++)
				used[i][s[i][j]] = true;
		}
		//if (n == 1) return 1;

		vector<vector<char> > ns(n, vector<char>(2));
		for (int i = 0; i< n; i++)
		{
			vector<char> t;
			for (int j = 0; j < s[i].length(); j++)
				if (t.size() == 0 || t.back() != s[i][j]) t.push_back(s[i][j]);
			
			for (int j = 0; j < t.size(); j++)
				for (int k = j + 1; k < t.size(); k++)
					if (t[k] == t[j]) return 0;

			for (int j = 1; j < t.size() - 1; j++)
				for (int k = 0; k < n; k++)
					if (k != i && used[k][t[j]]) return 0;

			ns[i][0] = t[0];
			ns[i][1] = t.back();
		}

		char cur = 'a' - 1;
		long long res = 1;
		int it = 0;
		while (ns.size() != 1 && it < 26)
		{
			it++, cur++;
			if (cur > 'z') cur = 'a';
			int cntFull = 0;
            int cntBeg = 0;
            int cntEnd = 0;
            char next = cur;
            char prev = cur;
            for (int i = 0; i < n; i++) 
            {
                if (ns[i][0] == cur && ns[i][1] == cur) cntFull++;
                if (ns[i][0] == cur && ns[i][1] != cur) cntEnd++, next = ns[i][1];
                if (ns[i][0] != cur && ns[i][1] == cur) cntBeg++, prev = ns[i][0];
            }
            if (cntBeg + cntEnd + cntFull == 0) continue;
            if (cntBeg > 1 || cntEnd > 1) return 0;
            for (int k = 1; k <= cntFull; k++)
            	res *= k, res %= MOD;
            vector<vector<char> > nns;
            if (prev  == next && prev != cur) return 0;
            
            nns.push_back({prev, next});
            for (int i = 0; i < n; i++)
            	if (ns[i][0] != cur && ns[i][1] != cur) nns.push_back(ns[i]);
            n = nns.size();
			ns = nns;
		}
		for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) 
                for (int k = 0; k < 2; k++) 
                    for (int l = 0; l < 2; l++) 
                        if (ns[i][k] == ns[j][l]) return 0;
        for (int i = 1; i <= n; i++)
        	res *= i, res %= MOD;
        return res;
}


int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": " << solve() << "\n";
	}
}