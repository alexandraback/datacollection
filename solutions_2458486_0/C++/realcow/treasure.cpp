#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n; // # of chest
int nik, ik[40]; // initial keys

int reqKey[21];
vector<int> getKeys[21];

int d[1 << 20 + 1];

void f(int s)
{
    int i, j, k;
    int nkey, key[40];
    int usedKeys[20], nu = 0;
    int resKey[40], nr = 0;

    // copy initial key
    copy(ik, ik + nik, key);
    nkey = nik;

    // copy obtainable key
    for (i = 0; i < n; i++) {
        if (s & (1 << i)) {
            usedKeys[nu++] = reqKey[i];
            copy(getKeys[i].begin(), getKeys[i].end(), key + nkey);
            nkey += getKeys[i].size();
        }
    }

    sort(key, key + nkey);
    sort(usedKeys, usedKeys + nu);

    // obtained key - used key
    nr = set_difference(key, key + nkey, usedKeys, usedKeys + nu, resKey) - resKey;

    // search 
    for (i = 0; i < n; i++) {
        if (!(s & (1 << i))) {
            int ns = s | (1 << i);
            if (d[ns] == -1) {
                if (binary_search(resKey, resKey + nr, reqKey[i])) {
                    d[ns] = i;
                    f(ns);
                }
            }
        }
    }
}

int main()
{
    int pn = 0, i, j, k;
    
    scanf("%*d");   
    while (2 == scanf("%d%d", &nik, &n)) {
        for (i = 0; i < nik; i++) scanf("%d", &ik[i]);
        for (i = 0; i < n; i++) {
            getKeys[i].clear();
            int nok, t;
            scanf("%d%d", &reqKey[i], &nok);
            for (j = 0; j < nok; j++)
                scanf("%d", &t), getKeys[i].push_back(t);
            sort(getKeys[i].begin(), getKeys[i].end());
        }

        // remove needless keys
        for (i = 0; i < nik; i++) {
            if (find(reqKey, reqKey + n, ik[i]) == reqKey + n)
                ik[i] = -1;
        }
        nik = remove(ik, ik + nik, -1) - ik;
        for (i = 0; i < n; i++) {
            for (int& key : getKeys[i]) {
                if (find(reqKey, reqKey + n, key) == reqKey + n)
                    key = -1;
            }
            int newsize = remove(getKeys[i].begin(), getKeys[i].end(), -1) - getKeys[i].begin();
            getKeys[i].resize(newsize);
        }

        pn++;
        fill(d, d + (1 << n), -1);
        f(0);

        printf("Case #%d: ", pn);
        if (d[(1 << n) - 1] == -1) printf("IMPOSSIBLE\n", pn);
        else {
            int s = (1 << n) - 1;
            vector<int> sol;
            while (s) {
                sol.push_back(d[s] + 1);
                s ^= (1 << d[s]);
            }
            while (!sol.empty()) printf("%d ", sol.back()), sol.pop_back();
            puts("");
        }

    }
    return 0;
}