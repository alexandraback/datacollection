#include <iostream>
#include <iomanip>

using namespace std;

string t1, key;

int cnt, s, mvs, mxCnt;

const int MAXN = 10;
char c[MAXN];

void bt(int lvl) {
	if (lvl == s) {
/*		cerr << " bt: ";
		for (int i = 0; i < s; i++)
			cerr << c[i] << " ";
		cerr << endl;*/
		mvs++;
		int tmpCnt = 0;
		for (int i = 0; i < s - (int)key.size() + 1; i++) {
			bool good = true;
			for (int j = 0; j < key.size(); j++)
				good &= key[j] == c[i + j];
			tmpCnt += good;
		}
		cnt += tmpCnt;
		mxCnt = max(mxCnt, tmpCnt);
		return;
	}
	for (int i = 0; i < t1.size(); i++) {
		c[lvl] = t1[i];
		bt(lvl + 1);
	}
}

int main() {
	int tt;
	cin >> tt;
	for (int o = 1; o <= tt; o++) {
		int k, l;
		cin >> k >> l >> s;
		cin >> t1 >> key;
		cnt = 0, mvs = 0, mxCnt = 0;
		bt(0);
		cout << "Case #" << o << ": " << setprecision(7) << fixed << (double) mxCnt - (double) cnt / (double) mvs << endl;
	}
	return 0;
}
