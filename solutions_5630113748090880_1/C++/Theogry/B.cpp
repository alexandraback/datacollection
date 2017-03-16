#include <bits/stdc++.h>

#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)

using namespace std;

int n;

vector<int> a[61];
vector<int> b[61][5];
int ok[61][5], pre[61][5];
int cnt[61];

bool cmp(vector<int> A, vector<int> B){
	FOR(i, 0, A.size()){
		if (A[i] > B[i]) return false;
		if (A[i] < B[i]) return true;
	}
	return true;
}

bool fulfil(vector<int> A, vector<int> B){
	FOR(i, 0, A.size()){
		if (A[i] >= B[i]) return false;
	}
	return true;
}

int res[6001];

void solve(){
	scanf("%d", &n);
	FOE(i, 1, 2 * n - 1){
		a[i].clear();
		FOE(j, 1, n){
			int x; scanf("%d", &x);
			a[i].push_back(x);
		}
	}
	
	sort(a + 1, a + (2 * n + 1) + 1);
	
	int now = 1;
	int miss;
	FOE(i, 1, n) cnt[i] = 0;
	FOE(i, 1, 2 * n - 1){
		int id = a[i][0];
		cnt[id]++;
		
		b[id][cnt[id]] = a[i];
	}
	
	FOE(i, 1, n) if (cnt[i] == 1) miss = i;
	FOE(i, 1, n) ok[i][1] = ok[i][2] = 0;
	
	FOE(i, 1, n){
		if (i == 1){
			ok[i][1] = ok[i][2] = 1;
			pre[i][1] = pre[i][2] = -1;	
		} else {
			FOE(c1, 1, 2) FOE(c2, 1, 2) if (cnt[i] >= c1 && cnt[i - 1] >= c2 && ok[i - 1][c2] && 
				fulfil(b[i][c1], b[i - 1][c2])){
				ok[i][c1] = 1;
				pre[i][c1] = c2;
			} 
		}
	}
	
	int tar = (ok[n][1]? 1: 2);
	FOD(i, n, 1){
		res[i] = b[i][tar][miss - 1];
		tar = pre[i][tar];
	}	
	
	FOE(i, 1, n) printf(" %d", res[i]);
	puts("");
}

int main(){
//	freopen("A-L.in", "r", stdin);
//	freopen("A-L.out", "w", stdout);
	int tc; scanf("%d", &tc);
	FOE(i, 1, tc){
		printf("Case #%d:", i);
		solve();
	}
	return 0;
}
