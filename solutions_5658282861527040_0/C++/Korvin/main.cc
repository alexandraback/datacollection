#define _USE_32BIT_TIME_T 1
#include <vector> // headers {{{
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>

#define DEBUG(x) cout << #x << ": " << x << "\n"
using namespace std; // }}}

int result(int A, int B, int K)
{
    int cnt = 0;
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) {
            cnt+= (i & j) < K;
        }
    }
    return cnt;
}

int main()
{
    time_t start, end;
    time(&start);
    
    ifstream cin("test.in");
    ofstream cout("test.out");
    //cout.precision(6);
    //cout.setf(ios::fixed,ios::floatfield);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int A, B, K;
        cin >> A >> B >> K;
        cout << "Case #" << i << ": " << result(A, B, K) << endl;
        time(&end);
        ::cout << i << " " << difftime(end, start) << endl;
    }

    return 0;
}
