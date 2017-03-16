// <-------------------[sWitCHcAsE]---------------------->
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<cstring>
#include<cassert>
#include<queue>
#include<set>

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORS(i,a,n) for(int i=a;i<n;i++)
#define FORR(i,a) for(int i=a;i>=0;i--)
#define foreach(it, x) for(typeof(x.begin()) it = x.begin(); it!=x.end();it++)
#define ERR(x) cerr<<#x<<" "<<x<<endl
#define pb push_back
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef vector<int> VI;
typedef long long ll;
typedef long double ld;

inline int print(int d) { return printf("%d",d);}
inline int read(int &d) { 
	d=0;
	int sign=1,ch;
	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)ch=getchar_unlocked();
	if(ch=='-')
		sign=-1, ch=getchar_unlocked();
	do 
		d=(d<<3)+(d<<1)+ch-'0';
	while((ch=getchar_unlocked())>='0' && ch<='9');
	d*=sign;
	return 1;
}

map<pair<int, pair<int, int> >, int> DP;
map< pair<int, pair< int,int> > ,string> Path;
queue< pair<int, pair<int, int> > > Q;
#define PAIR(x,y,z) make_pair(x,make_pair(y,z))

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int rx[] = {0, 0 , -1, 1};
int ry[] = {-1,1, 0, 0};

string dir = "NSEW";
map<char, int> R; 


string dij(int X, int Y) {
	R['N'] = 0; 
	R['S'] = 1; 
	R['E']= 2; 
	R['W'] = 3;
	DP.clear();Path.clear();
	while(!Q.empty())Q.pop();
	Q.push(make_pair(0, make_pair(0,0)));
	DP[PAIR(0,0,0)] = 0;
	Path[PAIR(0,0,0)] = "";
	int moves ;
	while(!Q.empty()) {
		pair<int, pair<int,int> > c = Q.front();
		Q.pop();
		int m = c.first;
		int xx = c.second.first;
		int yy = c.second.second;
		cerr<<"Popped "<<xx<<" "<<yy<<"  wiht m "<<m<<endl;
		if ( xx == X && yy == Y) {
			moves = m;
			break;
		}
		string cPath = Path[c];
		if ( m > 500) continue;
		FOR(i,4) {
			int x1= xx+ dx[i] * (m+1);
			int y1= yy+ dy[i] * (m+1);
			if ( 1) {
				pair<int, pair<int,int> > P = PAIR(m+1, x1,y1);
				if ( DP.find(P) == DP.end()) {
					DP[P] =m+1;
					Path[P] = cPath + dir[i];
					Q.push(PAIR(m+1,x1,y1));
				}
				else if ( DP[P] > m+1) {
					DP[P] = m+1;
					Path[P] = cPath + dir[i];
					Q.push(PAIR(m+1,x1,y1));
				}
			}
		}
	}
	cerr<<"DJ completed\n";
	string ans = "";
	/*pair<int, pair<int,int> > S = PAIR(moves, X,Y);
	while(Path[S] != 0) {
		ans += Path[S];
		int pm = moves;
		int idx = R[Path[S]];
		int xxx = S.second.first + pm * rx[idx];
		int yyy = S.second.second + pm * ry[idx];
		S = PAIR(moves-- , xxx,yyy);
		cerr<<"Path of S is "<<Path[S]<<endl;
	}
	reverse(ans.begin(), ans.end());*/
	ans = Path[PAIR(moves,X,Y)];
	return ans;

}

int main(int argc,char** args) 
{
	int tc;read(tc);FOR(tests,tc) {
		cout<<"Case #"<<tests+1<<": ";
		int X, Y;
		cin>>X>>Y;
		string ans = dij(X,Y);
		cout<<ans<<endl;
	}
}
