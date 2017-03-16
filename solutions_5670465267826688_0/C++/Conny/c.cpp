#include <iostream>
using namespace std;

long long trans[8][8] = {
	{7, 6, 4, 5, 3, 2, 0, 1},
	{6, 7, 5, 4, 2, 3, 1, 0},
	{5, 4, 7, 6, 0, 1, 2, 3},
	{4, 5, 6, 7, 1, 0, 3, 2},
	{2, 3, 1, 0, 7, 6, 4, 5},
	{3, 2, 0, 1, 6, 7, 5, 4},
	{0, 1, 2, 3, 4, 5, 6, 7},
	{1, 0, 3, 2, 5, 4, 7, 6}
};

const long long MAXN = 10002;
char str[MAXN];
long long str2num[MAXN];
long long len;
long long rep;

long long getIndex() {
	long long curr = 6;

	for (long long i = 0; i < 5; i++) {
		for (long long j = 0; j < len; j++) {
			curr = trans[curr][str2num[j]];
			if (curr == 0) {
				return i * len + j + 1;
			}
		}
	}

	return -1;
}

long long getRevIndex() {
	long long curr = 6;

	for (long long i = 0; i < 5; i++) {
		for (long long j = 0; j < len; j++) {
			curr = trans[str2num[len - j - 1]][curr];
			if (curr == 4) {
				return i * len + j + 1;
			}
		}
	}

	return -1;
}

bool totalvalid() {
	long long curr = 6;

	for (long long i = 0; i < len; i++) {
		curr = trans[curr][str2num[i]];
	}

	long long num = 6;
	for (long long i = 0; i != rep % 4; i++) {
		num = trans[num][curr];
	}

	bool result = (num == 7);

	//cout << "totalvalid: " << result << endl;
	return result;
}

bool getResult() {
	for (long long i = 0; i < len; i++) {
		str2num[i] = (str[i] - 'i') << 1;
	}

	if (!totalvalid()) {
		return false;
	}

	long long x = getIndex(), y = getRevIndex();
	//cout << "x: " << x << " y: " << y << endl;
	if (x < 0 || y < 0)
		return false;

	return (x + y < len * rep);
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);

	long long nCases;
	cin >> nCases;

	for (long long cnt = 1; cnt <= nCases; cnt++) {
		cin >> len >> rep;
		cin >> str;

		cout << "Case #" << cnt << ": ";
		if (getResult()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
