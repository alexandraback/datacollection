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

typedef pair< pair<int, int>, int > ww;

int main(int argc, char** argv) {
    writeToFile = true;
    setSIO("in.txt", "out.txt");
    int T;
    cin >> T;

    REP(t, T) {
        main2();
        assert(cin);
    }
    cout.flush();
    return 0;
}
vector< pair<double, double> > L, R;
const int ERROR = 1 << 29;

double calc(pair<double, double> first, pair<double, double> second) {
    if (second.second >= first.second) return numeric_limits<double>::max();
    double dist = second.first - first.first - 5;
    return dist / (first.second - second.second);
}

bool possible(int idx, vector< pair<double, double> > &A, vector< pair<double, double> > &B) {
    REP(i, B.size()) if (A[idx].first - B[i].first < 5 && A[idx].first - B[i].first>-5) return false;
    B.push_back(A[idx]);
    A.erase(A.begin() + idx);
    return true;
}

void main2() {
    //side,speed,position
    L.clear();
    R.clear();
    int N, bestIdx = 0;
    double result = 0;
    cin >> N;

    REP(i, N) {
        char ch;
        int speed, position;
        cin >> ch >> speed >> position;
        if (ch == 'L') L.push_back(pair<double, double>(position, speed));
        else R.push_back(pair<double, double>(position, speed));
    }

    while (bestIdx != ERROR) {
        bestIdx = ERROR;
        double minTime = numeric_limits<double>::max();
        sort(ALL(L));
        sort(ALL(R));

        REP(i, L.size() - 1) {
            double tempTime = calc(L[i], L[i + 1]);
            if (tempTime < minTime) bestIdx = i + 1, minTime = tempTime;
        }

        REP(i, R.size() - 1) {
            double tempTime = calc(R[i], R[i + 1]);
            if (tempTime < minTime) bestIdx = -1 - i, minTime = tempTime;
        }
        result += minTime;
        bool end = false;
        if (bestIdx != ERROR) {
            REP(i, L.size()) L[i].first += L[i].second*minTime;
            REP(i, R.size()) R[i].first += R[i].second*minTime;
            if (bestIdx > 0) end = !possible(bestIdx - 1, L, R);
            else end = !possible(-1 * bestIdx - 1, R, L);
            if (end) {
                printTest(result);
                return;
            }
        }
    }
    printTest("Possible");

}
