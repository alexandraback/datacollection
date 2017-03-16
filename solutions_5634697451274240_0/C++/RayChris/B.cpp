#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

#define PQ priority_queue
typedef long long LL;
typedef pair<LL,LL> pll;

int ans[1<<10],N;
bool chk[1<<10];

void bfs() {
	int n = (1<<N)-1,tmp,dig[10];
	queue<int> Q;
	Q.push(n);
	chk[n] = true;
	ans[n] = 0;
	while (!Q.empty()) {
		// flip from 0 to i
		n = Q.front();
		Q.pop();
		//cout << n << " " << ans[n] << endl;
		int val = n;
		for (int i=0;i<N;i++) {
			dig[N-1-i] = n%2;
			n /= 2;
		}
		for (int i=0;i<N;i++) {
			tmp = 0;
			for (int j=0;j<=i;j++)
				if (dig[i-j]==0)
					tmp += 1<<(N-1-j);
			for (int j=i+1;j<N;j++)
				if (dig[j]==1)
					tmp += 1<<(N-1-j);
			if (!chk[tmp]) {
				ans[tmp] = ans[val]+1;
				chk[tmp] = true;
				Q.push(tmp);
			}
		}
	}
}

void init_ans() {
	for (int i=0;i<(1<<10);i++)
		chk[i] = false;
}

int main() {
	int T,n;
	ifstream file_in ("B-small-attempt0.in");
	ofstream file_out ("B-small.txt");
	file_in >> T;
	string s;
	getline(file_in,s);
	for (int i=0;i<T;i++) {
		getline(file_in,s);
		N = (int) s.length();
		n = 0;
		for (int j=0;j<(int) s.length();j++) {
			n *= 2;
			if (s[j]=='+') n += 1;
		}
		init_ans();
		bfs();
		file_out << "Case #" << i+1 << ": " << ans[n] << endl;
	}
	return 0;

}
