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

const int N = 2010;

int n, a[N], b[N], nr, ve1[N], ve2[N], cs[3 * N], cd[3 * N], vv[4 * N];
map<string, int> h;
vector<int> v[3 * N];
bool ver[3 * N];

bool pairup(int nod) {
    int i;

    if(ver[nod])
        return 0;

    ver[nod] = 1;

    for(vector<int>::iterator it = v[nod].begin(); it != v[nod].end(); ++it)
        if(cd[*it] == -1 || pairup(cd[*it])) {
            cs[nod] = *it;
            cd[*it] = nod;
            return 1;
        }

    return 0;
}

int cuplaj() {
    int nrr = 0, i, ok = 1;

    while(ok) {
        ok = 0;
        memset(ver, 0, sizeof(ver));

        for(i = 1; i <= nr; ++i) if(!cs[i] && pairup(i)) {
            ok = 1;
            ++nrr;
        }
    }

    return nrr;
}

void sol() {
    int i, j;

    nr = 0;
    h.clear();

    for(i = 0; i < 3 * N; ++i) {
        v[i].clear();
        cs[i] = cd[i] = 0;
        cd[i] = -1;
    }
    nr = 0;

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

    memset(vv, 0, sizeof(vv));
    for(i = 0; i < n; ++i) {
        //a[i] += n;
        b[i] += nr;

        v[a[i]].push_back(b[i]);

        vv[b[i]]++;
        //v[a[i]].push_back(i);
        //v[i].push_back(b[i]);
        //v[b[i]].push_back(i);
    }

    int r = 0;

    for(i = 0; i < 3 * N; ++i) {
        if(v[i].size())
            ++r;
        if(vv[i])
            ++r;
    }


    out << n - (r - cuplaj());
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
