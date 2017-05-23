#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 2000010
#define MOD 1000000007
#define INF 9223372036854775807LL
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;
int prod[8];
set<int> v[MAX];
set<int>::iterator it;
char s['z'+1];

string rec(string v){
    int i, cont = 0;
    string t = "";
    for(i = 0; i < v.size(); i++){
        if(isalpha(v[i]))
            t+=s[v[i]];
        else
            t+=v[i];
    }
    return t;
}

int main(){
    int i, j, k, A, B, T;
    string v;
    s['a'] = 'y',s['b'] = 'h',s['c'] = 'e',s['d'] = 's',s['e'] = 'o',s['f'] = 'c',s['g'] = 'v';
    s['h'] = 'x',s['i'] = 'd',s['j'] = 'u',s['k'] = 'i',s['l'] = 'g',s['m'] = 'l',s['n'] = 'b';
    s['o'] = 'k',s['p'] = 'r',s['q'] = 'z',s['r'] = 't',s['s'] = 'n',s['t'] = 'w',s['u'] = 'j';
    s['v'] = 'p',s['w'] = 'f',s['x'] = 'm',s['y'] = 'a',s['z'] = 'q';    
    cin >> T;
    getline(cin, v);
    for(k = 1; k <= T; k++){
        getline(cin, v);
        cout << "Case #"<<k<<": " << rec(v)<<endl;
    }
    return 0;
}
