//#pragma comment(linker,"/STACK:102400000,102400000")
//#include <cstdio>
//#include <vector>
//#include <cmath>
//#include <queue>
//#include <set>
//#include <map>
//#include <cstring>
//#include <string>
//#include <iostream>
//#include <time.h>
//#include <algorithm>
//using namespace std;
//typedef pair<int, int> pii;
//#define INF 0x7fffffff 
//#define mod 1000000007
//#define ftmp 1000000000
//#define llu unsigned long long 
//#define ll long long
//#define maxn 1005
//#define pi acos(-1.0)
//#define dis(x0, y0, x1, y1) sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1))
//ll gcd(ll n, ll m){ return m ? gcd(m, n%m) : n; }
////struct node{int x, y;}b[maxn];
////bool comp(node a, node b){ return (a.x < b.x || a.x == b.x&&a.y < b.y); }
//int n, m, k, ans, y, s;
//char str[maxn];
//double a[maxn][maxn];
//double t,p,dans;
//int w[maxn],x[maxn];
//struct node{
//	double v;
//	int c;
//}dp[maxn][129][11];
//int main(){
//	while (scanf("%d%d",&n,&m)&&n){
//		int flag = 1;
//		for (int i = 1; i <= n; i++){
//			scanf("%lf%lf%lf%lf%lf%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &x[i], &w[i]);
//		}
//		p = m;
//		dp[0][m][0].x = 0;
//		for (int i = 1; i <= n; i++){
//			for (int j = 100; j >= 0; j--){
//				dp[i][j][ma] = min(dp[i][j][ma], dp[i - 1][j][ma] + t);
//				for (int k = 0; k <= ma+w[i]; k++){
//					dp[i][j + x[i]][ma] = min(dp[i][j + x[i]][ma], dp[i][j][ma]);
//					dp[i][j << k][ma - k] = min(dp[i][j << k][ma - k], dp[i][j][ma]);
//				}
//			}
//		}
//		dans = INF;
//		for (int i = 0; i <= 100; i++)
//			for (int j = 0; j <= 10; j++)dans = min(dans, dp[n][i][j]);
//		if (flag)printf("%.2lf\n", dans);
//		else printf("Impossible\n");
//	}
//	return 0;
//}
//
//#pragma comment(linker,"/STACK:102400000,102400000")
//#include <cstdio>
//#include <vector>
//#include <cmath>
//#include <queue>
//#include <set>
//#include <map>
//#include <cstring>
//#include <string>
//#include <iostream>
//#include <time.h>
//#include <algorithm>
//using namespace std;
//typedef pair<int, int> pii;
//#define INF 0x7fffffff 
//#define mod 1000000007
//#define ftmp 1000000000
//#define llu unsigned long long 
//#define ll long long
//#define maxn 1005
//int n, m, ans;
//int a[maxn], b[maxn], c[maxn];
//void bfs(int u){
//	queue<int>q;
//	q.push(u);
//	while (!q.empty()){
//		int u = q.front(); q.pop();
//		for (int i = 0; i < n; i++){
//
//		}
//	}
//}
//int main(){
//	while (~scanf("%d", &n)){
//		for (int i = 0; i < n; i++){
//			scanf("%d%d%d", &a[i], &b[i], &c[i]);
//		}
//		bfs();
//		if (ans)printf("NO\n");
//		else printf("%d\n", ans);
//	}
//	return 0;
//}


//
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <map>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//#define ll long long
//#define maxn 1055
//int n, m, s, k, t, sz;
//int a[maxn],val[maxn*maxn],pos[maxn];
//char str[maxn][16];
//char op[16];
//char ch[maxn*maxn][26];
//void insert(char *str, int v){
//	int len = strlen(str), u = 0;
//	for (int i = 0; i < len; i++){
//		int c = str[i] - 'a';
//		if (!ch[u][c]){
//			ch[u][c] = sz++;
//		}
//		u = ch[u][c];
//	}
//	val[u] = v;
//}
//void search(char *str){
//	int len = strlen(str), u = 0, flag = 1;
//	for (int i = 0; i < len; i++){
//		int c = str[i] - 'a';
//		if (!ch[u][c]){
//			flag = 0; break;
//		}
//		else{
//			u = ch[u][c];
//		}
//	}
//}
//int main(){
//	sz = 1;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++){ scanf("%s%d", str[i], a[i]); insert(str[i], a[i]); pos[i] = i; }
//	scanf("%d", &m);
//	while (m--){
//		scanf("%s", op);
//		search(op);
//	}
//	return 0;
//}


