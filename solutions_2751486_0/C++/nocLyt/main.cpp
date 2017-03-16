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
const int N=205;       // 点数
const int E=200055;   //边数
const int INF= 0x3f3f3f3f;
const long long  LINF= 0x3F3F3F3F3F3F3F3FLL;

char ch[N];
int n;
bool mp[100];

bool solve(int l, int r) {
    int s= 0;
	rep(i,l,r) {
	    if(s>=n)    return 1;
		if(mp[ch[i]-'a'+1]==0)  s++;
		else    s=0;
	}
	if(s>=n)    return 1;
	return 0;
}

int main() {

    mem(mp,0);
    mp['a'-'a'+1]= 1;
    mp['e'-'a'+1]= 1;
    mp['i'-'a'+1]= mp['o'-'a'+1]= mp['u'-'a'+1]= 1;

    isf(nca);
    rep(ica,1,nca) {

        scanf("%s", ch); sf(n);
        int ans= 0;
        int L= strlen(ch);
        rep(i,0,L-1) rep(j,i,L-1)
            ans+= solve(i,j);

        printf("Case #%d: %d\n", ica,ans);


    }

}
