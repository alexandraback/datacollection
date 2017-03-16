#include <cstdio>
#include <map>
#include <vector>
using namespace std;
#define MAX 23
static map<int, vector <int> > M; 
static int v[MAX];
static bool tem;
void solve(int n) {
	vector<int> w, p;
	for(int i = 0; i < (1<<n); i++){
		int sum = 0;
		w.clear();
		for( int j = n - 1; j >= 0; j-- ) {
			if (i &(1<<j)) {
				w.push_back(v[j]);
				sum += v[j];
			}
		}
		if (M.find(sum) == M.end()) 
			M[sum] = w;
		else {
			tem = true;
			p = M[sum];
			int mp = p.size(), mw = w.size();
			for (int k = 0; k != mp; k++) 
				printf("%d%c", p[k], k == mp-1 ? '\n' : ' ');
			for (int k = 0; k != mw; k++) 
				printf("%d%c", w[k], k == mw-1 ? '\n' : ' ');
			return;
		}
	}
}


int main () {
	int t, s;
	scanf("%d", &t);
	for (int i = 0; i != t; i++)  {
		scanf("%d", &s);
		M.clear();
		for (int j = 0; j != s; j++) 
			scanf("%d", &v[j]);
		printf("Case #%d:\n", i+1);
		tem = false;
		solve(s);
		if (!tem) puts("Impossible");
	}
	return 0;
}
