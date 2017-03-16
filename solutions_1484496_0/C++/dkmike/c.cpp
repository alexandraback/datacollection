#include <stdio.h>
#include <vector>

using std::vector;


void init(void) {
}

void read(void) {
}

int calcsum(int mask, vector < int > &s) {
	int sum = 0;
	int i = 0;
	while (0 != mask) {
		if (mask & 1) {
			sum += s[i];
		}
		mask = mask >> 1;
		++i;
	}
	return sum;
}

void newset(int mask, vector < int > &s, vector < int > &news, int &N, vector < int > & perm, int NN) {
	news.clear();
	perm.clear();
	N = 0;
	for (int i = 0; i < NN; ++i) {
		if (!(mask & 1)) {
			news.push_back(s[i]);
			perm.push_back(i);
			++N;
		}
		mask = mask >> 1;
	}
}

void print(int mask, vector <int> *perm, vector <int> &s) {
	int i = 0;
	while (0 != mask) {
		if (mask & 1) {
			if (NULL == perm) {
				printf("%d ", s[i]);
			} else {
				printf("%d ",s[(*perm)[i]]);
			}
		}
		mask = mask >> 1;
		++i;
	}
	puts("");
}

void solve(void) {
	int N = 0;
	scanf("%d", &N);
	vector < int > s;
	for (int i = 0; i < N; ++i) {
		int tmp = 0;
		scanf("%d", &tmp);
		s.push_back(tmp);
	}

	int NN = 1 << N;
	for (int i = 1; i < NN; ++i) {
		int sum = calcsum(i, s);
		vector < int > news;
		vector <int > perm;
		int N1 = 0;
		newset(i, s, news, N1, perm, N);
		int NN1 = 1 << N1;
		for (int j = 1; j < NN1; ++j) {
			int sum1 = calcsum(j, news);
			if (sum == sum1) {
				print(i, NULL, s);
				print(j, &perm, s);
				return;
			}
		}
	}
	puts("Impossible");
}

int main(void) {
	freopen("c.in", "rt", stdin);
	freopen("c.out", "wt", stdout);

	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d:\n", i + 1);
		init();
		read();
		solve();
	}

	fcloseall();

	return 0;
}
