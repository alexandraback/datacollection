#include <iostream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <string>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <deque>

#include <algorithm>
#include <numeric>

#define foreach(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define sqr(x) ((x) * (x))
#define len(x) ((int64) (x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define endl '\n'
#ifdef CUTEBMAING
#include "cutedebug.h"
#else
#define debug(x) ({})
#endif

using namespace std;

typedef long long int64;
typedef unsigned long long lint64;
typedef long double ld;

const int64 inf = ((1ll << 60) - 1);

const char* fin = "input.txt";
const char* fout = "output.txt";
const int64 cmax = 1000000;

int64 n, a;
int64 array[cmax];

void run(){
    cin >> a >> n;
    for (int64 i = 0; i < n; i++)
        cin >> array[i];
    sort(array, array + n);
    int64 ans = inf;
    for (int64 i = n - 1; i >= -1; i--){
        int64 curAns = n - i - 1;
        int64 curSum = a;
        for (int64 j = 0; j <= i; j++)
            if (curSum > array[j])
                curSum += array[j];
            else{
                if (curSum == 1){
                    curAns = inf;
                    continue;
                }
                while (curSum <= array[j])
                    ++curAns, curSum += curSum - 1;
                curSum += array[j];
            }
        ans = min(ans, curAns);
    }
    cout << ans << endl;
}

int main(){
    #if !defined STRESS && defined CUTEBMAING
    assert(freopen(fin, "r", stdin));
    assert(freopen(fout, "w", stdout));
    #endif
    int64 t; cin >> t;
    for (int64 i = 0; i < t; i++){
        cout << "Case #" << i + 1 << ": ";
        run();
    }
    return 0;
}
