#include <cstdio>
#include <string>
#include <set>
#include <cstdlib>

int T, A, B;

std::string toString(int a) {
	char buf[50];
	sprintf(buf, "%d", a);
	return buf;
}

int toInt(const std::string& s) {
	return atoi(s.c_str());
}

int solve() {
	std::set<std::string> set;

	for (int i = A; i <= B; ++i) {
		std::string n = toString(i);
		std::string orig = n;
		for (int j = 0; j < n.size(); ++j) {
			n = n[n.size()-1]+n.substr(0, n.size()-1);
			int n_int = toInt(n);
			if (n_int <= i || n_int > B) continue;
			set.insert(orig+n);
		}
	}
	return set.size();
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %d", &A, &B);
		printf("Case #%d: %d\n", t, solve());
	}
}