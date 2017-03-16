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

typedef long long llong;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int caseNum=1;
ifstream fin("D.in");
ofstream fout("D.out");

#define gout fout << "Case #" << caseNum++ << ": ", fout

int main (int argc, char* argv[]) {
    int T;
    fin >> T;

    while (T--) {
        int K,C,S;
        fin>>K>>C>>S;

        if (K != S)
            gout << "WELP\n";
        else {
            fout << "Case #" << caseNum++ << ":";
            for (int i=1;i<=K;i++)
                fout << ' ' << i;
            fout << '\n';
        }
    }

    fin.close();
    fout.close();
    return 0;
}
