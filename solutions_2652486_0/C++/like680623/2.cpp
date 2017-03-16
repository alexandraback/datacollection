
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



int d[200][3], in = 0;
int a[10];
int R, N, M, K;
vector<int> p[200];

bool ok(int l)
{
        int len = p[l].size();

        for (int j = 0; j < K; j++)
        {
                int is = 0;
                for (int i = 0; i < len; i++)
                        if (a[j] == p[l][i])
                        {
                                is = 1;
                                break;
                        }
                if (!is)return 0;
        }
        return 1;
}


void init()
{

        for (int i = 2; i <= 5; ++i)
                for (int j = i; j <= 5; j++)
                        for (int k = j; k <= 5; k++)
                        {
                               d[in][0] = i;
                               d[in][1] = j;
                               d[in][2] = k;
                               in++;
                              // cout << i << " " << j << " " << k << endl;
                        }
        for (int l = 0; l < in; ++l)
        {
                for (int i = 0; i < (1 << 3); i++)
                {
                        int t = 1;
                        for (int j = 0; j < 3; j++)
                                if (i & (1 << j))
                                        t *= d[l][j];
                        p[l].push_back(t);
                }
        }
}



int main()
{

       ifstream cin("C-small-1-attempt1.in");
        ofstream cout("b.txt");


        int tot;

        cin >> tot;

        int c = 1;

        init();


        while (tot--)
        {



                cout << "Case #" << c++ << ":"<< endl;


                cin >> R >> N >> M >> K;

                //init();

               // cout << R << " " << N << " " << M << " " << K << endl;


                for (int i = 0; i < R; ++i)
                {
                        for (int j = 0; j < K; j++)
                        {
                                cin >> a[j];
                        }
                        //cout << i << endl;
                        for (int l = 0; l < in; ++l)
                        {
                                if (ok(l))
                                {
                                        cout << d[l][0] << d[l][1] << d[l][2] << endl;
                                        break;
                                }
                        }
                }

        }



        return 0;
}
