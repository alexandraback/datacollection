//Problem: Google Code Jam 2014 Round 1C B
//Name: Reordering Train Cars
//Author: Bruce K. B. Tong
//Tag: Ad Hoc

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define SMALL
//#define LARGE

#define N_SIZE 100
#define MAX_LEN 100
#define MOD 1000000007

void read(int &N, string s[]) {
	char str[MAX_LEN+1];
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		s[i] = str;
	}
}

long long concat(string &str, int u, int N, string s[], int visited[], int k) {
	long long ans = 0;
	if (k == N) {
		int used[26] = {0};
		char last = str[0];
		used[last-'a'] = 1;
		for (int i = 1; i < str.size(); i++) {
			if (last != str[i]) {
				if (used[str[i]-'a'] == 0)
					used[str[i]-'a'] = 1;
				else
					return 0;
				}
			last = str[i];
		}
		return 1;
	}
	for (int i = 0; i < N; i++)
		if (visited[i] == 0) {
			visited[i] = 1;
			ans = (ans + concat(str.append(s[i]), i, N, s, visited, k+1)) % MOD;
			str.erase(str.end()-s[i].size(), str.end());
			visited[i] = 0;
		}
	return ans;
}

long long solve(int N, string s[]) {
	long long ans = 0;
	int visited[N_SIZE] = {0};
	for (int i = 0; i < N; i++) {
		string str = s[i];
		visited[i] = 1;
		ans = (ans + concat(str, i, N, s, visited, 1)) % MOD;
		visited[i] = 0;
	}
	return ans % MOD;
}

int main() {
	freopen("B-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("B-small-attempt0.in", "rt", stdin);
		freopen("B-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("B-large.in", "rt", stdin);
		freopen("B-large.out", "wt", stdout);
	#endif

	int T;				//1 <= T <= 100
	int N;				//1 <= N <= 10 (or 100)
	string s[N_SIZE];	//1 <= length(s[i]) <= 100
	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		read(N, s);
		cout << "Case #" << i << ": ";
		cout << solve(N, s);
		cout << endl;
	}
	return 0;
}