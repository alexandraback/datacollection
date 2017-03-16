#include <bits/stdc++.h>
using namespace std;

/*
*/

typedef vector<int> VI;
typedef vector<VI> VVI;

int seen[1005];

int w[1005][1005];
int n, m;
bool FindMatch(int i, VI &mr, VI &mc) {
  for (int j = 0; j < m; j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], mr, mc)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}


int BipartiteMatching(VI &mr, VI &mc) {
  mr = VI(n, -1);
  mc = VI(m, -1);
  int ct = 0;
//  VI seen(w[0].size());
  for (int i = 0; i < n; i++) {
    memset(seen, 0, sizeof(seen));
    if (FindMatch(i, mr, mc)) ct++;
  }
  return ct;
}

char s[25];

int main()
{
	freopen("input.in", "r", stdin);
	freopen("input.out", "w", stdout);
	int T;
	scanf("%d", &T);
	vector<pair<int, int> > eds;
	map<string, int> first;
	map<string, int> second;
	string S;
	for (int z = 1; z <= T; z++)
	{
		int x;
		scanf("%d", &x);
		eds.clear();
		first.clear();
		second.clear();
		for (int i = 0; i < x; i++)
		{
			scanf("%s", s);
			S = string(s);
			int a, b;
			a = first.size();
			if (first.count(S))
				a = first[S];
			else
				first[S] = a;

			scanf("%s", s);
			S = string(s);
			
			
			b = second.size();
			if (second.count(S))
				b = second[S];
			else
				second[S] = b;
			eds.push_back(make_pair(a, b));
		}

		memset(w, 0, sizeof(w));
		n = first.size();
		m = second.size();
		for (int i = 0; i < eds.size(); i++)
		{
			w[eds[i].first][eds[i].second] = 1;
		}
		VI r, c;
		int res = BipartiteMatching(r, c);
		for (int i = 0; i < r.size(); i++)
			if (r[i] == -1)
				res++;
		for (int j = 0; j < c.size(); j++)
			if (c[j] == -1)
				res++;
		res = x - res;
		printf("Case #%d: %d\n", z, res);
	}
}