#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SIZE(x) (int)(x).size()

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

void Solve() {
    char s[1010];
    char t[2010];
    scanf("%s", s);
    int l = 1000, r = 1000;
    t[r++] = s[0];
    for (int i = 1; s[i]; ++i) {
        if (s[i] >= t[l]) {
            t[--l] = s[i];
        } else {
            t[r++] = s[i];
        }
    }
    for (int i = l; i < r; ++i) {
        putchar(t[i]);
    }
    puts("");
}

int main() {
//	freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d: ", T);
        Solve();
        cerr << "Case #" << T << ": done!" << endl;
    }
    return 0;
}

