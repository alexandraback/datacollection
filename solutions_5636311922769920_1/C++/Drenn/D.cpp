#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <limits>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define all(c) (c).begin(),(c).end()

using namespace std;

typedef unsigned long long llong;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int caseNum=1;
ifstream fin("D.in");
ofstream fout("D.out");

#define gout fout << "Case #" << caseNum++ << ":", fout

int main (int argc, char* argv[]) {
    int T;
    fin >> T;

    while (T--) {
        int K,C,S;
        fin>>K>>C>>S;

        vector<llong> needed;
        int nextToCheck=0;
        for (int i=0; i<S; i++) {
            // student i
            int c=0;
            llong pos=0;
            while (c < C && nextToCheck < K) {
                pos *= K;
                pos += nextToCheck;
                nextToCheck++;

                c++;
            }
            needed.push_back(pos);
            if (nextToCheck >= K)
                break;
        }
        if (nextToCheck < K)
            gout << " IMPOSSIBLE\n";
        else {
            gout << "";
            for (llong i : needed) {
                fout << ' ' << (i+1);
            }
            fout << '\n';
        }
    }

    fin.close();
    fout.close();
    return 0;
}
