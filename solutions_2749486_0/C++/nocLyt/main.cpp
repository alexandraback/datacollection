#include <ctime>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <deque>
#include <assert.h>
using namespace std;
#define BUG1 puts("BUG11\n")
#define BUG2 puts("BUG22\n")
#define rep(i,a,b)  for(int (i)=(a);(i)<=(b);(i)++)
#define rp(i,n) for(int i=0;i<n;i++)
#define repp(i,a,b,c) for(int i=a;(c>0)?(i<=b):(i>=b);i+=c)
#define isf(x) int x;sf(x);
#define STOP  system("pause")
#define PP printf(" ")
#define mem(x,y) memset(x,y,sizeof(x))
#define LN printf("\n");
#define du freopen("in.txt","r",stdin)
#define chu freopen("out.txt","w",stdout)
#define EPS 1e-8

//--------------

//--------
#define FI first
#define SE second
#define PB push_back
#define MP(a,b) make_pair(a,b)
#define VIS vector<string>
#define SZ(x) int(x.size())
#define foreach(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define ALL(x) x.begin(),x.end()
template<class T> inline void CLR(T &A) {
    A.clear();
}
#define DO(n) while(n--)
#define DO_C(n) int n____=n;while(n____--)
//----------
typedef long long LL;
inline bool insize(int c,int l,int r) {
    if (c>=l&&c<=r) return true;
    return false;
}
template<class T> inline void checkmin(T &a,T b) {
    if(a == -1 || a > b)a = b;
}
template<class T> inline void checkmax(T &a,T b) {
    if(a < b)    a = b;
}
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int ,int> II;
typedef queue<int> QI;

int dx[] = {0,1,0,-1};//up Right down Left
int dy[] = {1,0,-1,0};
int dblcmp(double x) {
    return fabs(x-0)<EPS?0:x>0?1:-1;
}
template<class T> inline void sf(T& x) {
    char c;
    int mul = 1;
    while((c = getchar()) != EOF) {
        if(c == '-')mul = -1;
        if(c >= '0' && c <= '9') {
            x = c-'0';
            break;
        }
    }
    if(c == EOF) {
        x = EOF;
        return;
    }
    while((c = getchar())) {
        if(c >= '0' && c <= '9') {
            x = (x<<1)+(x<<3)+(c-'0');
        } else break;
    }
    x *= mul;
}
template<class T0, class T1> inline void sf(T0& x, T1& y) {sf(x);sf(y);}
template<class T0, class T1, class T2> inline void sf(T0& x, T1& y, T2& z) {sf(x);sf(y);sf(z);}

// mem 127, 0x7f => 2139062143 => 0x7F7F7F7F
// mem  63, 0x3f => 1061109567 => 0x3f3f3f3f
// mem 255, 0xff => -1
const int N=505;       // 点数
const int E=200055;   //边数
const int INF= 0x3f3f3f3f;
const long long  LINF= 0x3F3F3F3F3F3F3F3FLL;

II mp[N][N]; // <fo,
bool vis[N][N];
int ex, ey;

queue<II> q;
char ch[100000];
int  ans;

void dfs(int x, int y) {
	if(mp[x][y].FI<0)   return;
	if(mp[x][y].FI==0) {    // 北
        ch[ans++]= 'N';
        dfs(x, y-mp[x][y].SE);
	}else if(mp[x][y].FI==1) {
        ch[ans++]= 'E';
        dfs(x-mp[x][y].SE, y);
	}else if(mp[x][y].FI==2) {
		ch[ans++]= 'S';
		dfs(x, y+mp[x][y].SE);
	}else  {
		ch[ans++]= 'W';
		dfs(x+mp[x][y].SE, y);
	}
}

int main() {

    const int LEN= 500;
    isf(nca);
    rep(ica,1,nca) {
        mem(vis,0);
        sf(ex,ey);
        ex+= 100; ey+= 100;
        vis[100][100]= 1; mp[100][100]=MP(-1,0);
        while(!q.empty())   q.pop();
        q.push(MP(100,100));

        while(!q.empty()) {
        	II p= q.front(); q.pop();
            int x=p.FI, y=p.SE;
            int c= mp[p.FI][p.SE].SE +1;
            // North
            y+= c;
            if(insize(x,0,LEN) && insize(y,0,LEN) && !vis[x][y]) {
            	vis[x][y]= 1;
            	mp[x][y]= MP(0,c);
            	q.push(MP(x,y));
            }
            y-= c;
            // East
            x+= c;
            if(insize(x,0,LEN) && insize(y,0,LEN) && !vis[x][y]) {
            	vis[x][y]= 1;
            	mp[x][y]= MP(1,c);
            	q.push(MP(x,y));
            }
            x-= c;
            // South
            y-= c;
            if(insize(x,0,LEN) && insize(y,0,LEN) && !vis[x][y]) {
            	vis[x][y]= 1;
            	mp[x][y]= MP(2,c);
            	q.push(MP(x,y));
            }
            y+= c;
            // WEST
            x-= c;
            if(insize(x,0,LEN) && insize(y,0,LEN) && !vis[x][y]) {
            	vis[x][y]= 1;
            	mp[x][y]= MP(3,c);
            	q.push(MP(x,y));
            }
            x+= c;

            if(vis[ex][ey]) break;
        }


        ans=0;
        dfs(ex,ey);

        printf("Case #%d: ", ica);
        repp(i,ans-1,0,-1)
            printf("%c", ch[i]);
        LN;

    }

}
