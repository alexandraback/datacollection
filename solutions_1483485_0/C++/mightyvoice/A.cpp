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
typedef vector<int> vint;
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef map<int, int> mint;
typedef set<int> sint;

#define TWO(k)  (1<<k)
#define TWOL(k) (((LL)(1)<<(k)))
#define MP make_pair
#define MIN(a,b) ( (a)<(b)?(a):(b) )
#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define LS(x) 	 ((x)<<1)
#define RS(x) 	 (((x)<<1)+1)

const double PI = acos(-1.0);
const double EPS = 1e-9;
const int oo = 210000000;

int main()
{
    //freopen("A-small-attempt2.in","r",stdin);freopen("out.txt","w",stdout);
    map<char, char> mc;
    mc['a'] = 'y'; mc['b'] = 'h'; mc['c'] = 'e'; mc['d'] = 's';
    mc['e'] = 'o'; mc['f'] = 'c'; mc['g'] = 'v'; mc['h'] = 'x';
    mc['i'] = 'd'; mc['j'] = 'u'; mc['k'] = 'i'; mc['l'] = 'g';
    mc['m'] = 'l'; mc['n'] = 'b'; mc['o'] = 'k'; mc['p'] = 'r';
    mc['q'] = 'z'; mc['r'] = 't'; mc['s'] = 'n'; mc['t'] = 'w';
    mc['u'] = 'j'; mc['v'] = 'p'; mc['w'] = 'f'; mc['x'] = 'm';
    mc['y'] = 'a'; mc['z'] = 'q'; 
    int t, test = 0;
    scanf("%d", &t); getchar();
    while(t--)
    {
        printf("Case #%d: ", ++test);
        char s1[200];
        gets( s1);
        string s2 = s1;
        int l = s2.length();
        for( int i = 0; i < l; i++)
        {
            if( s2[i] >= 'a' && s2[i] <= 'z') s2[i] = mc[s2[i]];
        }
        cout<<s2<<endl;
    }
    return(0);
}

