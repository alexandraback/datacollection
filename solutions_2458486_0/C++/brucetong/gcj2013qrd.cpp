//Problem: Google Code Jam 2013 Qualification Round D
//Name: Treasure
//Author: Bruce K. B. Tong
//Tag: DP, Backtracking

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SMALL
//#define LARGE

#define N_SIZE 200
#define DP_SIZE (1 << 22)

typedef struct _chest {
	//int no;			//chest number
	int keytype;		//key type to open this chest
	vector<int> keys;	//key types inside
} Chest;

Chest chest[N_SIZE+1];
int keys[N_SIZE+1];
int opened[N_SIZE+1];
int ans[N_SIZE+1];
int f[DP_SIZE];

void read(int &K, int &N) {
	fill(keys, keys+N_SIZE+1, 0);
	for (int i = 1; i <= N_SIZE; i++) {
		chest[i].keytype = -1;
		chest[i].keys.clear();
	}

	int k, ki;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> ki;
		keys[ki]++;
	}
	for (int i = 1; i <= N; i++) {
		cin >> chest[i].keytype >> k;
		for (int j = 0; j < k; j++) {
			cin >> ki;
			chest[i].keys.push_back(ki);
		}
	}
}

void print(int K, int N) {
	for (int i = 1; i <= N_SIZE; i++)
		cout << keys[i] << " ";
	cout << endl;
	for (int i = 1; i <= N+1; i++) {
		cout << i << ":" << chest[i].keytype << " ";
		for (int j = 0; j < chest[i].keys.size(); j++)
			cout << chest[i].keys[j] << " ";
		cout << endl;
	}
}

int test(int K, int N, int n, int S) {
	if (N <= 0) return (f[S] = 1);	//N == 0: all chests have been opened
	if (K <= 0) return (f[S] = -1);	//no keys left but still have chests not opened
	if (f[S] != 0) return f[S];
	//asserted: K > 0
	for (int i = 1; i <= n; i++)
		if (!opened[i] && keys[chest[i].keytype] > 0) {
			opened[i] = 1;
			keys[chest[i].keytype]--;
			for (int j = 0; j < chest[i].keys.size(); j++)
				keys[chest[i].keys[j]]++;
			int res = test(K-1+chest[i].keys.size(), N-1, n, S | (1 << i));
			if (res == 1) {
				ans[N] = i;
				return (f[S] = 1);
			}
			opened[i] = 0;
			keys[chest[i].keytype]++;
			for (int j = 0; j < chest[i].keys.size(); j++)
				keys[chest[i].keys[j]]--;
		}
	return (f[S] = -1);	//tried all choices but still cannot open all chests
}

void solve(int K, int N) {
	fill(opened, opened+N_SIZE+1, 0);
	fill(f, f+DP_SIZE, 0);
	//print(K, N);
	if (test(K, N, N, 0) == -1)
		cout << "IMPOSSIBLE";
	else {
		cout << ans[N];
		for (int i = N-1; i >= 1; i--)
			cout << " " << ans[i];
	}
}

int main() {
	freopen("D-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("D-small-attempt0.in", "rt", stdin);
		freopen("D-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("D-large.in", "rt", stdin);
		freopen("D-large.out", "wt", stdout);
	#endif

	int T;				//1 <= T <= 25
	int K;				//1 <= K <= 40 (or 400)
	int N;				//1 <= N <= 20 (or 200)

	cin >> T;
	for (int i = 1; i <= T; i++) {
		read(K, N);
		//print(K, N);
		cout << "Case #" << i << ": ";
		solve(K, N);
		cout << endl;
	}
	return 0;
}