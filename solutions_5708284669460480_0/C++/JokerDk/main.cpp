#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//#define _CRT_SECURE_NO_WARNINGS
using namespace std;
typedef long long ll;

int solve( int r, int c, int w)
{
	int remain = 0;
	int ret = 0;

	remain = c / w-1;
	int other = max(c%w-1, 0);

	ret = r*c - remain*(w - 1) - other;
	return ret;
}

void gen(
	vector<char>& cs,
	vector<double>& ps,
	vector<string>& ss, 
	vector<double>& ps2, 
	string& w, double prob,
	string& target) {
	for (int i = 0; i < cs.size(); i++) {
		string w2 = w;
		double p2 = prob;
		w2 += cs[i];
		p2 *= ps[i];
		if (w2.length() == target.length()) {
			ss.push_back(w2);
			ps2.push_back(p2);
		}
		else
			gen(cs, ps, ss, ps2, w2, p2, target);
	}
}

int get_num_instances(string& target, string& source)
{
	int ans = 0;

	for (int i = 0; i < source.length(); i++) {
		bool same = true;
		for (int j = 0; j < target.size(); j++) {
			if (i + j >= source.length()) {
				same = false;
				break;
			}
			if (target[j] != source[i + j]) {
				same = false;
			}
		}
		if (same)
			ans++;
	}
	return ans;

}

double solve_case(int s, string key, string target)
{
	int k = key.length();
	int l = target.length();
	const int max_size = 9999;
	int tab[max_size];
	memset(tab, 0, sizeof(tab));
	for (int i = 0; i < k; i++) {
		tab[key[i]] ++;
	}

	vector<char> cs;
	vector<double> ps;

	for (int i = 0; i < max_size; i++) {
		if (tab[i]) {
			cs.push_back(i);
			ps.push_back((tab[i] / (double)k));
		}
	}

	vector<string> ss;
	vector<double> ps2;

	gen(cs, ps, ss, ps2, string(), 1.0, target);

	int total_banana = 0;
	double expected = 0.0;
	for (int i = 0; i < ss.size(); i++) {
		int bs = get_num_instances(target, ss[i]);
		if (bs > 0) {
			if (bs > total_banana)
				total_banana = bs;
			expected = expected + bs * ps2[i];
		}
	}
	double ans = total_banana - expected;
	return ans;
}


int main()
{
	//freopen("A-large-practice (1).in", "r", stdin);
	//freopen("A-small-attempt2.in", "r", stdin);
	//freopen("A-small-attempt3.in", "r", stdin);
	freopen("a.txt", "r", stdin);

	int N;
	cin >> N;

	FILE * p; p = fopen("result.txt", "w");
	
	for (int i = 0; i < N; ++i)
	{
		int K, L, S;
		string key, target;
		cin >> K>>L>>S;
		cin >> key >> target;
		double ret = solve_case(S, key, target);
		fprintf(p, "Case #%d: %lf\n", i + 1, ret);
	}
	fclose(p);
	return 0;
}