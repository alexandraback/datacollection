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


bool ok(int a, int b){


        int x[10], y[5];
        int l = 0, k = 0;

        while (a){
                x[l++] = a % 10;
                a /= 10;
        }
        while(b){
                y[k++] = b % 10;
                b /= 10;
        }
        if (l != k)return 0;
        for (int i = 0; i < l; i++){
                x[i + l] = x[i];
        }
        for (int i = 0; i < l; i++)
                if (x[i] == y[0]){
                        int flag = 1;
                        for (int j = 1; j < k; j++)
                                if (x[i + j] != y[j]){
                                        flag = 0;
                                        break;
                                }
                        if (flag)return 1;
                }
        return 0;
}


int main(){

        int tot;
        int n, count = 1;


        ifstream cin("C-small-attempt0.in");
        ofstream cout("b.out");

        cin >> tot;

        while (tot--)
        {
                int a, b, ans = 0;

                cin >> a >> b;

                for (int i = a; i <= b; i++)
                        for (int j = i + 1; j <= b; j++)
                                if (ok(i, j))
                                        ans++;
                cout << "Case #" << count++ << ": " << ans << endl;
        }

        return 0;
}
