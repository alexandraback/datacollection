#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<int> getPartialMatch(const string& str) {
	vector<int> pi(str.size());
	int matched = 0;
	for (int i=1; i<str.size(); ++i) {
		while (matched > 0 && str[i] != str[matched])
			matched = pi[matched-1];
		if (str[i] == str[matched])
			pi[i] = ++matched;
	}
	return pi;
}

int k, l, s;
char keyboard[101], target[101];
vector<int> pi;
int prob[128];
double cache[101][101];

double dp(int matched, int typed) {
	if (typed == s) return 0;
	double &ret = cache[matched][typed];
	if (ret != -1) return ret;
	ret = 0;
	for (int i=0; i<k; ++i) {
		char key = keyboard[i];
		int match = matched;
		while (match > 0 && key != target[match])
			match = pi[match-1];
		if (target[match] == key)
			++match;
		if (match == l)
			ret += 1/(double)k * (1 + dp(pi[match-1], typed+1));
		else
			ret += 1/(double)k * dp(match, typed+1);
	}
	return ret;
}

int main() {
	freopen("r1c\\B-large.in", "r", stdin);
	freopen("r1c\\B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%d%d%d", &k, &l, &s);
		scanf("%s", keyboard);
		scanf("%s", target);
		for (int i=0; i<101; ++i)
			for (int j=0; j<101; ++j)
				cache[i][j] = -1;
		memset(prob, 0, sizeof prob);
		for (int i=0; i<k; ++i)
			prob[keyboard[i]] += 1;
		pi = getPartialMatch(target);
		bool ok = true;
		for (int i=0; i<l; ++i)
			if (prob[target[i]] == 0)
				ok = false;
		int start = 0;
		if (ok && s >= l) start = (s-l)/(l-pi[l-1]) + 1;
		printf("Case #%d: ", N);
		printf("%.10f\n", start - dp(0, 0));
	}
}