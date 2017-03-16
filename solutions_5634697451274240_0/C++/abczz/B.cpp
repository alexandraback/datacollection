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
    char s[300];
    scanf("%s", s);
    int l = strlen(s);
    while (l && s[l - 1] == '+') --l;
    int n = (l > 0);
    REP(i, l - 1) {
        if (s[i + 1] != s[i]) {
            ++n;
        }
    }
    cout << n << endl;
}

int main() {
//	freopen("B.in","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d: ", T);
        Solve();
        cerr << "Case #" << T << ": done!" << endl;
    }
    return 0;
}

