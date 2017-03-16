#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <utility>
#include <set>
#include <map>
#include <cctype>

#define FOR(i,n) for(long long int i=0; i<n; i++)
#define MP(a,b) make_pair(a,b)
#define PB(x) push_back(x)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())

#define COND(p,t,f) ((p)?(t):(f))

#define PI 3.14159265

using namespace std;
typedef long long int lint;
typedef unsigned long long int ulint;



int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        lint R,C,W;
        cin >> R >> C >> W;
        //lint res = C - ((C-W)/W)*W + (C-W)/W + (R-1)*(C/W);
        lint res = 0;
        lint pp = C;
        while (pp>2*W) {
            res++;
            pp-=W;
        }
        lint qq = C;
        lint tmp=0;
        while (qq>=W) {
            tmp++;
            qq-=W;
        }
        //lint res = (C - 2*W)/W + W+1 + (R-1)*(C/W);
        res+=W+COND(pp!=W,1,0);
        //res+=(R-1)*(C/W);
        res+=(R-1)*tmp;
        cout << "Case #" << t+1 << ": " << res << endl;
        cerr << R << " " << C << " " << W << " " << res << endl;
    }

}
