#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
void precalc();

#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	//freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	cout.sync_with_stdio(0);
	int t = 1;
	precalc();
	//cout << "done!\n";
	freopen("in.txt", "r", stdin);
	cin >> t;
	//gen();
	while (t--)
		solve();
	/*
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif*/
	return 0;
}

int timer = 0;
#define int li

vector<string> have;

set<int> mapa;

int pr = 2013;
int step[20];

int Hash (const string& s) {
	int res = 0;
	for (int i = 0; i < s.length(); ++i)
		res = res * pr + s[i];
	return res;
}

void precalc() {
	step[0] = 1;
	for (int i = 1; i < 20; ++i)
		step[i] = step[i - 1] * pr;
	FILE* dic = fopen("dictionary.txt", "r");
	string s;
	int id = 0;
	while (true) {
		s.clear();
		char c;
		while ((c = getc(dic)) != EOF) {
			if (c == '\n')
				break;
			s += c;
		}
		if (c == EOF)
			break;
		have.push_back(s);
		int curHash = Hash(s);
		mapa.insert(curHash);
		++id;
	}
	fclose(dic);
}

int dp[5000][5];

int INF = 1000000000;

void solve() {
	++timer;
	
	string s;
	cin >> s;
	for (int i = 0; i < 5000; ++i)
		for (int j = 0; j < 5; ++j)
			dp[i][j] = INF;
	dp[0][4] = 0;
	for (int i = 0; i < s.length(); ++i) {
			int curHash = 0;
			for (int j = i; j < i + 10 && j < s.length(); ++j) {
				curHash = curHash * pr + s[j];
				if (mapa.find(curHash) != mapa.end()) {
					for (int w = 0; w < 5; ++w) 
						if (dp[i][w] < INF) {
							int diff = w + j - i + 1;
							if (diff > 3)
								diff = 4;
							dp[j + 1][diff] = min(dp[j + 1][diff], dp[i][w]);
						}
				}
				
				for (int first = i; first <= j; ++first) {
					for (char c = 'a'; c <= 'z'; ++c)
						if (c != s[first]) {
							int nowHash = curHash + (c - s[first]) * step[j - first];
							if (mapa.find(nowHash) != mapa.end()) {
								for (int w = 0; w < 5; ++w)
									if (dp[i][w] < INF && first - i + w >= 4) {
										int diff = j - first;
										if (diff > 3)
											diff = 4;
										dp[j + 1][diff] = min(dp[j + 1][diff], dp[i][w] + 1);
									}
							}

							for (int second = first + 5; second <= j; ++second)
								for (char cc = 'a'; cc <= 'z'; ++cc)
									if (cc != s[second]) {
										int newHash = nowHash + (cc - s[second]) * step[j - second];
										if (mapa.find(newHash) != mapa.end()) {
											for (int w = 0; w < 5; ++w)
												if (dp[i][w] < INF && first - i + w >= 4) {
													int diff = j - second;
													if (diff > 3)
														diff = 4;
													dp[j + 1][diff] = min(dp[j + 1][diff], dp[i][w] + 2);
												}
										}
									}

						}
				}

			}
	}
	

	cout << "Case #" << timer << ": ";

	int res = 1000000000;
	for (int w = 0; w < 5; ++w)
		res = min(res, dp[s.length()][w]);
	cout << res << "\n";

}