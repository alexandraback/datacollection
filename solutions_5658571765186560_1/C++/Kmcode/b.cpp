#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<valarray>
using namespace std;
int t;
int x;
int r;
int c;
int a[5][5];
int m = 0;
int cnt(int a){
	int countt = 0;
	while (a){
		if ((a & 1)){
			countt++;
		}
		a >>= 1;
	}
	return countt;
}
bool use[5][5];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int cc = 0;
inline void dfs(int A, int b){
	use[A][b] = true;
	cc++;
	for (int i = 0; i < 4; i++){
		int aa = A + dx[i];
		int bb = b + dy[i];
		if (aa >= 0 && bb >= 0 && aa < x&&bb < x){
			if (a[aa][bb] && use[aa][bb] == false){
				dfs(aa, bb);
			}
		}
	}
}
bool ng = false;
void solve(){
	if (r > x){
		return;
	}
	if (r == x){
		for (int l = 0; l < c; l++){
			if (l + 1 > c){
				break;
			}
			if ((l*r) % x){
				ng = true;
				return;
			}
			if ((r*(c - l - 1)) % x){
				ng = true;
				return;
			}
		}
		return;
	}
	int len = min(x, c);
	for (int i = 1; i <= len; i++){
		int maxt = r*i;
		for (int j = 0; j <= maxt; j++){
			if (j + x>maxt){
				break;
			}
			int need = 0;
			if (j%r){
				need++;
			}
			need += r;
			need += i;
			need--;
			if (j%r){
				need--;
			}
			if (need > x){
				continue;
			}
			if (c > r&&r > i){
				continue;
			}
			int k = maxt - x - j;
			bool oo = false;
			for (int l = 0; l < c; l++){
				if (l + i > c){
					break;
				}
				int lef = l*r + j;
				int ri = (c - (i + l))*r + k;
				if (lef%x){
					continue;
				}
				if (ri%x){
					continue;
				}
				oo = true;
				break;
			}
			if (oo == false){
				ng = true;
				return;
			}
		}
	}
}
int main(){
	scanf("%d", &t);
	int rr = 0;
	while (t--){
		rr++;
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: ", rr);
		if (x > r&&x > c){
			puts("RICHARD");
			continue;
		}
		if ((r*c) % x){
			puts("RICHARD");
			continue;
		}
		if (x > (r*c)){
			puts("RICHARD");
			continue;
		}
		if (x > (r*r) + 1){
			puts("RICHARD");
			continue;
		}
		if (x > (c*c) + 1){
			puts("RICHARD");
			continue;
		}
		ng = false;
		solve();
		if (ng){
			puts("RICHARD");
			continue;
		}
		swap(r, c);
		solve();
		if (ng){
			puts("RICHARD");
		}
		else{
			puts("GABRIEL");
		}
	}
	return 0;
}