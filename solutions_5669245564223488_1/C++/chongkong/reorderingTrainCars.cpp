#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;


ll fact(int n) {
	ll ret = 1;
	while (n) {
		ret = (ret * (n--)) % mod;
	}

	return ret;
}

ll go() {
	map <char, char> next;
	int n;
	vector <string> train;
	int dup[256] = { 0 };
	int bitmap[256] = { 0 };
	int panic[256] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		train.push_back(temp);
	}
	fprintf(stderr, "0\n");
	for (int i = 0; i < train.size(); i++) {
		char beg = train[i][0], end = train[i][train[i].length() - 1];
		if (beg == end)
			dup[beg]++;
		if (train[i].length() == 1) {
			bitmap[beg] = 1;
		}
		for (int j = 1; j < train[i].length(); j++) {
			bitmap[train[i][j]] = 1;
			if (train[i][j] != beg) {
				if (next.find(beg) != next.end())
					return 0;
				next[beg] = train[i][j];
				beg = train[i][j];
				if (beg != end) {
					panic[beg] = 1;
				}
			}
		}
	}
	fprintf(stderr, "1\n");
	for (int i = 0; i < train.size(); i++) {
		char beg = train[i][0];
		if (panic[beg] == 1)
			return 0;
	}

	int sections = 0;
	for (char a = 'a'; a <= 'z'; a++) {
		if (bitmap[a]) {
			if (next.find(a) == next.end()) {
		//cout << "end char: " << a << endl;
				sections++;
			}
		}
	}
	//cout << "sections: " << sections << endl;
	for (char a = 'a'; a <= 'z'; a++) {
		if (bitmap[a]) {
			char b = a;
			int cnt = 0;
			while (next.find(b) != next.end()) {
				cnt++;
				b = next[b];
				if (b == a) return 0;
				if (cnt > 30) return 0;
			}

		}
	}
	fprintf(stderr, "2\n");
	ll ret = 1;
	for (char a = 'a'; a <= 'z'; a++) {
		if (bitmap[a]) {
	//		cout << "dup[" << a << "]: " << dup[a] << endl;
			ret = (ret * fact(dup[a])) % mod;
		}
	}

	ret = (ret * fact(sections)) % mod;
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int CaseNum;
	cin >> CaseNum;
	for (int Case = 1; Case <= CaseNum; Case++)
	{
		cout << "Case #" << Case << ": ";
		fprintf(stderr, "Case #%d\n", Case);

		cout << go() << endl;
	}
}