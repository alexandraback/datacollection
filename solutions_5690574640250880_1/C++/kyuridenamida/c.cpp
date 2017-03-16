#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <ctime>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
#include <cassert>
using namespace std;
static const double EPS = 1e-10;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SS stringstream
#define DBG1(a) rep(_X,sz(a)){printf("%d ",a[_X]);}puts("");
#define DBG2(a) rep(_X,sz(a)){rep(_Y,sz(a[_X]))printf("%d ",a[_X][_Y]);puts("");}
#define bitcount(b) __builtin_popcount(b)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

#define delete(a,n) a.erase(remove(all(a),n),a.end())
template<typename T, typename S> vector<T>& operator<<(vector<T>& a, S b) { a.push_back(b); return a; }
template<typename T> void operator>>(vector<T>& a, int b) {while(b--)if(!a.empty())a.pop_back();}
bool isprime(int n){ if(n<2)return false;  for(int i=2;i*i<=n;i++)if(n%i==0)return false;  return true;} 
ll b_pow(ll x,ll n){return n ? b_pow(x*x,n/2)*(n%2?x:1) : 1ll;}
string itos(int n){stringstream ss;ss << n;return ss.str();}

void putCase(){
	static int x = 1;
	cout << "Case #" << x++ << ":";
}
typedef vector< vector<char> > B;
int done[52][52];
B v;
int r;
int w,h;

int cnt(int x,int y){
	int c = 0;
	for(int i = -1 ; i < 2 ; i++)
		for(int j = -1 ; j < 2 ; j++){
			int tx = x + j;
			int ty = y + i;
			if( tx < 0 || tx >= w || ty < 0 || ty >= h ) continue;
			c += v[ty][tx] == '*';
		}
	return c;
}
int reach = 0;
int dfs(int x,int y){
	if( x < 0 || y < 0 || y >= h || x >= w || done[y][x] || v[y][x] == '*' ) return 0;
	reach++;
	done[y][x] = 1;
	if(!cnt(x,y)){
		dfs(x+1,y);
		dfs(x-1,y);
		dfs(x,y+1);
		dfs(x,y-1);
		dfs(x+1,y-1);
		dfs(x-1,y-1);
		dfs(x+1,y+1);
		dfs(x+1,y-1);
	}
}


B rotate(B v){
	B w(v[0].size(),vector<char>(v.size()));
	for(int i = 0 ; i < v.size() ; i++)
		for(int j = 0 ; j < v[0].size() ; j++)
			w[j][i] = v[i][j];
	return w;
}
void view(B v){
	for(int i = 0 ; i < v.size() ; i++){
		for(int j = 0 ; j < v[0].size() ; j++) cout << v[i][j];
		cout << endl;
	}
}
int main(){
	int T;
	cin >> T;
	while(T--){
		memset(done,0,sizeof(done));
		//putCase();
		int m;
		cin >> h >> w >> m;
		
		int emp = h*w-m;
		int rot = 0;
		v = B(h,vector<char>(w,'.'));
		
		int sh = h , sw = w;
		int ph = 0 , pw = 0;
		if( !(sw < sh) ){
			v = rotate(v);
			swap(sw,sh);
			swap(ph,pw);
			rot ^= 1;
		}


		
		while(1){
			if( !(sw < sh) ){
				v = rotate(v);
				swap(sw,sh);
				swap(ph,pw);
				rot ^= 1;
			}

			if( m < sw  ){
				if( (sw < sh) ){
					v = rotate(v);
					swap(sw,sh);
					swap(ph,pw);
					rot ^= 1;
				}
				vector< pair<int,pair<int,int> >  > pairs;
				for(int i = 0 ; i < sh ; i++){
					for(int j = 0 ; j < sw ; j++){
						pairs.push_back(make_pair(i+j,make_pair(i,j)));
					}
				}
				sort(pairs.begin(),pairs.end());
				
				for(int i = 0 ; i < m ; i++){
					v[ph+pairs[i].second.first][pw+pairs[i].second.second] = '*';
				}
				
				break;
			}else{
				m -= sw;
				for(int i = 0 ; i < sw ; i++)
					v[ph][pw+i] = '*';
				ph++;
				sh--;
			}
		}
		
		if(rot)v=rotate(v);
		reach = 0;
		dfs(w-1,h-1);
		putCase(); cout << endl;
		if(reach==emp){
			v[h-1][w-1] = 'c';
			view(v);
		}else{
			//view(v);
			cout << "Impossible" << endl;
		}
	}
	
}