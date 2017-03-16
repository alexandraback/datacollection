#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

void make_all(int m, int k, int j, int p, int s, vector<int> &S) {
	if (k >= 3) {
		S.push_back(m);
		return;
	}

	if (k == 0) {
		for(int i=1 ; i<=j ; i++)
			make_all(m + 100*i, k+1, j, p, s, S);
	}
	else if (k == 1) {
		for(int i=1 ; i<=p ; i++)
			make_all(m + 10*i, k+1, j, p, s, S);
	}
	else {
		for(int i=1 ; i<=s ; i++)
			make_all(m + i, k+1, j, p, s, S);
	}
}

void back(int r, int n, int k, vector<int> &order, map<int,int> &cnt, vector<int> &ans_order, vector<int> &S, int st) {
	if (r >= n) {
		if (order.size() > ans_order.size()) {
			ans_order = order;
		}
		return;
	}
	if (st == r) {
		back(r+1, n, k, order, cnt, ans_order, S, st);
		return;
	}

	// for(int i=r ; i<n ; i++) {
	for(int i=r ; i<=r ; i++) {
		int p1, p2, p3;
		p1 = S[i] - S[i]%10;
		p2 = (S[i]/100)*100 + S[i]%10;
		p3 = S[i] - (S[i]/100)*100;

		cnt[p1]++, cnt[p2]++, cnt[p3]++;
		if (cnt[p1] <= k && cnt[p2] <= k && cnt[p3] <= k) {
			order.push_back(S[i]);
			back(r+1, n, k, order, cnt, ans_order, S, st);
			order.pop_back();
		}
		cnt[p1]--, cnt[p2]--, cnt[p3]--;
	}

	/*
	if (n - r - 1 + (int) order.size() > ans_order.size())
		back(r + 1, n, k, order, cnt, ans_order, S);
	*/
	return;
}

void solve_small(int j, int p, int s, int k) {
	vector<int> S;
	make_all(0,0,j,p,s,S);

	int n = (int) S.size();
	vector<int> ans_order, order;
	map<int,int> cnt;

	for(int i=0 ; i<n ; i++) {
		int p1, p2, p3;
		p1 = S[i] - S[i] % 10;
		p2 = (S[i] / 100) * 100 + S[i] % 10;
		p3 = S[i] - (S[i] / 100) * 100;

		if (cnt[p1] < k && cnt[p2] < k && cnt[p3] < k) {
			cnt[p1]++, cnt[p2]++, cnt[p3]++;
			order.push_back(S[i]);
		}
	}

	ans_order = order;
	order = vector<int>();
	for(auto &iter : cnt) {
		iter.second = 0;
	}
	
	// back(0, n, k, order, cnt, ans_order, S);
	for(int i=0 ; i<n ; i++) {
		int p1, p2, p3;
		p1 = S[i] - S[i] % 10;
		p2 = (S[i] / 100) * 100 + S[i] % 10;
		p3 = S[i] - (S[i] / 100) * 100;

		if (cnt[p1] < k && cnt[p2] < k && cnt[p3] < k) {
			cnt[p1]++, cnt[p2]++, cnt[p3]++;
			order.push_back(S[i]);
			back(0, n, k, order, cnt, ans_order, S, i);
			cnt[p1]--, cnt[p2]--, cnt[p3]--;
			order.pop_back();
		}		
	}

	int ans = (int) ans_order.size();
	printf("%d\n", ans);
	for(int i=0 ; i<ans ; i++) {
		int ord = ans_order[i];
		printf("%d %d %d\n", ord/100, (ord%100)/10, ord%10);
	}

	return;
}

int main() {

	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		int j, p, s, k;
		scanf("%d%d%d%d", &j, &p, &s, &k);
		printf("Case #%d: ", tc);

		solve_small(j,p,s,k);



	}

	return 0;
}