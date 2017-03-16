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
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rp(i,a) for(int i=0;i<a;i++)
#define FD(i,a,b) for(int i=a;i>=b;i--)
#define STOP  system("pause")
#define PP printf(" ")
#define mem(x,y) memset(x,y,sizeof(x))
#define LN printf("\n");
#define du freopen("in.txt","r",stdin)
#define chu freopen("out.txt","w",stdout)
#define EPS 1e-10

#define FI first
#define SE second
#define PB push_back
#define MP make_pair


typedef long long LL;
inline int dblcmp(double x) { return fabs(x)<EPS?0:x>0?1:-1; }
inline bool insize(int c,int l,int r){if (c>=l&&c<=r) return true; return false;}
template<class T> inline void checkmin(T &a,T b)	{if(a == -1 || a > b)a = b;}
template<class T> inline void checkmax(T &a,T b)	{if(a < b)	a = b;}
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int ,int> II;

int dx[] = {0,1,0,-1};//up Right down Left
int dy[] = {1,0,-1,0};
template<class T> inline void sf(T& x)
{
    char c;
    int mul = 1;
    while((c = getchar()) != EOF)
    {
        if(c == '-')mul = -1;
        if(c >= '0' && c <= '9')
        {
            x = c-'0';
            break;
        }
    }
    if(c == EOF){x = EOF;return;}
    while(c = getchar())
    {
        if(c >= '0' && c <= '9')
        {
            x = (x<<1)+(x<<3)+(c-'0');
        }
        else break;
    }
    x *= mul;
}

const int N= 100005;       // 点数
const int E= 200005;   //边数
const int INF= 0x3f3f3f3f;
const long long  LINF= 0x3F3F3F3F3F3F3F3FLL;


LL a[N];
LL A, n;

int main()
{
    int nca,ica(0);
    sf(nca);
    while(nca--)
    {
        sf(A); sf(n);
        LL ans= n, cnt=0;
        rep(i,1,n)
            sf(a[i]);
        sort(a+1,a+1+n);

        rep(i,1,n)
        {
            if(A>a[i])
            {
                A+= a[i];
            }
            else
            {
                // 放弃
                checkmin(ans, cnt+(n-i+1));
                // 否则
                for(;A<=a[i] && cnt<=n;cnt++)
                    A+= A-1;
                if(cnt>=n)
                    break;
                A+= a[i];
            }
        }
        checkmin(ans, cnt);
        printf("Case #%d: %I64d\n", ++ica, ans);
    }

}


