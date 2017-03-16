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
LL n;
string s;
LL p[1000005][2];
int pn;
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
    freopen("A-large.in","r",stdin);
    int t, test = 0;
    cin>>t; 
    while(t--)
    {
        cout<<"Case #"<<++test<<": ";
         cin >> s;
         cin >> n;
        LL l = s.length();
        LL ans = 0;
        LL cur = 0;
        pn = 0;
        for( LL i = 0; i < l; i++)
        {
            if( !vowel( s[i]))
            {
                LL j = i;
                while( i < l && !vowel(s[i])) 
                {
                    i++;
                    cur++;
                }
                if( cur >= n) p[++pn][0] = j; p[pn][1] = i-1;
                cur = 0;
            }
            else cur = 0;
        }
        cur = 1;
        LL pre = 0;
        for( LL i = 0; i < l; i++)
        {
            if( i > p[cur][1]) cur++;
            if( vowel(s[i]))
            {
                if( cur <= pn) ans += l-1 -(p[cur][0]+n-1)+1;
            }
            else
            {
//                cout << "shit" << endl;
                if( !(i >= p[cur][0] && i <= p[cur][1])) ans += l-1 -(p[cur][0]+n-1)+1;
                else
                {
                    if( i+n-1 <= p[cur][1]) 
                    {
//                        cout <<  i  << ' ' <<  i+n-1 <<  ' ' <<  p[cur][1] << endl;
                        ans += l-1-(i+n-1)+1;
                    }

                    else
                    {
                        if( cur < pn) ans += l-1-(p[cur+1][0]+n-1)+1;
                    }
                }
            }
//            cout << ans - pre << endl;
            pre = ans;
        }
        cout << ans << endl;
    }
    return(0);
}

