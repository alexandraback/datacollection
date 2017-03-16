#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define double long double
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
//template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int maxn = 1000 + 100;
int b[maxn];
int mark[maxn], ind[maxn], mx[maxn], mx2[maxn], mx3[maxn];
bool d2[maxn];
int main(){
	iOS;
	int T;
	cin >> T;
	for(int test = 1; test <= T; ++ test){
		cout << "Case #" << test << ": ";
		int n;
		cin >> n;
		int ans = 0;
		fill(mark, mark + maxn, -1);
		fill(mx, mx + maxn, 0);
		fill(mx2, mx2 + maxn, 0);
		fill(mx3, mx3 + maxn, 0);
		memset(d2, 0, sizeof d2);
		For(i,0,n){
			cin >> b[i];
			-- b[i];
		}
		int best = 0;
		For(i,0,n){
			int t = 1;
			int v = i;
			vi w;
			while(mark[v] != i){
				w.pb(v);
				mark[v] = i;
				ind[v] = t ++;
				v = b[v];
			}
			int c = t - ind[v];
			if(c == 2){
				int a = w.back();
				smax(mx2[a], t-3);
				d2[a] = d2[v] = 1;
				w.PB;
				smin(a, w.back());
				smax(mx3[v], t-1);
				smax(mx[a], t-1);
			}
			smax(best, c);
		}
		For(i,0,n)if(d2[i]){	ans += max(mx2[i] + mx3[i], mx2[b[i]] + mx3[b[i]]); d2[i] = d2[b[i]] = 0;}
		cout << max(best, ans) << '\n';
	}
}
