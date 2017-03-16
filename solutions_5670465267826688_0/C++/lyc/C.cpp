#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
const string basic[4][4] = {
	{"1",  "i",  "j",  "k"},
	{"i", "-1",  "k", "-j"},
	{"j", "-k", "-1",  "i"},
	{"k",  "j", "-i", "-1"}
};
int nCase, l;
long long x;
string str;
map<pair<string, string>, string> mul;

void init() {
	mul.clear();
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			string x, y;
			if (i == 0) x = "1";
			if (i == 1) x = "i";
			if (i == 2) x = "j";
			if (i == 3) x = "k";
			if (j == 0) y = "1";
			if (j == 1) y = "i";
			if (j == 2) y = "j";
			if (j == 3) y = "k";
			mul[make_pair(x, y)] = basic[i][j];
			mul[make_pair("-" + x, "-" + y)] = basic[i][j];
			if (basic[i][j].length() == 1) {
				mul[make_pair("-" + x, y)] = "-" + basic[i][j];
				mul[make_pair(x, "-" + y)] = "-" + basic[i][j];
			}
			else {
				mul[make_pair("-" + x, y)] = basic[i][j].substr(1, 1);
				mul[make_pair(x, "-" + y)] = basic[i][j].substr(1, 1);
			}
		}
}

bool pass() {
	string product = "1";
	for (int i = 0; i < str.length(); ++i)
		product = mul[make_pair(product, str.substr(i, 1))];
	if (product == "1")
		return false;
	else if (product == "-1") {
		if (x % 2 != 1) return false;
	}
	else {
		if (x % 4 != 2) return false;
	}
	product = "1";
	int k = -1, count = 0;
	while (count < 4 * l && product != "i") {
		++count;
		++k;
		product = mul[make_pair(product, str.substr(k % l, 1))];
	}
	if (product != "i") return false;
	count = 0;
	while (count < 4 * l && product != "k") {
		++count;
		++k;
		product = mul[make_pair(product, str.substr(k % l, 1))];
	}
	if (product != "k") return false;
	while (k % l != l - 1 || product != "-1") {
		++k;
		product = mul[make_pair(product, str.substr(k % l, 1))];
	}
	int period = k / l + 1;
	return period <= x;
}

int main()
{
	init();
	scanf("%d", &nCase);
	for (int _case = 1; _case <= nCase; ++_case) {
		scanf("%d%lld", &l, &x);
		cin >> str;
		if (pass())
			printf("Case #%d: YES\n", _case);
		else printf("Case #%d: NO\n", _case);
	}
	return 0;
}
