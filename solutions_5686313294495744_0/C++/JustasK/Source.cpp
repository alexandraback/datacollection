#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:167772160000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <sstream>
#include <assert.h>
#include <functional>
#include <climits>
#include <cstring>

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;
typedef std::pair<long double,long double> pdd;
#define forn(N)          for(int i = 0; i<(int)N; i++)
#define fornj(N)         for(int j = 0; j<(int)N; j++)
#define fornk(N)         for(int k = 0; k<(int)N; k++)
#define forn1(N)          for(int i = 1; i<=(int)N; i++)
#define fornj1(N)         for(int j = 1; j<=(int)N; j++)
#define fornk1(N)         for(int k = 1; k<=(int)N; k++)
#define PI 3.1415926535897932384626433
#define v vector
#define ll long long
#define print(n) printf("%d ", (n));
#define printll(n) printf("%I64d", (n));
#define printline() printf("\n");
#define read(n) scanf("%d", &n);
#define read2(n, m) scanf("%d%d", &n, &m);
#define readll(n) scanf("%I64d", &n);
#define mp make_pair
using namespace std;
map<string, v<int> >v1, v2;
string words[1100][2];
set<string>firstwords[2];
set<string>wordsnow[2];
int N;
int answer;

void solve() {
	forn(1 << N) {
		if (i == 255)
			int asdfwqeg = 16;
		int cnt = 0;
		fornj(N)if ((1 << j) & i)cnt++;
		if (cnt >= answer)continue;
		fornj(2)wordsnow[j].clear();
		fornj(N)if ((1 << j) & i) {
			fornk(2)wordsnow[k].insert(words[j][k]);

		}
		if (wordsnow[0].size() == firstwords[0].size() && wordsnow[1].size() == firstwords[1].size())answer = cnt;
		
	}


}

int main()
{
#if defined(_DEBUG) || defined(_RELEASE)
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//(File".in", "r", stdin); freopen(File".out", "w", stdout);
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int T; cin >> T;
	fornk1(T) {
		 cin >> N;
		 forn(2)firstwords[i].clear();
		forn(N) {
			cin >> words[i][0] >> words[i][1];
			firstwords[0].insert(words[i][0]);
			firstwords[1].insert(words[i][1]);
		}
		random_shuffle(words, words + N);
		answer = 200;
		solve();
		if (N - answer < 0)
			int sdf = 15;
		cout << "Case #" << k << ": " << N - answer << endl;
	}
	

	return 0;

}
