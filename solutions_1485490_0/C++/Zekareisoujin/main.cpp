#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define NMAX 100
typedef long long ll;
typedef pair<int, ll> rem;
typedef pair<ll, int> tup;

map<rem, ll> rmb[NMAX][NMAX];
tup	q1[NMAX];
tup q2[NMAX];
rem zero = make_pair(0, 0);

int n, m;

ll dp(int idx1, int idx2, rem leftOver){
	if (idx1 >= n)
		return 0;
	if (idx2 >= m)
		return 0;
	if (rmb[idx1][idx2].find(leftOver) != rmb[idx1][idx2].end())
		return rmb[idx1][idx2][leftOver];
	else {
		ll sumMax = 0;
		int remType = leftOver.first;
		int type1 = q1[idx1].second;
		int type2 = q2[idx2].second;
		ll qty1, qty2;

		if (remType == 0){
			sumMax = max(sumMax, dp(idx1+1, idx2, zero));
			sumMax = max(sumMax, dp(idx1, idx2+1, zero));
			qty1 = q1[idx1].first;
			qty2 = q2[idx2].first;
		}else if (remType == 1){
			sumMax = max(sumMax, dp(idx1+1, idx2, zero));
			sumMax = max(sumMax, dp(idx1, idx2+1, leftOver));
			qty1 = leftOver.second;
			qty2 = q2[idx2].first;
		}else if (remType == 2){
			sumMax = max(sumMax, dp(idx1+1, idx2, leftOver));
			sumMax = max(sumMax, dp(idx1, idx2+1, zero));
			qty1 = q1[idx1].first;
			qty2 = leftOver.second;
		}

		//printf("%d %d %d %d\n", qty1, type1, qty2, type2);
		/*if (type1 == type2){
			ll add = min(qty1, qty2);
			if (qty1 > add)
				sumMax = max(sumMax, add + dp(idx1, idx2+1, make_pair(1, qty1-add)));
			else if (qty2 > add)
				sumMax = max(sumMax, add + dp(idx1+1, idx2, make_pair(2, qty2-add)));
			else
				sumMax = max(sumMax, add + dp(idx1+1, idx2+1, zero));
		}*/
		/*if (type1 == type2){
			ll add = min(qty1, qty2);
			if (qty1 > add){
				for (int i=idx2+1; i<m; i++)
					if (q2[i].second == type1)
						sumMax = max(sumMax, add + dp(idx1, i, make_pair(1, qty1-add)));
			}else if (qty2 > add){
				for (int i=idx1+1; i<n; i++)
					if (q1[i].second == type2)
						sumMax = max(sumMax, add + dp(i, idx2, make_pair(2, qty1-add)));
			}
			sumMax = max(sumMax, add + dp(idx1+1, idx2+1, zero));
		}*/
		if (type1 == type2){
			ll add;

			ll nqty1 = qty1;
			ll nqty2 = qty2;
			for (int i=idx1+1; i<n; i++){
				if (q1[i].second == type1)
					nqty1 += q1[i].first;
				for (int j=idx2+1; j<m; j++){
					if (q2[j].second == type1){
						nqty2 += q2[j].first;
						add = min(nqty1, nqty2);
						sumMax = max(sumMax, add + dp(i+1, j+1, zero));
					}
				}
			}

			nqty1 = qty1; nqty2 = qty2;
			for (int i=idx2+1; i<m; i++){
				if (q2[i].second == type1)
					nqty2 += q2[i].first;
				for (int j=idx1+1; j<n; j++){
					if (q1[j].second == type1){
						nqty1 += q1[j].first;
						add = min(nqty1, nqty2);
						sumMax = max(sumMax, add + dp(j+1, i+1, zero));
					}
				}
			}

			add = min(qty1, qty2);
			sumMax = max(sumMax, add + dp(idx1+1, idx2+1, zero));
		}

		rmb[idx1][idx2][leftOver] = sumMax;
		return sumMax;
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int tci=0; tci<tc; tci++){
		cin >> n >> m;
		ll a;
		int b;
		for (int i=0; i<n; i++){
			cin >> a >> b;
			q1[i] = make_pair(a, b);
		}
		for (int i=0; i<m; i++){
			cin >> a >> b;
			q2[i] = make_pair(a, b);
		}
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				rmb[i][j].clear();
		
		printf("Case #%d: %lld\n", tci+1, dp(0, 0, zero));
	}
}