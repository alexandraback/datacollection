#include <iostream>
#include <cstdio>

#define MOD 1000000007
#define CHARS 26
#define MAX_N 100

using namespace std;

typedef long long ll;

int n;

bool used[CHARS];
//bool was[CHARS];//merge with used? (this is for visited chars in sequences)

int aloneCount[CHARS];//count of carts starting and ending with the same letter

//edges
int in[CHARS];
int out[CHARS];

ll fact(int x) {
	ll value = 1;
	for (int i = 2; i <= x; ++i) {
		value = (value * i) % MOD;
	}
	return value;
}

char input[MAX_N][105];

int solve() {
	for (int i = 0; i < CHARS; ++i) {
		in[i] = -1;
		out[i] = -1;
		used[i] = false;
		aloneCount[i] = 0;
	}

	scanf("%d", &n);

	int s[105];
	int sN;
	//cout << "n = " << n << endl;
	for (int j = 0; j < n; ++j) {
		scanf("%s", input[j]);
	}
	for (int j = 0; j < n; ++j) {
		//cout << "---" << endl;
		//cout << "iterate " << j << endl;
		sN = 0;
		char last = 0;
		for (int k = 0; input[j][k]; ++k)
			if (input[j][k] != last) {
				last = input[j][k];
				s[sN++] = input[j][k] - 'a';
				//cout << input[j][k] << endl;
			}
		for (int k = 1; k+1 < sN; ++k) {
			if (used[s[k]])
				return 0;
			used[s[k]] = true;
		}
		//cout << "length " << sN << endl;
		int begin = s[0], end = s[sN-1];
		if (begin < 0 || begin >= CHARS || end < 0 || end >= CHARS) {
			cout << "ERROR" << endl;
			cout << begin << ' ' << end << endl;
			while (true);
		}
		if (begin == end)
			aloneCount[s[0]]++;
		else {
			//begin -> end
			if (out[begin] != -1 || in[end] != -1)
				return 0;
			out[begin] = end;
			in[end] = begin;
		}
	}

	//delete?
	for (int i = 0; i < CHARS; ++i) {
		if (used[i] && (out[i] != -1 || in[i] != -1))
			return 0;
	}

	ll ways = 1;

	//count independent parts
	int parts = 0;
	for (int i = 0; i < CHARS; ++i)
		if (aloneCount[i]) {
			ll now = fact(aloneCount[i]);
			ways = (ways * now) % MOD;
			if (in[i] == -1 && out[i] == -1)
				parts++;//independent part of one letter
		}

	for (int i = 0; i < CHARS; ++i) {
		if (out[i] != -1 && in[i] == -1) {
			int now = i;
			while (out[now] != -1) {
				//cout << now << " ";
				if (used[now])
					return 0;
				used[now] = true;
				now = out[now];
			}
			//cout << now << endl;
			if (used[now])
				return 0;
			used[now] = true;
			parts++;
		}
	}

	//check if all visited?
	for (int i = 0; i < CHARS; ++i) {
		if ((out[i] != -1 || in[i] != -1) && !used[i])
			return 0;
	}
	
	//cout << "parts " << parts << endl;

	ways = (ways * fact(parts)) % MOD;

	//for (int i = 0; i < CHARS; ++i) {
		//cout << char(i+'a') << ": " << endl;
	//}

	return ways;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		//cout << i << endl;
		//int a = solve();
		//cout << "Case #" << i << ": " << a << endl;
		printf("Case #%d: %d\n", i, solve());
		//cout << i << endl;
	}
}
