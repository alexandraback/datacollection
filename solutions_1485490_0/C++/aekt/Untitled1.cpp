#include <cstdio>
#include <stack>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int tc, n, m;
struct box{ long long p, q; } temp;
stack<box> A, B;

long long r(stack<box>A, stack<box> B){
	while(!A.empty() && !A.top().p) A.pop();
	while(!B.empty() && !B.top().p) B.pop();
	if (A.empty() || B.empty()) return 0;
	long long d, e;
	if (A.top().q == B.top().q){
		d = min(A.top().p, B.top().p);
		A.top().p -= d;
		B.top().p -= d;
		return r(A, B) + d;
	}else{
		box temq = A.top();
		A.pop();
		d = r(A, B);
		A.push(temq);
		temq = B.top();
		B.pop();
		e = r(A, B);
		return max(d, e);
	}
}

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &tc);
	for(int ct = 1; ct <= tc; ct++){
		scanf("%d%d", &n, &m);
		while(!A.empty()) A.pop();
		while(!B.empty()) B.pop();
		for(int i = 0; i < n; i++){
			scanf("%I64d%I64d", &temp.p, &temp.q);
			A.push(temp);
		}
		for(int j = 0; j < m; j++){
			scanf("%I64d%I64d", &temp.p, &temp.q);
			B.push(temp);
		}
		printf("Case #%d: %I64d\n", ct, r(A, B));
	}
	return 0;
}
