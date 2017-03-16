#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const int MAXK = 13;
const int MAXN = 13;


int r, n, m, k;

long long need[MAXK];
bool have[MAXK];
int place[MAXN];
bool acc[MAXN];

void solve() {
	cin >> r >> n >> m >> k;
	printf("\n");
	int partsize = 400;
	FILE *fout[3] = {fopen("C_input1.txt","w")
	, fopen("C_input2.txt","w")
	, fopen("C_input3.txt","w")};

	for (int i = 0; i < 3; i++)
		fprintf(fout[i], "1\n %d %d %d %d\n", partsize, n, m, k);

	for (int i = 0; i < r; i++) {
		int part = i / partsize;
		if (part >= 3)
			break;

		for (int j = 0; j < k; j++)
			cin >> need[j];

		for (int j = 0; j < k; j++)
			fprintf(fout[part], "%d ", need[j]);
		fprintf(fout[part], "\n");
	}
	fclose(fout[0]);
	fclose(fout[1]);
	fclose(fout[2]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("C_input.txt","r", stdin);
	freopen("C_output.txt","w", stdout);
#endif
	int testnum;
	scanf("%d\n", &testnum);
	for (int i = 0; i < testnum; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
}
