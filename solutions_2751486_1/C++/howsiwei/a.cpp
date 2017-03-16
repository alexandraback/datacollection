#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ifstream fin("a.in");
ofstream fout("A.out");

bool isconso(char c)
{
	return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solve()
{
	string s;
	int n;
	fin >> s >> n;
	int len = s.size();
	vector<int> a(len);
	a[len-1] = isconso(s[len-1]);
	for (int i = len-2; i >= 0; --i) {
		if (!isconso(s[i])) {
			a[i] = 0;
		}
		else a[i] = a[i+1]+1;
	}

	ll ans = 0;
	int first_begin = 0;
	for (; a[first_begin] < n; ++first_begin);

	for (int i = 0; i <= len-n; ++i) {
		if (first_begin < i) {
			++first_begin;
			for (; first_begin < len && a[first_begin] < n; ++first_begin);
		}
		if (first_begin >= len) break;
		ans += len-(n+first_begin)+1;
	}

	fout << ans;
}

int main()
{
	int n;
	fin >> n;

	for (int case_num = 1; case_num <= n; ++case_num) {
		fout << "Case #" << case_num << ": ";
		solve();
		fout << '\n';
	}

	return 0;
}
