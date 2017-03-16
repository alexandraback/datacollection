#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<bitset>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define inf (1 << 28)
map<char, char> m;


int main(){
    m['a'] = 'y';
m['b'] = 'h';
m['c'] = 'e';
m['d'] = 's';
m['e'] = 'o';
m['f'] = 'c';
m['g'] = 'v';
m['h'] = 'x';
m['i'] = 'd';
m['j'] = 'u';
m['k'] = 'i';
m['l'] = 'g';
m['m'] = 'l';
m['n'] = 'b';
m['o'] = 'k';
m['p'] = 'r';
m['q'] = 'z';
m['r'] = 't';
m['s'] = 'n';
m['t'] = 'w';
m['u'] = 'j';
m['v'] = 'p';
m['w'] = 'f';
m['x'] = 'm';
m['y'] = 'a';
m['z'] = 'q';
    int t; cin >> t;
    string s; getline(cin, s);
    for(int cc = 1; cc <= t; cc++){
            getline(cin, s);
            f(i, 0, s.size()) if(s[i] != ' ') s[i] = m[s[i]];
            cout << "Case #" << cc << ": " << s << endl;
    }
}
