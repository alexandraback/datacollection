#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int T, C=1, n;
map<vector<int>,int> PD;
map<vector<int>,int>::iterator PDi;

int calc(vector<int> v) {

    PDi = PD.find(v);
    if (PDi != PD.end())
        return PDi->second;

    // sem nada
    int resp = 0;
    for (int i=0;i<(int)v.size();i++)
        resp = max(resp, v[i]);

    // mudando
    for (int i=0;i<(int)v.size();i++)
        for (int j=1;j<v[i];j++) { // 0 e todos eh nosense
            vector<int> nv = v;
            nv[i] -= j;
            nv.push_back(j);
            sort(nv.begin(),nv.end());
            int tt = 1 + calc(nv);
            resp = min(resp, tt);
        }
    PD[v] = resp;
    return resp;
}

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d",&n);
        vector<int> v;
        for (int i=0;i<n;i++) {
            int t;
            scanf("%d",&t);
            v.push_back(t);
        }
        PD.clear();
        sort(v.begin(),v.end());
        printf("%d\n",calc(v));

    }

    return 0;
}