//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//#define maxn 1005
//int n, m, x;
//struct node{
//	int l, r, pos, v;
//}a[maxn];
//int cmp(node a, node b){
//	if (a.l != b.l)return a.l < b.l;
//	return a.r < b.r;
//}
//int main(){
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++){
//		scanf("%d%d", &a[i].l, &x);
//		a[i].r = a[i].l + x - 1;
//		a[i].pos = i;
//	}
//	sort(a, a + n, cmp);
//	return 0;
//}



//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <map>
//#include <stack>
//#include <algorithm>
//#include <vector>
//#include <iostream>
//#include <functional>
//using namespace std;
//#define ll long long
//#define INF 0x7fffffff
//#define mod 1000000007
//#define maxn 300055
//int n, m, k, c, s, t, id, ans;
//int a[maxn],d[maxn];
//int nxt[maxn], head[maxn], edges[maxn], q[maxn], vals[maxn],flow[maxn],cap[maxn];
//void add(int u, int v,int val){
//	vals[id] = val; edges[id] = v; nxt[id] = head[u]; head[u] = id++;
//}
//int bfs(int u){
//	for (int i = 0; i <= n; i++)d[i] = INF;
//	int hd = 0, tl = 0;
//	while (hd <= tl){
//		int u = q[hd++];
//		for (int i = head[u]; i != -1; i = nxt[i]){
//			int v = edges[i];
//			if (d[v] > d[u] + 1){
//				d[v] = d[u] + 1;
//				q[tl++] = v;
//			}
//		}
//	}
//	return d[t];
//}
//int dfs(int u,int pre){
//	if (u == t)return 1;
//	for (int i = head[u]; i != -1; i = nxt[i]){
//		x = max(x, cap[v]-flow[v]);
//	}
//	for (int i = head[u]; i != -1; i = nxt[i]){
//		if (lv[v] != lv[u] + 1)continue;
//		int v = edges[i];
//		if (v == pre||f[v]==cap[v])continue;
//		if (flow[v] == x){
//			if (v != pre)x = dfs(v, u);
//		}
//	}
//	return y;
//}
//int dinic(){
//	while (bfs()){
//		f = dfs();
//		ans += f;
//		if (f == 0)break;
//	}
//	return ans;
//}
//struct node{
//	int l, r, pos, v;
//}p[maxn];
//int main(){
//	scanf("%d%d", &n, &m);
//	for (int i = 1; i <= n; i++){
//		scanf("%d%d", &p[i].l, &c);
//		p[i].r = p[i].l + c - 1;
//		mi = min(mi, p[i].l);
//		ma = max(ma, p[i].r);
//	}
//	t = 0;
//	ma -= mi-1;
//	t = ma;
//	for (int i = 1; i <= n; i++){
//		p[i].l -= mi-1;
//		p[i].r -= mi-1;
//	}
//	for (int i = 1; i <= ma; i++)add(0, i, k);
//	for (int i = 1; i <= n; i++){
//		for (int j = p[i].l; j <= p[i].r; j++){
//			add(j,t+i,1);
//		}
//	}
//	for (int i = t + 1; i <= t + n; i++){
//		add(i, t + n + 1, 2);
//	}
//	t = t + n + 1;
//	int flag = dinic();
//	if (flag==2*n){
//		printf("YES\n");
//		for (int i = t - n; i <= t - 1; i++){
//			printf("%d %d\n", x, y);
//		}
//	}
//	else printf("NO\n");
//	return 0;
//}


//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <map>
//#include <stack>
//#include <algorithm>
//#include <vector>
//#include <iostream>
//#include <functional>
//using namespace std;
//#define ll long long
//#define INF 0x7fffffff
//#define mod 1000000007
//#define maxn 1055
//int n, m, k, s, t;
//int a[maxn];
//char str[maxn][maxn];
//int main(){
//	//freopen("in.txt","r",stdin);
//	//freopen("out.txt","w",stdout);
//	scanf("%d", &t);
//	int cas = 1;
//	while (t--){
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++){
//			scanf("%s", str[i]);
//
//		}
//		for (int i = 0; i < n; i++){
//			if (str[i])
//		}
//		printf("Case #%d: ", cas++);
//		printf("%d\n", s);
//	}
//	return 0;
//}



#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
#define ll long long
#define INF 0x7fffffff
#define mod 1000000007
#define maxn 1055
int n, m, k, s, t;
int a[maxn];
char str[maxn][maxn];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int cas = 1;
	scanf("%d", &t);
	while (t--){
		int x, y;
		s = 0;
		scanf("%d%d%d", &x, &y, &k);
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				if ((i&j) < k)s++;
		printf("Case #%d: ", cas++);
		printf("%d\n", s);
	}
}