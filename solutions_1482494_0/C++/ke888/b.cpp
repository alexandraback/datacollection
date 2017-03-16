#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <list>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<(int)b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair <int, int> pii;
#define debug(x) cerr << #x << " = " << (x) << \
" (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template <class T> void debugall(T a, T b) { cerr << " (L" << __LINE__ << ") "; for(T i = a; i != b; i++) cerr << *i << ", "; cerr << endl; }

#define MAXN 1000000
int memo[1 << 10][1 << 10];
int stages[10][2];
int n;

int rec(int st1, int st2){
    if(st2 == ((1 << n) - 1)){
        return 0;
    }
    if(memo[st1][st2] != MAXN){
        return memo[st1][st2];
    }
    int cur = 0;
    FOR(i,0,n){
        if(st2 >> i & 1) cur += 2;
        else if(st1 >> i & 1) cur++;
        else continue;
    }
    int res = MAXN;
    FOR(i,0,n){
        if(st2 >> i & 1){
            continue;
        }else{
            if(stages[i][1] <= cur){
                res = min(res, 1+rec(st1, st2 | (1 << i)));
                continue;
            }
            if(st1 >> i & 1){
                continue;
            }else{
                if(stages[i][0] <= cur){
                    res = min(res, 1+rec(st1 | (1 << i), st2));
                }
            }
        }
    }
    return memo[st1][st2] = res;
}

int main() {
	int zz;
	cin >> zz;
	FOR(z, 0, zz){
        FOR(i, 0, (1<<10)) FOR(j, 0, (1<<10)) memo[i][j] = MAXN;
        cin >> n;
        FOR(i, 0, n){
            int a, b;
            cin >> a >> b;
            stages[i][0] = a;
            stages[i][1] = b;
        }
        int res = rec(0, 0);

		printf("Case #%d: ", z+1);
        if(res >= MAXN){
            cout << "Too Bad" << endl;
        }else{
            printf("%d\n", res);
        }
	}
}
