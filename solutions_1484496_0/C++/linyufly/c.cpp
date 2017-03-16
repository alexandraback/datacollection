#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 1000;

map<int, int> status[maxn];
int s[maxn], seq1[maxn], seq2[maxn];
int n, l1, l2;

void Solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i]);
	status[0].clear();
	status[0][-1] = 0;
	for (int i = 0; i < n; i++) {
		status[i + 1].clear();
		for (map<int, int>::iterator itr = status[i].begin(); itr != status[i].end(); itr++) {
			int value = itr->first == -1 ? 0 : itr->first;
			status[i + 1][itr->first] = itr->first;
			status[i + 1][value + s[i]] = itr->first;
			status[i + 1][abs(value - s[i])] = itr->first;
		}
		if (status[i + 1].find(0) != status[i + 1].end()) {
			l1 = l2 = 0;
			int currSeq = 1, currValue = 0;
			for (int j = i + 1; j >= 1; j--) {
				int prevValue = status[j][currValue];
				//printf(" %d", prevValue);
				if (prevValue == -1) prevValue = 0;
				if (prevValue == currValue) continue;
				if (prevValue + s[j - 1] == currValue) {
					if (currSeq == 1) seq1[l1++] = s[j - 1];
					else seq2[l2++] = s[j - 1];
					currValue = prevValue;
					continue;
				}
				if (prevValue - s[j - 1] == currValue) {
					if (currSeq == 1) seq2[l2++] = s[j - 1];
					else seq1[l1++] = s[j - 1];
					currValue = prevValue;
					continue;
				}
				if (currSeq == 1) seq1[l1++] = s[j - 1];
				else seq2[l2++] = s[j - 1];
				currSeq = 3 - currSeq;
				currValue = prevValue;
			}
			//printf("\n");
			int sum1 = 0, sum2 = 0;
			for (int j = 0; j < l1; j++) {
				if (j) printf(" ");
				printf("%d", seq1[j]);
				sum1 += seq1[j];
			}
			printf("\n");
			for (int j = 0; j < l2; j++) {
				if (j) printf(" ");
				printf("%d", seq2[j]);
				sum2 += seq2[j];
			}
			printf("\n");
			//printf("%d %d\n", sum1, sum2);
			return;
		}
	}
	printf("Impossible\n");
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%d:\n", i + 1);
		Solve();
	}
	return 0;
}