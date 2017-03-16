#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
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

ui digits(ui n) {
    char buf[8];
    snprintf(buf, 8, "%u", n);
    return strlen(buf);
}

ui recycle(ui n, ui d) {
    char buf[8], buf2[8];
    snprintf(buf, 8, "%u", n);
    ui td = strlen(buf);
    fd(i, 0, d) {
        buf2[i] = buf[td - d + i];
    }
    fd(i, d, td) {
        buf2[i] = buf[i - d];
    }
    buf2[td] = '\0';
    return atoi(buf2);
}

void doTestcase() {
    ui A, B, count = 0;
    cin >> A >> B;
    ui d = digits(A);
    vui rs(d);

    fd(i, A, B+1) {
        fd(j, 1, d) {
            ui C = recycle(i, j);
            if (C > i && C <= B && rs.end() == find(rs.begin(), rs.end(), C)) {
                rs.push_back(C);
                ++count;
            }
        }
        rs.clear();
    }

    cout << count;
}

int main(int argc, char *argv[]) {
    frl(t, tt) {
        cout << "Case #" << t + 1 << ": ";
        doTestcase();
        cout << endl;
    }
    return EXIT_SUCCESS;
}

