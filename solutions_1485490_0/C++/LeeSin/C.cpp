#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#define N 105
#define M 1000005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
using namespace std;
typedef long long LL;

int t, n, m, A[N], B[N];
LL a[N], b[N], ans;
struct nod{
	int x, y;
	LL a, b;
	nod(){}
	nod(int x, int y, LL a, LL b) : x(x), y(y), a(a), b(b){}
	bool operator < (const nod &T) const { return x != T.x ? x < T.x : (y != T.y ? y < T.y : (a != T.a ? a < T.a : b < T.b));}
};
struct node{
	int x, y;
	LL a, b, d;
	node(){}
	node(int x, int y, LL a, LL b, LL d) : x(x), y(y), a(a), b(b), d(d){}
	bool operator < (const node &b) const { return d > b.d;}
};
map<nod, LL> d;
map<nod, LL>::iterator it;
priority_queue<node> q;

void print(node x){
	printf("node %d %d %I64d %I64d %I64d\n", x.x, x.y, x.a, x.b, x.d);
}

void push(int x, int y, LL aa, LL bb, LL dd){
	if(x > n || y > m || d.find(nod(x, y, aa, bb)) != d.end() && d[nod(x, y, aa, bb)] >= dd) return;
	d[nod(x, y, aa, bb)] = dd;
	q.push(node(x, y, aa, bb, dd));
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-out.txt", "w", stdout);
	scanf("%d", &t);
	
	FI(z, 1, t){
		ans = 0;
		scanf("%d %d", &n, &m);
		
		FI(i, 1, n) scanf("%I64d %d", &a[i], &A[i]);
		FI(i, 1, m) scanf("%I64d %d", &b[i], &B[i]);
		
		d.clear();
		push(0, 0, 0, 0, 0);
		
		while(q.size()){
			int x = q.top().x, y = q.top().y;
			LL aa = q.top().a, bb = q.top().b, ds = q.top().d;
	//		print(q.top());
			q.pop();
			
			if(ds < d[nod(x, y, aa, bb)]) continue;
			
			if(!aa) push(x + 1, y, a[x + 1], bb, ds);
			
			if(!bb) push(x, y + 1, aa, b[y + 1], ds);
			
			if(A[x] != B[y]){
				push(x, y, 0, bb, ds);
				push(x, y, aa, 0, ds);
			}else{
				LL mm = min(aa, bb);
				push(x, y, aa - mm, bb - mm, ds + mm);
			}
		}
		
		for(it = d.begin(); it != d.end(); it++) ans = max(ans, it->second);
		
		printf("Case #%d: %I64d\n", z, ans);
	}
	
	scanf("\n");
	
}
