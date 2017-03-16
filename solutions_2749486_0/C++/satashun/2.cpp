//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>
#include <climits>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define fi first
#define se second

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int T, x, y;
char dir[4] = {'N', 'S', 'E', 'W'};

map<P, string> m;

void small(int t){
    //static char ma[410][410][510] = {'\0'};
    queue<pair<P, int> > q;
    m.clear();
    q.push(mp(mp(200, 200), 1));
    m[mp(200, 200)] = "";
    while(!q.empty()){
	pair<P, int> p = q.front(); q.pop();
	if(p.fi.fi == x + 200 && p.fi.se == y + 200) break;
	//printf("%d %d %s\n", p.fi.fi - 200, p.fi.se - 200, ma[p.fi.fi][p.fi.se]);
	//int len = strlen(ma[p.fi.fi][p.fi.se]);
	int len = m[p.fi].size();
	rep(i, 4){
	    int nx = p.fi.fi + dx[i] * p.se, ny = p.fi.se + dy[i] * p.se;
	    if(nx == 200 && ny == 200) continue;
	    if(nx < -200 || ny < -200 || nx > 600 || ny > 600) break;
	    //int l = strlen(m[mp(nx, ny)]);
	    if(m.count(mp(nx, ny))) continue;
	    //if(l != 0) continue;
	    string t = "";
	    string s = m[p.fi];
	    q.push(mp(mp(nx, ny), p.se + 1));
	    rep(j, len) t.pb(s[j]); t.pb(dir[i]);
	    m[mp(nx, ny)] = t;
	}
    }
    printf("Case #%d: ", t + 1);
    cout << m[mp(x + 200, y + 200)] << endl;
}

int main(){
    scanf("%d", &T);
    rep(t, T){
	scanf("%d %d", &x, &y);
	small(t);
	/*
	for(int i = -4; i <= 4; ++i){
	    for(int j = -4; j <= 4; ++j){
		printf("%s ", ma[i + 200][j + 200]);
	    }
	    puts("");
	}
	*/
	//printf("Case #%d: %s\n", t + 1, ma[x + 200][y + 200]);
    }
    return 0;
}
