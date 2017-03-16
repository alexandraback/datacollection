#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <list>
using namespace std;

typedef long long i64;
#define mp make_pair
#define pb push_back
#define ppb pop_back
const double EPS = 1e-6;
const int INF = ~(1 << 31);

i64 gcd(i64 a, i64 b, i64 &x, i64 &y){
	if(a == 0){
		x = 0;
		y = 1;
		return b;
	}
	i64 x1, y1;
	i64 g = gcd(b % a, a, x1, y1);
	x = y1 - b / a * x1;
	y = x1;
	return g;
}

int euler(int n){
	int res = n;
	int c = 0;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			while(n % i == 0) {
				n /= i;
			}
			res -= res / i;	
		}
	}
	if(n > 1) {
		res -= res / n;
	}
	return res;
}

int div(int n){
	int res = 0;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0) res++;
		if(n / i && i != n / i && n % (n / i) == 0) res++;
	}
	return res;
}

int divSum(int n){
	int res = 0, cnt = 0, m = n;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			cnt++;
			int tmp = 1;
			while(n % i == 0){
				tmp *= i;
				n /= i;
			}
			res += tmp;
		}
	}
	if(cnt == 0) return n + 1;
	if(n > 1) res += n;
	if(cnt == 1 && n == 1) return m + 1;
	
	return res;
}

i64 merge(vector<int> &v, int l, int r){
	int m = (l + r) / 2;
	i64 cnt = 0;
	vector<int> buf(r - l + 1);
	int posl = l, posbuf = 0, posr = m + 1;
	while(posl <= m && posr <= r){
		if(v[posl] > v[posr]){
			buf[posbuf++] = v[posr++];
			cnt += m - posl + 1;
		}else buf[posbuf++] = v[posl++];
	}
	while(posl <= m) buf[posbuf++] = v[posl++];
	while(posr <= r) buf[posbuf++] = v[posr++];
	copy(buf.begin(), buf.end(), v.begin() + l);
	return cnt;
}

i64 mergeSort(vector<int> & v, int l, int r){
	i64 cnt = 0;
	if(l == r){
		return 0;
	}
	cnt += mergeSort(v, l, (l + r) / 2);
	cnt += mergeSort(v, (l + r) / 2 + 1, r);
	cnt += merge(v, l, r);
	return cnt;
}


int t;
int n, a, tmp;
vector<vector<int> > g;
vector<char> used;
bool found = false;

void dfs(int v){
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		if(used[g[v][i]] == 1){
			found = true;
			return;
		}
		else dfs(g[v][i]);
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	
	scanf("%d", &t);
	for(int cnt = 1; cnt <= t; cnt++){
		scanf("%d", &n);
		g.assign(n, vector<int>());
		used.assign(n, 0);
		for(int i = 0; i < n; i++){
			scanf("%d", &a);
			for(int j = 0; j < a; j++){
				scanf("%d", &tmp);
				g[i].pb(tmp - 1);
			}
		}
		bool gotta = false;
		for(int i = 0; i < n; i++){
			used.assign(n, 0);
			found = false;
			dfs(i);
			if(found){
				printf("Case #%d: Yes\n", cnt);
				gotta = true;
				break;
			}
			
		}
		if(!gotta) printf("Case #%d: No\n", cnt);
	}
	return 0;
}