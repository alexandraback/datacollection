#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,n)
#define LL long long
int n, m;
LL A;
int a[1001];
struct node{
	LL a, lo, hi, b;
	node(int s, int d, int f, int g):a(s), lo(d), hi(f), b(g){}
	bool operator < (node p) const{
		return b >= p.b;
	}
};
priority_queue <node> q;
int main(){
	int T;
	scanf("%d", &T);
	FOE(cc,1,T){
		int ans = 1111, tmp = 0;
		scanf("%lld%d", &A, &n);
		FOR(i,0,n) scanf("%d", a + i);
		while(!q.empty()) q.pop();
		/*
		if (A == 1){
			printf("Case #%d: %d\n", cc, n);
			continue;
		}
		*/
		sort(a, a + n);
		q.push(node(A, 0, n, 0));
		while(!q.empty()){
			node cur = q.top(); q.pop();
			int x = cur.a, lo = cur.lo, hi = cur.hi, b = cur.b;
			if (lo == hi){
				ans = b;
				break;
			}
			if (x > a[lo]){
				q.push(node(x + a[lo], lo + 1, hi, b));
			}
			else{
				q.push(node(x + x - 1, lo, hi, b + 1));
				q.push(node(x, lo, hi - 1, b + 1));
			}
		}
		printf("Case #%d: %d\n", cc, ans);
	}
	return 0;
}

