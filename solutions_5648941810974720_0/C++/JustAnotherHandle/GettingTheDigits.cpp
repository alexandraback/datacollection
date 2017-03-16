#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

int res[12], c[300], n;
char a[2005];

void solve() {
    memset(c, 0, sizeof c);
    for (int i = 0; i < n; ++i)
        c[a[i]]++;
    res[0] = c['Z'];
    res[2] = c['W'];
    res[8] = c['G'];
    res[3] = c['H'] - c['G'];
    res[6] = c['X'];
    res[7] = c['S'] - c['X'];
    res[5] = c['V'] - res[7];
    res[4] = c['R'] - c['Z'] - c['H'] + c['G'];
    res[1] = c['O'] - c['W'] - res[4] - c['Z'];
    res[9] = (n - res[0]*4 - res[1]*3 - res[2]*3 - res[3]*5 - res[4]*4 - res[5]*4 - res[6]*3 - res[7]*5 - res[8]*5) / 4;
    ////////
    for (int i = 0; i < 10; ++i)
    for (int j = 0; j < res[i]; ++j)
        printf("%d",i);
    printf("\n");
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int t; scanf("%d\n",&t); int tmp = t;
    while (t--) {
        scanf("%s\n",a);
        n = strlen(a);
        //////////////
        printf("Case #%d: ",tmp-t);
        solve();
    }
	return 0;
}
