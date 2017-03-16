#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>

using namespace std;

#define SZ(X) ((int)X.size())
#define REP(i,n) for(int i=0; i<(int)n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define IT(it) __typeof((it)->begin())
#define FORIT(v) for(IT(v) it=(v)->begin(); it!=(v)->end(); it++)
#define all(x) (x).begin(),x.end()
#define pb(x) push_back(x)
#define VI vector<int> 
#define VVI vector<vector<int> >
#define VS vector<string>

int power[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int ten(int b)
{
    if (b<2) return 10;
    int bits = (int)ceil(log2(b+1));
    int low = (int)(log2(1<<(bits-1))/log2(10));
    if (low>0) low--;
    while (1) {
        if (power[low] <= b && (low+1 > 7 || power[low+1] > b)) return power[low+1]; 
        low++;
    }
}

bool shift(int a, int s, int A, int *pret)
{
    int y = power[s];
    int b = a/y;
    int z = a % y * ten(b) + b;
    //cout << a << " " << s << " " << b << " " << ten(b) << " " << y << " " << z << endl;
    bool ret=false;
    if (b == 0) ret=false;
    else {
        if (a % y < power[s-1]) ret=false;
        else {
            if (z < a && z >= A) ret=true;
        }
    }
    //cout << "ret = " << ret << endl;
    *pret=z;
    return ret;
}

int go(int A, int B)
{
    int ret=0;
    int y;
    FOR(x,A,B) {
        set<int> u;
        FOR(i,1,6) {
            if (shift(x,i,A,&y)) {
                u.insert(y);
            }
        }
        ret+=u.size();
    }
    return ret;
}
int main() {
    int T;
    cin >> T; getchar();
    REP(zz,T) {
        int A, B;
        cin >> A >> B; getchar();
        int ret = go(A,B);

        printf("Case #%d: %d\n", zz+1, ret);
    }
    return 0;
}
