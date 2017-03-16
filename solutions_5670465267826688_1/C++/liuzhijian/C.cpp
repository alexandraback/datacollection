#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int N = 1111111;

map<pair<char, char>, pair<char, char> > result;

int n;
long long repeat;
char buffer[N];

inline pair<char, char> operator * (const pair<char, char> &a, char b) {
	pair<char, char> answer = result[make_pair(a.second, b)];
	if (a.first == '-') {
		if (answer.first == '+') {
			answer.first = '-';
		} else {
			answer.first = '+';
		}
	}
	return answer;
}

inline pair<char, char> operator * (char a, const pair<char, char> &b) {
	pair<char, char> answer = result[make_pair(a, b.second)];
	if (b.first == '-') {
		if (answer.first == '+') {
			answer.first = '-';
		} else {
			answer.first = '+';
		}
	}
	return answer;
}

inline void solve() {
	scanf("%d%lld%s", &n, &repeat, buffer);

	if (repeat > 100) {
		repeat %= 4;
		repeat += 20;
	}

	if (repeat == 0) {
		puts("NO");
		return;
	}

	string str;
	for (; repeat--; str += buffer);

	{
		pair<char, char> result = make_pair('+', '1');
		for (int i = 0; i < (int)str.length(); ++i) {
			result = result * str[i];
		}
		if (result != make_pair('-', '1')) {
			puts("NO");
			return;
		}
	}

//puts("xxx");

	int pi = -1, pk = -1;

	{
		pair<char, char> result = make_pair('+', '1');
		for (int i = 0; i < (int)str.length(); ++i) {
			result = result * str[i];
			if (result == make_pair('+', 'i')) {
				pi = i;
				break;
			}
		}
	}

	{
		pair<char, char> result = make_pair('+', '1');
		for (int i = (int)str.length() - 1; i >= 0; --i) {
			result = str[i] * result;
			if (result == make_pair('+', 'k')) {
				pk = i;
				break;
			}
		}
	}

//printf("%d %d\n", pi, pk);

	if (pi == -1 || pk == -1) {
		puts("NO");
		return;
	}

	if (pi + 1 <= pk - 1) {
		puts("YES");
		return;
	}

	puts("NO");
}

inline void prepare() {
	result[make_pair('1', '1')] = make_pair('+', '1');
	result[make_pair('1', 'i')] = make_pair('+', 'i');
	result[make_pair('1', 'j')] = make_pair('+', 'j');
	result[make_pair('1', 'k')] = make_pair('+', 'k');
	result[make_pair('i', '1')] = make_pair('+', 'i');
	result[make_pair('i', 'i')] = make_pair('-', '1');
	result[make_pair('i', 'j')] = make_pair('+', 'k');
	result[make_pair('i', 'k')] = make_pair('-', 'j');
	result[make_pair('j', '1')] = make_pair('+', 'j');
	result[make_pair('j', 'i')] = make_pair('-', 'k');
	result[make_pair('j', 'j')] = make_pair('-', '1');
	result[make_pair('j', 'k')] = make_pair('+', 'i');
	result[make_pair('k', '1')] = make_pair('+', 'k');
	result[make_pair('k', 'i')] = make_pair('+', 'j');
	result[make_pair('k', 'j')] = make_pair('-', 'i');
	result[make_pair('k', 'k')] = make_pair('-', '1');
}

int main() {
	prepare();
	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}