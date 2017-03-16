// BEGIN CUT HERE

// END CUT HERE
#line 5 "PlatypusPaternity.cpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
#include <deque>
#include <utility>
#include <list>
#include <sstream>
#include <iostream>
#include <functional>
#include <fstream>
#include <numeric>
#include <algorithm>

using namespace std;

//Prepared for TopCoder and Codeforces

#define EP 1E-10
#define CLR(arr, v) memset(arr, v, sizeof(arr))
#define SQ(a)       ((a)*(a))
#define DEBUG(a)    printf("%s = %s\n", #a, toStr(a).c_str())
#define FOR(i,s,e)  for( int (i)=(s); (i) < (e) ; i++)
#define SIZE(X)     ((int)(X.size()))
#define LENGTH(X)   ((int)(X.length()))
#define two(X)      (1<<(X))
#define twoL(X)     (((int64)(1))<<(X))

typedef long long ll;
typedef unsigned long long ull;
const   double PI = acos(-1.0);
int     toInt(string s)   {int r=0; istringstream sin(s); sin>>r; return r;}
ll      toInt64(string s) {ll r=0; istringstream sin(s); sin>>r; return r;}
double  toDouble(string s){double r=0; istringstream sin(s); sin>>r; return r;}
//double  dist(double x1, double y1, double x2, double y2){return sqrt(SQ(x1-x2)+SQ(y1-y2));}
bool isUpperCase(char c){return c >= 'A' && c <= 'Z';}
bool isLowerCase(char c){return c >= 'a' && c <= 'z';}
bool isLetter(char c)   {return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';}
bool isDigit(char c)    {return c >= '0' && c <= '9';}
char toLowerCase(char c){return (isUpperCase(c))?(c + 32) : c;}
char toUpperCase(char c){return (isLowerCase(c))?(c - 32) : c;}

template<class T> inline T strTo(string s){istringstream is(s);T v;is>>v;return v;}
template<class T> inline string toStr(const T& v){ostringstream os;os<<v;return os.str();}
template<class T> inline int cMin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> inline int cMax(T& a, const T& b){return a<b?a=b,1:0;}
template<class T> inline int cBit(T n){return n?cBit(n&(n-1))+1:0;}
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}
template<class T> inline T GCD(T a, T b)
  {if(a<0)return GCD(-a,b);if(b<0)return GCD(a,-b);return (b==0)?a:GCD(b,a%b);}
template<class T> inline T LCM(T a, T b)
  {if(a<0)return LCM(-a,b);if(b<0)return LCM(a,-b);return a*(b/gcd(a,b));}


int a[120], b[120];

int dp[120][120];
int tot;
int n, p, s;
int ans;

void dfs(int i, int x, int q){
        if (i == n){
                if (x == s){
                        //cout << x << " " << q << endl;
                        ans = max(ans, q);
                }
                return;
        }

        if (b[i] >= p)dfs(i + 1, x, q + 1);
        else dfs(i + 1, x, q);

        if (a[i] > -1){
                if (a[i] >= p)
                        dfs(i + 1, x + 1, q + 1);
                else dfs(i + 1, x + 1, q);
        }
}

int main()
{
        ifstream cin("B-small-attempt1.in");
        ofstream cout("b.out");

        cin >> tot;
        int count = 1;

        while (tot--)
        {
                cin >> n >> s >> p;
                int v;

                CLR(a, -1);
                CLR(b, -1);

                for (int i = 0; i < n; i++){

                        cin >> v;

                        bool flag = 0;

                        for (int x = 0; x <= v; x++)
                                for (int y = x; y <= v; y++)
                                        for (int z = y; z <= v; z++)
                                                if (x + y + z == v){
                                                        if (z - x == 2)a[i] = max(a[i], z);
                                                        if (z - x < 2)
                                                                b[i] = max(b[i], z);
                                                }
                       // cout << a[i] << " " << b[i] << endl;
                }

                ans = 0;
                dfs(0, 0, 0);

                cout << "Case #" << count++ << ": " << ans << endl;

        }
        return 0;

}
