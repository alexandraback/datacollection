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
ifstream fin("A.in");
ofstream fout("A.out");

#define gout fout << "Case #" << caseNum++ << ": ", fout

int main (int argc, char* argv[]) {
    int T;
    fin >> T;

    int needed = 0;
    for (int i=0;i<10;i++)
        needed |= (1<<i);

    while (T--) {
        int N;
        fin >> N;
        int visited = 0;

        if (N == 0)
            gout << "INSOMNIA\n";
        else {
            int i;
            for (i=1; visited != needed; i++) {
                llong v = N*i;
                while (v != 0) {
                    visited |= 1<<(v%10);
                    v /= 10;
                }
            }
            gout << (N*(i-1)) << '\n';
        }
    }

    fin.close();
    fout.close();
    return 0;
}
