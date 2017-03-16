#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <list>
#include <set>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define forin(i, l, h) for(ll i = l; i < h; i++)

int solve(int r, int c, int w);

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");

    int trialCount;
    fin >> trialCount;

    for(int trialNo = 1; trialNo <= trialCount; trialNo++) {
        int w, r, c;
        fin >> r >> c >> w;
        fout << "Case #" << trialNo << ": " << solve(r, c, w) << "\n";
    }


    return 0;
}


int solve(int r, int c, int w) {
    int colDiv = c / w;
    int result = colDiv * (r - 1);

    vector<bool> lastRow = vector<bool>(c, false);
    forn(i, c) {
        lastRow[i] = !((i + 1) % w);
        result += !((i + 1) % w);
    }
    //cerr << result << endl;
    int rightTrace = 0;
    for(int i = c - 1; i >= 0; i--) {
        if(lastRow[i]) break;
        rightTrace++;
    }
    result += w - 1 + ((rightTrace)? 1 : 0);

    return result;
}
