#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <deque>
#include <cstdio>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<double> vd;
template<class T> void pr(T a, T b) { for(T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

const int N = 109;
int a[N][N];
int cov[N][N];

struct field {
	int val;
	int x;
	int y;
	field(int val, int x, int y):val(val), x(x), y(y){}
	bool operator < (const field & r) const {
		return val < r.val;
	}
};
vector<field> v;

bool cover_column(int x, int y, int n, int m){
	for(int i = 0; i < n; ++i){
		if(a[i][y] > a[x][y]) return false;
	}
	for(int i = 0; i < n; ++i){
		cov[i][y] = 1;
	}
	return true;
}
bool cover_row(int x, int y, int n, int m){
	for(int j = 0; j < m; ++j){
		if(a[x][j] > a[x][y]) return false;
	}
	for(int j = 0; j < m; ++j){
		cov[x][j] = 1;
	}
	return true;
}

bool cover(int x, int y, int n, int m){
	if(cov[x][y]) return true;
	if(cover_row(x, y, n, m)) return true;
	if(cover_column(x, y, n, m)) return true;
	return false;
}

void dupa(){
	int n, m;
	scanf("%d%d", &n, &m);
//	printf("\n");
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &a[i][j]);
			v.push_back(field(a[i][j], i, j));
//			printf("%d" , a[i][j]);
			cov[i][j] = 0;
		}
//		printf("\n");
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); ++i){
		if(!cover(v[i].x, v[i].y, n, m)){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main(){
	int z;
	scanf("%d", &z);
	for(int i = 0; i < z; ++i){
		cout << "Case #" << i+1 << ": ";
		dupa();
		v.clear();
	}
}
