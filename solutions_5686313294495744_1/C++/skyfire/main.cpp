#include <bits/stdc++.h>

using namespace std;

set<string> w1, w2;
string ss1[1111], s1[1111], s2[1111], ss2[1111];
int i1[1111], i2[1111];

int k1, k2;
vector<int> g[1111];
vector<int> mt;
vector<char> used;
 
bool kuhn(int v) 
{
	if (used[v])  
        return false;
	used[v] = true;
	for (int to: g[v]) {
		if (mt[to] == -1 || kuhn(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int main()
{
    //freopen("sample.in", "r", stdin);
    //freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n_tests;
    scanf("%d", &n_tests);

    for (int test_id = 1; test_id <= n_tests; ++test_id)
    {
        int n;
        scanf("%d", &n);

        w1.clear();
        w2.clear();
        for (int i = 0; i < n; ++i) {
            cin >> s1[i] >> s2[i];
            w1.insert(s1[i]);
            w2.insert(s2[i]);
        }

        k1 = 0; 
        for (string s: w1)
            ss1[k1++] = s;

        k2 = 0;
        for (string s: w2)
            ss2[k2++] = s;

        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (ss1[j] != s1[i]) ++j;
            i1[i] = j;
        }

        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (ss2[j] != s2[i]) ++j;
            i2[i] = j;
        }

        for (int i = 0; i < k1; ++i)
            g[i].clear();

        for (int i = 0; i < n; ++i) {
            g[i1[i]].push_back(i2[i]);
        }
                
        printf("Case #%d: ", test_id);

        mt.assign(k2, -1);
        for (int v = 0; v < k1; ++v) {
            used.assign(k1, false);
            kuhn(v);
        }

        set< pair<int, int> > selected;

        set<int> p1, p2;
     
        for (int i = 0; i < k2; ++i)
            if (mt[i] != -1) { 
                selected.insert(make_pair(mt[i], i));
                p1.insert(mt[i]);
                p2.insert(i);
            }

        int res = 0;

        for (int i = 0; i < n; ++i) {

            pair<int, int> c = make_pair(i1[i], i2[i]);

            if (!p1.count(i1[i]) || !p2.count(i2[i])) {
                selected.insert(c);
                p1.insert(i1[i]);
                p2.insert(i2[i]);
            }
            else if (!selected.count(c)) {
                ++res;
            }
        }

        printf("%d\n", res);
    }

    return 0;
}
