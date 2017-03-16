#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <deque>
#include <time.h>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <bitset>

//#pragma comment(linker, "/STACK:256000000")

#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N

#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs

#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)

#define DBN1(a)         cerr<<#a<<"="<<(a)<<"\n"
#define DBN2(a,b)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define DBN3(a,b,c)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define DBN4(a,b,c,d)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"

using namespace std;


int main() {
#ifdef MYLOCAL
    freopen("//home//maks//input.txt", "rt", stdin);
    freopen("//home//maks//output.txt", "wt", stdout);
    clock_t beginTime = clock();
#endif

    int te;
    cin >> te;
    for (int test = 0; test < te; ++test) {
        int a, b, c;
        long long ans = 0;
        cin >> a >> b >> c;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
               // DBN(i, j, i & j);
                if ((i & j) < c)
                    ++ans;
            }
        }
        DBN(ans);
        cout << "Case #" << test + 1 << ": " << ans << endl;
    }

#ifdef MYLOCAL
    cout << endl << "time: " << double(clock() - beginTime) / CLOCKS_PER_SEC;
#endif
    return 0;
}
