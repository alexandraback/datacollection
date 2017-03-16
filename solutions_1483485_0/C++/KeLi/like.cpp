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



string s, s1;
int v[50];

void init()
{
        CLR(v, 0);

        v['y' - 'a'] = 'a';
        v['e' - 'a'] = 'c';
        v['o' - 'a'] = 'e';
        v['q' - 'a'] = 'z';

        v['u' - 'a'] = 'j';
        v['r' - 'a'] = 'p';
        v['l' - 'a'] = 'm';
        v['n' - 'a'] = 's';
        v['g' - 'a'] = 'l';

        v['i' - 'a'] = 'k';
        v['s' - 'a'] = 'd';

        v['m' - 'a'] = 'x';
        v['p' - 'a'] = 'v';
        v['b' - 'a'] = 'n';

        v['t' - 'a'] = 'r';
        v['d' - 'a'] = 'i';
        v['w' - 'a'] = 't';
        v['y' - 'a'] = 'a';

        v['x' - 'a'] = 'h';
        v['f' - 'a'] = 'w';
        v['c' - 'a'] = 'f';
        v['v' - 'a'] = 'g';
        v['h' - 'a'] = 'b';
        v['j' - 'a'] = 'u';
        v['k' - 'a'] = 'o';
        v['z' - 'a'] = 'q';
        v['a' - 'a'] = 'y';

        bool f[50];
        for (int i = 0; i < 26; i++){
                f[v[i] - 'a'] = 1;
        }

        //cout << "hhh" << endl;

        //for (int i = 0; i < 26; i++)
        //        if (!f[i])cout << i << endl;
}

int main(){

        int tot;
        int n, count = 1;

       // ifstream cin("A-large-practice.in");
      //  ofstream cout("a.out");
        init();


        ifstream cin("A-small-attempt0 (1).in");
        ofstream cout("b.out");

        cin >> tot;

        //CLR(v, 0);
        cin.get();


        while (tot--)
        {
                //getline(cin, s);
                getline(cin, s1);
                cout << "Case #" << count++ << ": ";

                for (int i = 0; i < s1.length(); i++){
                        if (isLetter(s1[i])){

                                for (int j = 0; j < 26; j++)
                                        if (s1[i] == v[j]){
                                                s1[i] = char(j + 'a');
                                               // cout << "hhh" << endl;
                                                break;
                                        }
                        }
                        cout << s1[i];
                }
                cout << endl;
                //cout << s1 << endl;
        }

        return 0;
}
