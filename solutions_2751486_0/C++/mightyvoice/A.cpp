#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vI;
typedef vector<string> vS;
typedef pair<int, int> pI;
typedef map<int, int> mI;
typedef map<string, int> mSI;
typedef set<int> sI;
typedef set<pI> spI;
typedef priority_queue<int> qmax;
typedef priority_queue<int, vector<int>, greater<int> >qmin;
typedef map<int, int>::iterator mI_it;
typedef set<int>::iterator sI_it;

#define TWO(k)  (1<<(k))
#define LTWO(k) (((LL)(1)<<(k)))
#define MIN(a,b) ( (a)<(b)?(a):(b) )
#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define LS(x) 	 ((x)<<1)
#define RS(x) 	 (((x)<<1)+1)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define B begin()
#define E end()
#define F0(i, n) for( int (i) = 0; (i) < (n); (i)++)
#define F1(i, n) for( int (i) = 1; (i) <= (n); (i)++)
#define zero(i) memset((i),0,sizeof((i)))

const double PI = acos(-1.0);
const double EPS = 1e-9;
const int ioo = (~0)-(1<<31);
const LL loo = (~(LL)0)-((LL)1<<63);

char s1[5] = {'a','e','i','o','u'};
int n;
string s;
bool vowel( char x)
{
    F0(i,5)
    {
        if( s1[i] == x) return 1;
    }
    return 0;
}
bool find1( string x, int l)
{
    int cur = 0;
    F0(i,l)
    {
        if( !vowel(x[i])) 
        {
            cur ++;
            if( cur >= n) return 1;
        }
        else cur = 0;
    }
    return 0;

}
int main()
{
    freopen("out.txt","w",stdout);
    freopen("A-small-attempt0.in","r",stdin);
    int t, test = 0;
    cin>>t; 
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
         cin >> s;
         cin >> n;
        int l = s.length();
        int ans = 0;
        F0(i,l)
        {
            int j;
            for(  j = i; j < l; j++) 
            {
                string tmp = "";
                for( int k = i; k <= j; k++) tmp += s[k];
                if( find1(tmp, j-i+1)) ans++;
            }
        }
        cout << ans << endl;

    }
    return(0);
}

