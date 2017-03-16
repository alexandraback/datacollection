//      anks
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <iostream>
#include <string.h>
using namespace std;

typedef long long ll;
#define debug(args...) dbg(),args
#define S(N) scanf("%d", &N)
#define SS(N) scanf("%s", N)
#define FOR(A,B,C) for(int A=B;A<C;++A)
#define RFOR(A,B,C) for(int A=B;A>=C;--A)
#define PB(A,B) A.push_back(B);
#define MEM(A,B) memset(A,B,sizeof(A))
#define MAX(A,B) ((A > B) ? A : B)
#define MIN(A,B) ((A < B) ? A : B)
#define MAXLIM 100000
bool DBG;
struct dbg { template<typename T> dbg& operator , (const T& v) { if (DBG)
 cerr << v << " "; return *this; } ~dbg() { if (DBG) cerr << endl; } };
map<char, char> freq;
void preprocess() {
    freq['a'] = 'y'; freq['b'] = 'h'; freq['c'] = 'e'; freq['d'] = 's'; freq['e'] = 'o';
    freq['f'] = 'c'; freq['g'] = 'v'; freq['h'] = 'x'; freq['i'] = 'd'; freq['j'] = 'u';
    freq['k'] = 'i'; freq['l'] = 'g'; freq['m'] = 'l'; freq['n'] = 'b'; freq['o'] = 'k';
    freq['p'] = 'r'; freq['q'] = 'z'; freq['r'] = 't'; freq['s'] = 'n'; freq['t'] = 'w';
    freq['u'] = 'j'; freq['v'] = 'p'; freq['w'] = 'f'; freq['x'] = 'm'; freq['y'] = 'a';
    freq['z'] = 'q';
}

int main (int argc, char *argv[]) {
    DBG = (argc > 1 && *argv[1]);

    preprocess();

    int t;
    scanf("%d\n", &t);

    FOR(i, 0, t) {
        string s;
        getline(cin, s);
        printf("Case #%d: ", i+1);
        FOR(i, 0, s.length()) {
            if (isspace(s[i])) {
                printf(" ");
            } else {
                printf("%c", freq[s[i]]);
            }
        }
        printf("\n");
    }

    return 0;
}
