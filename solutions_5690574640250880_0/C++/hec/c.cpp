#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

char  table[50][50];

int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={1,0,-1,-1,-1,0,1,1};

int main(void){
	int t;
	cin >> t;
	rep(loop,t){
		int r,c,m;
		cin >> r  >> c >> m;
		rep(i,r)rep(j,c) table[i][j]='.';
		bool ok=true;
		int cur=m;
		for(int i=r-1;i>=3;i--){
			for(int j=c-1;j>=3;j--){
				if(cur>0){
					table[i][j]='*';
					cur--;
				}
			}
		}
		for(int i=r-1;i>=3;i--){
			if(c>=3){
				if(cur>=3){
					table[i][0]=table[i][1]=table[i][2]='*';
					cur-=3;
				}else if(cur>0){
					table[i][2]='*';
					cur--;
				}
			}else{
				if(cur>0){
					if(1<c){
						table[i][1]='*';
						cur--;
					}
					if(0<c){
						table[i][0]='*';
						cur--;
					}
				}
			}
		}
		for(int j=c-1;j>=3;j--){
			if(r>=3){
				if(cur>=3){
					table[0][j]=table[1][j]=table[2][j]='*';
					cur-=3;
				}else if(cur>0){
					table[2][j]='*';
					cur--;
				}
			}else{
				if(cur>0){
					if(1<r){
						table[1][j]='*';
						cur--;
					}
					if(0<r){
						table[0][j]='*';
						cur--;
					}
				}
			}
		}
		// corner case  2 2 
		if(cur>0){  
			if(2<r&&2<c){   
				table[2][2]='*';
				cur--;
			}
		}
		// corner case 2 0 and 2 1
		if(cur>0){
			if(2<r&&1<c){
				table[2][1]='*';
				cur--;
			}
			if(2<r&&0<c){
				table[2][0]='*';
				cur--;
			}
		}
		// corner case 0 2 and 0 1
		if(cur>0){
			if(1<r&&2<c){
				table[1][2]='*';
				cur--;
			}
			if(0<r&&2<c){
				table[0][2]='*';
				cur--;
			}
		}
		// corner case 0 1 and 1 0 and 1 1
		if(cur>0){
			if(0<r&&1<c){
				table[0][1]='*';
				cur--;
			}
			if(1<r&&0<c){
				table[1][0]='*';
				cur--;
			}
			if(1<r&&1<c){
				table[1][1]='*';
				cur--;
			}
		}
	//	dump(cur);
		table[0][0]='c';
		if(cur==0)
			ok=true;
		else
			ok=false;

		cout << "Case #" << loop+1 << ": " << endl;
		if(ok){
			rep(i,r){
				rep(j,c) cout << table[i][j];
				cout << endl;
			}
		}else
			cout << "Impossible" << endl;
	}
	return 0;
}