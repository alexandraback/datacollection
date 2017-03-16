#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

double dp[101][101];
int trans[101][101];
bool isVisited[101][101];

int n, l, s;
string base, tar;

int fromMax;

double getAns(int len, int stat) {
	double &ret = dp[len][stat];
	if(isVisited[len][stat]) return ret;
	isVisited[len][stat] = true;

	if(stat == tar.size()) ret = getAns(len, fromMax) + 1;
	else {
		ret = 0;
		if(len > 0) {
			for(int i = 0; i < base.size(); i++)
				ret += getAns(len - 1, trans[stat][i]);
			ret /= base.size();
		}
	}

	return ret;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d %d %d", &n, &l, &s);
		cin >> base >> tar;

		for(int i = 0; i <= tar.size(); i++)
			for(int j = 0; j < base.size(); j++) {
				string str = tar.substr(0, i) + base[j];
				trans[i][j] = 0;
				for(int k = 0; k < str.size(); k++) {
					string sub = str.substr(k);
					if(sub == tar.substr(0, sub.size())) {
						trans[i][j] = sub.size();
						break;
					}
				}
			}

		fromMax = 0;
		for(int i = 1; i < tar.size(); i++)
			if(tar.substr(i) == tar.substr(0, tar.size() - i)) {
				fromMax = tar.size() - i;
				break;
			}

		memset(isVisited, 0, sizeof(isVisited));
		
		double expected = getAns(s, 0);

		bool isAble = true;
		for(char ch: tar) {
			bool have = false;
			for(char b: base)
				if(ch == b) {
					have = true;
					break;
				}
			if(!have) {
				isAble = false;
				break;
			}
		}

		double required = 0;
		if(isAble) {
			int len = 0;
			for(int i = 0; i < s; i++) {
				len++;
				if(len == tar.size()) {
					required++;
					len = fromMax;
				}
			}
		}

		printf("Case #%d: %.10lf\n", kase, required - expected);
	}

	return 0;
}
