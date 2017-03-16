/*
 *    
 */
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<cmath> 
#include<algorithm>
#include<vector>
#include<list>
#include<cstring>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<queue>
#include<deque>
#include<ctime>
#include<complex>
#include<bitset>
#include<time.h>

using namespace std;
#define PB push_back
#define LL long long
#define MP make_pair
typedef unsigned long long ULL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define DBG 0

#define fori(i,a,b) for(int i = (a); i < (b); i++)
#define forie(i,a,b) for(int i = (a); i <= (b); i++)
#define ford(i,a,b) for(int i = (a); i > (b); i--)
#define forde(i,a,b) for(int i = (a); i >= (b); i--)
#define forls(i,a,b,n) for(int i = (a); i != (b); i = n[i])
#define mset(a,v) memset(a, v, sizeof(a))
#define mcpy(a,b) memcpy(a, b, sizeof(a))

#define dout  DBG && cerr << __LINE__ << " >>| "
#define checkv(x) dout << #x"=" << (x) << " | "<<endl
#define checka(array,a,b) if(DBG) { \
dout << #array"[] | " << endl; \
forie(i, a, b) cerr << "[" << i << "]=" << array[i] << " |" << ((i - (a)+1) % 5 ? " " : "\n"); \
if (((b)-(a)+1) % 5) cerr << endl; \
}

#define redata(T, x) T x; cin >> x
#define MIN_LD -2147483648
#define MAX_LD  2147483647
#define MIN_LLD -9223372036854775808
#define MAX_LLD  9223372036854775807
#define MAX_INF 18446744073709551615
const int INF = 0x7fffffff;//use double for addition
inline int  reint() { int d; scanf("%d", &d); return d; }
inline long relong() { long l; scanf("%ld", &l); return l; }
inline char rechar() { scanf(" "); return getchar(); }
inline double redouble() { double d; scanf("%lf", &d); return d; }
inline string restring() { string s; cin >> s; return s; }

typedef set<int> Set;
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
//set_union(ALL(x1),ALL(x2),INS(x)),set_intersection


int rf = 0;




int T, N, x;
int a,a1,a2;
const int maxn = 1010;
int vis[maxn], F[maxn], onstack[maxn];
vector<int> G[maxn];


int dfs2(int x, int id){
	int ans = id;
	fori(i,0,G[x].size()){
		int y = G[x][i];
		if(!(id==0 && y==F[x])){
			if(!vis[y] || vis[y]>0){
				vis[y] = -1;
				ans = max(ans,dfs2(y,id+1));
			}
		}
	}
	return ans;
}

void dfs(int x, int id){
	int y = F[x];
	onstack[x] = 1;
	if(!vis[y]){
		vis[y] = id+1;
		dfs(y,id+1);
	}
	else{
		if(onstack[y]){
			int u = vis[y];
			int looplen = id-u+1;
			int ans = 0;
			if(looplen>2){
				a1 = max(a1,looplen);
			}
			else{
				ans = dfs2(x,0);
				ans += dfs2(y,0);
				a2 += 2 + ans;
			}
		}
	}
	onstack[x] = 0;
}
int main(void){
    if(rf){
    	freopen("*.in", "r", stdin);
		freopen("*.out", "w", stdout);
    }
    cin.sync_with_stdio(false);
    cin >> T;
    forie(cnt,1,T){
    	cin >> N;
    	mset(vis,0);mset(onstack,0);
    	forie(i,0,N){
    		G[i].clear();
    	}
    	forie(i,1,N){
    		cin >> x;
    		F[i] = x;
    		G[x].PB(i);
    	}
    	a = a1 = a2 = 0;
    	forie(i,1,N){
    		if(!vis[i]){
    			vis[i] = 1;
    			dfs(i,1);
    		}
    	}
    	a = max(a1,a2);
    	printf("Case #%d: %d\n",cnt,a);
    }
    return 0;
}

/*
1
10
9 11 8 1 9 7 6 3 1 1 12 2 3 8
Case #1: 10
*/