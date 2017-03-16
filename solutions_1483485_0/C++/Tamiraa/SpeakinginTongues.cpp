#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#define sqr(x) ((x)*(x))
#define ABS(x) ((x<0)?(-(x)):(x))
#define eps (1e-9)
#define mp make_pair
#define pb push_back
#define Pair pair<int,int>
#define xx first
#define yy second
#define equal(a,b) (ABS(a-b)<eps)
using namespace std;

template<class T> string tostring(T x) { ostringstream out; out<<x; return out.str();}
long long toint(string s) { istringstream in(s); long long x; in>>x; return x; }

/////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    map<char, char>m;
    m['a']='y';
    m['b']='h';
    m['c']='e';
    m['d']='s';
    m['e']='o';
    m['f']='c';
    m['g']='v';
    m['h']='x';
    m['i']='d';
    m['j']='u';
    m['k']='i';
    m['l']='g';
    m['m']='l';
    m['n']='b';
    m['o']='k';///K
    m['p']='r';
    m['q']='z';//!!q
    m['r']='t';
    m['s']='n';
    m['t']='w';
    m['u']='j';
    m['v']='p';
    m['w']='f';
    m['x']='m';
    m['y']='a';
    m['z']='q';//!!z
    int t;
    char s[300];
    freopen("speak.in", "r", stdin);
    freopen("speak.out", "w", stdout);
    scanf("%d\n", &t);
    for(int i=1; i<=t; i++){
       printf("Case #%d: ", i);
        fgets(s, 300, stdin);
        int len = strlen(s);
        for(int i=0; i<len; i++){
           if(s[i]==' ')printf(" ");
           else if(s[i]=='\n')printf("\n");
           else printf("%c", m[s[i]]);
        }
    }
return 0;
}
