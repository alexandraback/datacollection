#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <deque>
#include <queue>
#include <bitset>
#include <stack>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <iomanip> 
#include <ctime>
using namespace std;

#define sz size()
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second 

typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii; 
const int INF=~(1<<31);
const double eps=1e-6;
 
const long double PI = 3.1415926535;
 
 
int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  int n;
  int q,Q;
  cin>>Q;
  int dx[]={1,-1,0,0},
	  dy[]={0,0,1,-1};

  FOR(q,1,Q){
	printf("Case #%d: ",q);
	int x,y;
	cin>>x>>y;
	int l=0;
	string ans;
	while(1){
		ans.clear();
		l++;
		int m=l;
		int h=m;
		pii g(x,y);
		while(h>0){
			int mnum=0,mval=1e8;
			rep(u,4){
				pii z=g;
				z.first+=dx[u]*h;
				z.second+=dy[u]*h;
				if(abs(z.first)+abs(z.second)<mval){
					mval=abs(z.first)+abs(z.second);
					mnum=u;
				}
			}
			{
				if(mnum==1)ans.pb('E');
				if(mnum==0)ans.pb('W');
				if(mnum==3)ans.pb('N');
				if(mnum==2)ans.pb('S');
				pii z=g;
				z.first+=dx[mnum]*h;
				z.second+=dy[mnum]*h;
				g=z;
				h--;
			}
		}
		if(g==pii(0,0))break;
	}
	reverse(all(ans)); cout<<ans<<'\n';
  }
  return 0;
}
