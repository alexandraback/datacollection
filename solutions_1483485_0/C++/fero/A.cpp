#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define FOREACH(iter, cont) for(__typeof((cont).begin()) iter = (cont).begin(); iter != (cont).end(); iter++)
#define REP(i, end) for(int i = 0; i < (end); i++)
#define CLEAR(arr) memset(arr, 0, sizeof(arr))
#define ALL(cont) (cont).begin(),(cont).end()

map<char, char> g;

int main() {

    g['y'] = 'a';
    g['n'] = 'b';
    g['f'] = 'c';
    g['i'] = 'd';
    g['c'] = 'e';
    g['w'] = 'f';
    g['l'] = 'g';
    g['b'] = 'h';
    g['k'] = 'i';
    g['u'] = 'j';
    g['o'] = 'k';
    g['m'] = 'l';
    g['x'] = 'm';
    g['s'] = 'n';
    g['e'] = 'o';
    g['v'] = 'p';
    g['z'] = 'q';
    g['p'] = 'r';
    g['d'] = 's';
    g['r'] = 't';
    g['j'] = 'u';
    g['g'] = 'v';
    g['t'] = 'w';
    g['h'] = 'x';
    g['a'] = 'y';
    g['q'] = 'z';
    g[' '] = ' ';

    int cases;
    cin >> cases >> ws;
    for (int cs = 1; cs <= cases; cs++) {
	string line;
	getline(cin, line);
	cout << "Case #" << cs << ": ";
        FOREACH(c, line)
	    cout << g[*c];
	cout << endl;
    }
}
