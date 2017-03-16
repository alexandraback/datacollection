#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i = a; i < (b); ++i)
#define rep(i, n) fr(i,0,n)
#define _(n) rep(i, n)
#define mp make_pair
#define ft first
#define sd second
#define pb push_back
#define SZ(x) int(x.size())
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long hash;
int n, m;
#define get kjsdhf
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int tmp[30][30];
int get(int a, int b){
	return tmp[a][b];
	return 1 << (a * m + b);
}

void dfs(int i, int j, int& msk){
	if(msk & (1<<get(i,j))) return;
	msk |= 1 << get(i, j);

	rep(d, 4){
		int ni = i + dx[d], nj = j + dy[d];
		if(ni >= 0 && ni < n && nj >= 0 && nj < m){
			dfs(ni, nj, msk);
		}
	}
}

vector<int> masks[30];

int count(int msk){
	int cnt = 0;
	while(msk) ++cnt, msk -= msk & -msk;
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;	

	fr(tt, 1, 1+t){
		int k;
		cin >> n >> m >> k;
		int h = 0;
		rep(i, n) rep(j, m) tmp[i][j] = h++;

		_(30) masks[i].clear();

		_(1<<(n*m)) masks[count(i)].pb(i);

		int best = k;
		rep(tam, k){

			rep(x, SZ(masks[tam])){
				int msk = masks[tam][x];

				rep(j, m) if(!((1 << get(0, j)) & msk)) dfs(0, j, msk);
				rep(j, m) if(!((1<<get(n-1, j)) & msk)) dfs(n-1, j, msk);

				fr(i, 1, n-1) if(!((1<< get(i, 0)) & msk)) dfs(i, 0, msk);
				fr(i, 1, n-1) if(!((1<< get(i, m-1)) & msk)) dfs(i, m-1, msk);

				if(n*m - (count(msk) - tam) >= k){
					best = tam;
					break;
				}
			}
			if(best == tam) break;
		}

		cout << "Case #" << tt << ": " << best << "\n";


	}
}

