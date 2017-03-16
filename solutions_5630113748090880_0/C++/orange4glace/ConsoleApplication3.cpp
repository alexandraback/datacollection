#include "stdafx.h"
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

#define INF 300000000
#define LLINF 10000000000000LL
#define MOD 1000000000LL
#define cout cout
#define cin cin
typedef long long ll;

int Q, N, M, K, L;
int check[2501];

int main() {
	ifstream in("B-small-attempt0.in");
	ofstream out("out.txt");
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());

	cin >> Q;
	for (int qq = 0; qq < Q; qq++) {
		cin >> N;
		for (int i = 0; i < 2501; i++) check[i] = 0;
		for (int i = 0; i < 2 * N - 1; i++) {
			for (int j = 0; j < N; j++) {
				int a;
				cin >> a;
				check[a] ++;
			}
		}
		vector<int> resl;
		for (int i = 0; i < 2501; i++)
			if (check[i] % 2 == 1) resl.push_back(i);
		sort(resl.begin(), resl.end());
		cout << "Case #" << qq + 1 << ": ";
		for (int i = 0; i < resl.size(); i++)
			cout << resl[i] << " ";
		cout << "\n";
	}

	return 0;
}