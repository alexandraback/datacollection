#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int N = 1e7 + 11;
const int oo = 0x3f3f3f3f;
int d[N], inq[N];
int inv(int x){
	int r = 0;
	while(x){
		r = r*10 + x%10;
		x /= 10;
	}
	return r;
}
int spfa(int n){
	memset(d, 0x3f, sizeof(int)*N);
	memset(inq, 0, sizeof(int)*N);
	queue<int> Q;
	d[1] = 1;
	Q.push(1);
	inq[1] = 1;
	int u, v;
	while(!Q.empty()){
		u = Q.front();
		if(u==n)	break;
		Q.pop();
		inq[u] = 0;
		int t[2];
		t[0] = u+1;
		t[1] = inv(u);
		for(int i=0; i<2; i++){
			v = t[i];
			if(d[u]+1 < d[v]){
				d[v] = d[u]+1;
				if(inq[v]==0){
					Q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
	return d[n];
}
int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("A-small-attempt0.in", "r", stdin);
	// freopen("A-large.in", "r", stdin);
	// freopen("ou.txt", "w", stdout);
	int t, kase=0;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", ++kase, spfa(n));
	}
	return 0;
}