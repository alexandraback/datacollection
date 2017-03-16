#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int a[10], b[10], c[10], d[20], g[20];

int main(){
	int r,n,m,k,x,w;
	bool bl;
	scanf("%*d%d%d%d%d",&r,&n,&m,&k);
	printf("Case #1:\n");
	
	rep(ri,r){
		rep(i,10) b[i] = c[i] =  0;
		rep(i,20) d[i] = 0;
		bl = false;
		rep(i,k){
			scanf("%d",&x);
			rep(i,10) a[i] = 0;
			while(x%2==0){ a[2]++; x /= 2;}
			while(x%3==0){ a[3]++; x /= 3;}
			while(x%5==0){ a[5]++; x /= 5;}
			while(x%7==0){ a[7]++; x /= 7;}
			rep(i,10) b[i] = max(b[i],a[i]), c[i] += a[i];
			maxs(d[n-a[3]-a[5]-a[7]],a[2]);
			if(a[2]&1) bl = true;
		}
		
		w = n;
		if(m <= 5){
			rep(i,b[3]) g[--w] = 3;
			rep(i,b[5]) g[--w] = 5;
			x = 0;
			if(bl) g[--w] = 2;
			for(int i = n; i >= 1; i--){
				while(w && g[i]-x > i-x/2){ g[--w] = 4; x+=2;}
			}
			while(w>0){
				if(c[2]*2 < (w*2+x)*n) g[--w] = 2,x++; else g[--w] = 4,x+=2;
			}
		} else {
		}
		
		rep(i,n) printf("%d",g[i]);
		puts("");
	}
	
	return 0;
}





