#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <fstream>
#include <numeric>
#include <limits.h>
#include <limits>
#include <iterator>
#include <iomanip>
#include <bitset>
#include <assert.h>

using namespace std;

#define EPS (1e-9)
#define PI (2 * acos(0.0))
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) )
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))

typedef long long LL;

ifstream input;
ofstream output;
bool writeToFile = false;

void setSIO(std::string iFilePath, std::string oFilePath) {
    cin.sync_with_stdio(false);
    cout << setprecision(16);
    if (writeToFile) {
        streambuf *i, *o;
        input.open(iFilePath.c_str(), ifstream::in);
        i = input.rdbuf();
        output.open(oFilePath.c_str(), ifstream::out);
        o = output.rdbuf();
        cin.rdbuf(i);
        cout.rdbuf(o);
    }
}

int testIndex = 1;

template <typename T>
void printTest(T result) {
    cout << "Case #" << testIndex << ": " << result << endl;
    testIndex++;
}

void main2();
map<char, char> conv;

void add(string original, string other) {
    int N = other.length();
    REP(i, N) conv[other[i]] = original[i];
}

int main(int argc, char** argv) {
    writeToFile = true;
    setSIO("in.txt", "out.txt");
    conv['y'] = 'a';
    conv['e'] = 'o';
    conv['q'] = 'z';
    conv['z'] = 'q';
    add("our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi");
    add("there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    add("so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv");
    int T;
    string s;
    cin >> T;
    getline(cin, s);

    REP(t, T) {
        main2();
        assert(cin);
    }
    cout.flush();
    return 0;
}

void main2() {
    string s, other;
    getline(cin, s);
    other = s;
    int N = s.length();
    REP(i, N) other[i] = conv[s[i]];
    printTest(other);
}
