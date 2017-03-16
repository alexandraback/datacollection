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
double  dist(double x1, double y1, double x2, double y2){return sqrt(SQ(x1-x2)+SQ(y1-y2));}
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




const ll INF = (1 << 20);
int N = 1005;


int main()
{

        ifstream cin("A-small-attempt0.in");
        ofstream cout("b.txt");


        int tot;

        cin >> tot;

        int c = 1;

        while (tot--)
        {

                ll t, r;

                cin >> r >> t;

                ll sum = 0, ans = 0;

                while (1)
                {
                        ll temp = (SQ(r + 1) - SQ(r));
                        if (sum + temp <= t)
                        {
                                sum += temp;
                        }
                        else break;

                        ans++;
                        r += 2;
                }

                cout << "Case #" << c++ << ": " << ans << endl;


        }



        return 0;
}
