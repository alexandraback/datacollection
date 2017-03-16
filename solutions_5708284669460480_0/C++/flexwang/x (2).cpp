#include <stdio.h>
#include <vector>
#include <map>
#include <hash_map>
#include <algorithm>
#include <utility>
#include <string.h>

using namespace std;

typedef long long ll;

int k, l, s;

const int max_size = 2000;
char key[max_size], target[max_size];

struct sk
{
	char c;
	double p;
};

struct wk
{
	string s;
	double p;
};

vector<sk> ss;
vector<wk> ww;

void build(vector<wk>& o, const string& c, const double& p)
{
	for (int i=0; i<ss.size(); i++) {
		string c2 = c;
		double p2 = p;
		c2 += ss[i].c;
		p2 *= ss[i].p;
		if (c2.length() == s) {
			wk w;
			w.s = c2;
			w.p = p2;
			o.push_back(w);
		}
		else
			build(o, c2, p2);
	}
}

int ins(string& t, string& s)
{
	int ans = 0;

	for (int i=0; i<s.length(); i++) {
		bool flag = true;
		for (int j=0; j<t.size(); j++) {
			if (i+j >= s.length()) {
				flag = false;
				break;
			}
			if (t[j] != s[i+j]) {
				flag = false;
				break;
			}
		}
		if (flag)
			ans ++;
	}
	return ans;




}

double solve()
{
	map<char, int> ks;
	for (int i=0; i<k; i++) {
		ks[key[i]] ++;
	}
	
	ss.clear();
	for (map<char, int>::iterator iter=ks.begin(); iter!=ks.end(); iter++) {
		sk s;
		s.c = iter->first;
		s.p = (double)iter->second / k;
		ss.push_back(s);
	}

	int max_b = 0;

	string c;
	double p = 1;
	ww.clear();

	build(ww, c, p);

	double eb = 0.f;

	for (int i=0; i<ww.size(); i++) {
		int nb = ins(string(target), ww[i].s);
		max_b = std::max(max_b, nb);
		if (nb > 0)
			eb += nb * ww[i].p;
	}
	return max_b - eb;
}

int main()
{
	freopen("D:\\gcj\\a\\a.txt", "r", stdin);
	freopen("D:\\gcj\\a\\r.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	for (int icase=1; icase<=ncase; icase++) {
			scanf("%d %d %d", &k, &l, &s);
			scanf("%s %s", key, target);
		
		printf_s("Case #%d: %lf\n", icase, solve());

	}
	

	return 0;
}