#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
using namespace std;

#pragma comment(linker, "/STACK:64000000")

#define sqr(x) ((x)*(x))

const int lim = 1e5 + 10;
const int bs = 10;

struct mystring {
	string s;
	mystring() { s = ""; }
	mystring(string str) : s(str) { ; }
	bool operator < (const mystring & ms) const {
		if (s.size() == ms.s.size()) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] < ms.s[i]) return true;
				else if (s[i] > ms.s[i]) return false;
			}
			return false;
		}
		else return s.size() < ms.s.size();
	}
};

int n;
set<mystring> even, odd;
set<mystring> possib;
string pod[50005];
int num[50005][105];
int sq[50005][125];
string a, b;
int A[125], B[125];
int q = 0;
bool was = false;

void rec(string cur, int sum) {
	if (cur.size() > 25) return;
	for (int i = 0; i < 4; i++) {
		int s = sum + 2*sqr(i);
		int sz = cur.size();
		if (s < 10) {
			if (sz && cur[0] != '0') rec(cur + ((char)('0' + i)), s);
			else if (!sz) {
				rec(cur + ((char)('0' + i)), s);
			}
			if ((sz == 0 && s != 0) || (sz && cur[0] != '0')) even.insert(mystring(cur + ((char)('0' + i))));
		}
		s = sum + sqr(i);
		if (s < 10) {
			if ((sz == 0 && s != 0) || (sz && cur[0] != '0')) odd.insert(mystring(cur + ((char)('0' + i))));
		}
	}
}
bool isLess(int dig[], int id) {
	if (dig[0] < sq[id][0]) return true;
	if (dig[0] > sq[id][0]) return false;
	for (int i = 1; i <= dig[0]; i++) {
		if (dig[i] > sq[id][i]) return false;
		if (dig[i] < sq[id][i]) return true;
	}
	return false;
}
bool isBig(int dig[], int id) {
	if (dig[0] < sq[id][0]) return false;
	if (dig[0] > sq[id][0]) return true;
	for (int i = 1; i <= dig[0]; i++) {
		if (dig[i] > sq[id][i]) return true;
		if (dig[i] < sq[id][i]) return false;
	}
	return false;
}
int FindLessEqual(int dig[]) {
	int l = 0, r = q - 1;
	int res = 0;
	while (r >= l) {
		int mid = (l + r)/2;
		if (isLess(dig, mid)) {
			r = mid - 1;
		}
		else if (isBig(dig, mid)) {
			if (mid + 1 > res) res = mid + 1;
			l = mid + 1;
		}
		else {
			was = true;
			return mid + 1;
		}
	}
	return res;
}
int main() {
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small-attempt0.out", "wt", stdout);

	rec("", 0);

	for (set<mystring>::iterator it = even.begin(); it != even.end(); it++) {
		string cur = (*it).s;
		string temp = cur;
		reverse(cur.begin(), cur.end());
		temp = temp + cur;
		possib.insert(mystring(temp));
	}

	for (set<mystring>::iterator it = odd.begin(); it != odd.end(); it++) {
		string cur = (*it).s; if (cur.size() < 1) continue;
		string temp = cur;
		cur.erase(cur.begin() + cur.size() - 1);
		reverse(cur.begin(), cur.end());
		temp = temp + cur;
		possib.insert(mystring(temp));
	}

	for (set<mystring>::iterator it = possib.begin(); it != possib.end(); it++) {
		pod[q++] = (*it).s;
	}

	for (int i = 0; i < q; i++) {
		for (int j = 0; j < pod[i].size(); j++)
			num[i][++num[i][0]] = pod[i][j] - '0';
	}

	for (int i = 0; i < q; i++) {
		for (int id1 = 1; id1 <= num[i][0]; id1++) {
			for (int id2 = 1; id2 <= num[i][0]; id2++) {
				int id3 = id1 + id2 - 1;
				int carry = num[i][id1] * num[i][id2];
				while (carry) {
					if (id3 > sq[i][0])
						sq[i][0] = id3;
					carry = carry + sq[i][id3];
					sq[i][id3] = carry % bs;
					carry /= bs;
					id3++;
				}
			}
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		a = ""; b = "";
		cin >> a >> b;
		A[0] = 0; B[0] = 0;
		for (int j = 0; j < a.size(); j++) A[++A[0]] = a[j] - '0';
		for (int j = 0; j < b.size(); j++) B[++B[0]] = b[j] - '0';
		was = false;
		int answer = FindLessEqual(B);
		was = false;
		answer -= FindLessEqual(A);
		if (was) answer++;

		cout << "Case #" << i + 1 << ": " << answer << endl;
	}

	return 0;
}