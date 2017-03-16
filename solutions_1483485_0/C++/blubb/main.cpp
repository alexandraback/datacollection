#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#define fl(var, start, limit) for(var = (start); var < (limit); ++var)
#define fd(var, start, limit) for(unsigned int var = (start); var < (limit); ++var)
#define flz(var, limit) for(var = 0; var < (limit); ++var)
#define fdz(var, limit) for(unsigned int var = 0; var < (limit); ++var)
#define rl(limitVar) unsigned int limitVar; cin >> limitVar;
#define frl(var, limitVar) rl(limitVar); cin.getline(tmp, 4); fdz(var, limitVar)
#define fe(tp, it, in) for(tp ::iterator it = (in).begin(); it != (in).end(); ++it)
#define sp << " " <<
char tmp[4];
using namespace std;
typedef unsigned int ui;
typedef vector<unsigned int> vui;
typedef vector<int> vi;
typedef vector<char> vc;
#define nxt a; cin >> a; return a;
char nc() { char nxt; }
unsigned int nui() { unsigned int nxt; }
int ni() { int nxt; }
float nf() { float nxt; }
double nd() { double nxt; }

ui ix(char x) { return x - 'a'; }

char t[26];

void doTestcase() {
    char line[101];
    cin.getline(line, 101);
    for (ui i = 0; i < 101 && line[i] != '\0'; ++i) {
        if (line[i] >= 'a' == line[i] <= 'z')
            line[i] = t[ix(line[i])];
    }
    cout << line;
}

int main(int argc, char *argv[]) {
    t[ix('a')] = 'y';
    t[ix('b')] = 'h';
    t[ix('c')] = 'e';
    t[ix('d')] = 's';
    t[ix('e')] = 'o';
    t[ix('f')] = 'c';
    t[ix('g')] = 'v';
    t[ix('h')] = 'x';
    t[ix('i')] = 'd';
    t[ix('j')] = 'u';
    t[ix('k')] = 'i';
    t[ix('l')] = 'g';
    t[ix('m')] = 'l';
    t[ix('n')] = 'b';
    t[ix('o')] = 'k';
    t[ix('p')] = 'r';
    t[ix('q')] = 'z';
    t[ix('r')] = 't';
    t[ix('s')] = 'n';
    t[ix('t')] = 'w';
    t[ix('u')] = 'j';
    t[ix('v')] = 'p';
    t[ix('w')] = 'f';
    t[ix('x')] = 'm';
    t[ix('y')] = 'a';
    t[ix('z')] = 'q';
    frl(t, tt) {
        cout << "Case #" << t + 1 << ": ";
        doTestcase();
        cout << endl;
    }
    return EXIT_SUCCESS;
}

