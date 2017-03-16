#include <bits/stdc++.h>

using namespace std;

#define TRACE(x...)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)

typedef vector<int> vi;
typedef vector<vi> vvi;

void doit(vi& F, vvi& ine, vi& C, int i, int curc){
    C[i] = curc;
    if(C[F[i]] == 0) doit(F, ine, C, F[i], curc);
    for(int x : ine[i]) if(C[x] == 0) doit(F, ine, C, x, curc);
}

int height(vvi& ine, vi& fez, int v){
    int ans = 0;
    for(int u : ine[v]) if(fez[u] != 2) ans = max(ans, 1 + height(ine, fez, u));
    return ans;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int n; cin >> n;
        vi F(n), C(n), fez(n);
        vvi ine(n), cmps(n);

        for(int i = 0; i < n; i++){
            cin >> F[i]; F[i]--;
            ine[F[i]].push_back(i);
        }

        int curc = 1;
        for(int i = 0; i < n; i++) if(C[i] == 0){
            doit(F, ine, C, i, curc);
            curc++;
        }

        for(int i = 0; i < n; i++) cmps[C[i]].push_back(i);

        int ans = 0, maxm = 0;

        for(auto comp : cmps) if(comp.size() > 0){

            int a = comp[0]; fez[a] = 1;
            int b = F[a];
            while(fez[b] != 1) {
                    fez[b] = 1;
                    b = F[b];
            }

            vector<int> cyc{b};
            a = F[b];
            fez[b] = 2;

            while(a != b){
                cyc.push_back(a);
                fez[a] = 2;
                a = F[a];
            }

            vector<int> best;

            int m = cyc.size();

            for(int i = 0; i < m; i++) best.push_back(height(ine, fez, cyc[i]));

            for(int i = 0; i < m; i++) WATCH(best[i]);

            int cans = 0;

            if(m == 2) cans = max(cans, 2 + best[0] + best[1]);

            ans += cans;
            maxm = max(maxm, m);

        }

        ans = max(ans, maxm);
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
