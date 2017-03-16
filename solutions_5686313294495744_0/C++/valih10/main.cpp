#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

ofstream out("tttt");

const int N = 1010;

int n, a[N], b[N], nr, ve1[N], ve2[N];
map<string, int> h;

void sol() {
    int i, j;

    nr = 0;
    h.clear();

    cin >> n;

    for(i = 0; i < n; ++i) {
        string x;

        cin>> x;

        if(!h[x])
            h[x] = ++nr;
        a[i] = h[x];

        cin >> x;

        if(!h[x])
            h[x] = ++nr;
        b[i] = h[x];
    }

    int emax = 0;

    for(i = 0; i < (1<<n); ++i) {

        for(j = 0; j <= nr; ++j)
            ve1[j] = ve2[j] = 0;

        int nrc = 0;

        for(j = 0; j < n; ++j) if(i & (1<<j)) {
            ve1[a[j]] = 1;
            ve2[b[j]] = 1;
        }

        for(j = 0; j < n; ++j) if(!(i & (1<<j))) {
            ++nrc;

            if(!ve1[a[j]] || !ve2[b[j]]) {
                nrc = -666;
                break;
            }
        }

        if(nrc >= 0)
            emax = max(emax, nrc);
    }

    out << emax;
}

int main() {
    freopen("ttt", "r", stdin);
    //freopen("tttt", "w", stdout);

    int t, a = 0;
    cin >> t;

    while(t--) {
        ++a;
        out << "Case #" << a << ": ";
        sol();
		out << "\n";

        printf("Test %d\n", a);
    }

    return 0;
}
