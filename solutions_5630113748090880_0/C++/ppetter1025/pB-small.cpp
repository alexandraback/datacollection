#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN = 20 + 5;

int n;
int a[MAXN][MAXN], b[MAXN][MAXN];
bool u0[MAXN], u1[MAXN];
VI v;

bool find(int num) {
	for(int i=0; i<n; i++) {
		if(u0[i])	continue;
		bool flag = true;
		for(int j=0; j<n; j++) if(a[num][j] != b[i][j])	flag = false;
		if(flag) {
			u0[i] = true;
			return true;
		}
	}
	for(int j=0; j<n; j++) {
		if(u1[j])	continue;
		bool flag = true;
		for(int i=0; i<n; i++) if(a[num][i] != b[i][j])	flag = false;
		if(flag) {
			u1[j] = true;
			return true;
		}
	}

	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++) {
		scanf("%d", &n);
		for(int i=0; i<n*2-1; i++)
			for(int j=0; j<n; j++)	scanf("%d", a[i]+j);

		for(int i=0; i<n*2-1; i++) {
			for(int j=i+1; j<n*2-1; j++) {
				if(a[i][0] > a[j][0]) {
					for(int k=0; k<n; k++)	swap(a[i][k], a[j][k]);
				}
			}
		}
		
		bool find_ans = false;
		fill(u0, u0+n, false);
		fill(u1, u1+n, false);
		for(int i=0; i<(1<<(2*n-1)); i++) {
			fill(u0, u0+n, false);
			fill(u1, u1+n, false);
			v.clear();
			for(int j=0; j<2*n-1; j++) {
				if((i>>j)&1)	v.PB(j);
			}
			if(SZ(v) != n)	continue;
			
			for(int x=0; x<n; x++) {
				for(int y=0; y<n; y++)	b[x][y] = a[v[x]][y];
			}

			bool flag = false;
			fill(u0, u0+n, false);
			fill(u1, u1+n, false);
			for(int j=0; j<n*2-1; j++)
				if(!find(j))	flag = true;
			if(flag)	continue;

			printf("Case #%d: ", kase);
			for(int x=0; x<n; x++) {
				if(!u0[x]) {
					for(int y=0; y<n; y++)	printf("%d%c", b[x][y], " \n"[y==n-1]);
				}
			}
			for(int x=0; x<n; x++) {
				if(!u1[x]) {
					for(int y=0; y<n; y++)	printf("%d%c", b[y][x], " \n"[y==n-1]);
				}
			}
			find_ans = true;
			break;
		}

		for(int i=0; !find_ans&&i<(1<<(2*n-1)); i++) {
			fill(u0, u0+n, false);
			fill(u1, u1+n, false);
			v.clear();
			for(int j=0; j<2*n-1; j++) {
				if((i>>j)&1)	v.PB(j);
			}
			if(SZ(v) != n)	continue;
			
			for(int x=0; x<n; x++) {
				for(int y=0; y<n; y++)	b[y][x] = a[v[x]][y];
			}

			bool flag = false;
			fill(u0, u0+n, false);
			fill(u1, u1+n, false);
			for(int j=0; j<n*2-1; j++)
				if(!find(j))	flag = true;
			if(flag)	continue;

			printf("Case #%d: ", kase);
			for(int x=0; x<n; x++) {
				if(!u0[x]) {
					for(int y=0; y<n; y++)	printf("%d%c", b[x][y], " \n"[y==n-1]);
				}
			}
			for(int x=0; x<n; x++) {
				if(!u1[x]) {
					for(int y=0; y<n; y++)	printf("%d%c", b[y][x], " \n"[y==n-1]);
				}
			}
			break;
		}
	}
    
    return 0;
}
