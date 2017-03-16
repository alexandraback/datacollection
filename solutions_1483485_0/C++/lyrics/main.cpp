#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cmath>
#define sz(a) ((int)(a).size())
#define foreach(i, v) for(__typeof((v).begin()) i=(v).begin(); i!=(v).end(); i++)
using namespace std;
typedef long long llong;
typedef pair<int, int> Item;

const int Maxn = 1000+10;
const llong INF = 0x7f7f7f7f7f7f7f7fLL;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int realcmp(double a, double b){ return (a>b+eps) ? 1 : ((a+eps<b)?-1:0); }

int main()
{
    int T;
    char s[200];
    ios::sync_with_stdio(0);
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("a.out", "w", stdout);
    map<char, char> mp;
    mp['y']='a';  mp['n']='b';  mp['f']='c';  mp['i']='d';  mp['c']='e';  mp['w']='f';  mp['l']='g';
    mp['b']='h';  mp['k']='i';  mp['u']='j';  mp['o']='k';  mp['m']='l';  mp['x']='m';  mp['s']='n';
    mp['e']='o';  mp['v']='p';  mp['z']='q';  mp['p']='r';  mp['d']='s';  mp['r']='t';
    mp['j']='u';  mp['g']='v';  mp['t']='w';  mp['h']='x';  mp['a']='y';  mp['q']='z';  mp[' ']=' ';

    scanf("%d\n", &T);
    for(int i=0; i<T; i++)
    {
        gets(s);
        string str = (string)s;
        printf("Case #%d: ", i+1);
        for(int i=0; i<sz(str); i++)
            printf("%c", mp[str[i]]);
        printf("\n");
    }

    return 0;
}
