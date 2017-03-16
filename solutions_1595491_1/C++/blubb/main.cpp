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
#define frl(var, limitVar) rl(limitVar); fdz(var, limitVar)
#define fe(tp, it, in) for(tp ::iterator it = (in).begin(); it != (in).end(); ++it)
#define sp << " " <<
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

void doTestcase() {
    rl(N); rl(S); rl(p);
    ui r = 0;
    fdz(i, N) {
        rl(t);
        ui x = t / 3;
        ui rest = t % 3;
        if (x >= p) {
            ++r;
        } else if (x + 1 >= p) {
            if (rest > 0) {
                ++r;
            } else if (S > 0 && x > 0) {
                ++r;
                --S;
            }
        } else if (x + 2 >= p && rest > 1 && S > 0) {
            ++r;
            --S;
        }
    }
    cout << r;
}

int main(int argc, char *argv[]) {
    frl(t, tt) {
        cout << "Case #" << t + 1 << ": ";
        doTestcase();
        cout << endl;
    }
    return EXIT_SUCCESS;
}

