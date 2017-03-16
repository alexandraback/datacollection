#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>


using namespace std;
#define ll long long

string A[1000], B[1000];
int An[1000], Bn[1000];
int N;

bool vis[2002];
int cap[2002][2002];
vector<int> E[2002];
int flow(int s, int e) {
    if (s == e) {
        return 1;
    }
    if (vis[s]) {
        return 0;
    }
    vis[s] = true;

    //printf("At %d going to %d\n", s, e);

    for (int i=0;i<E[s].size();++i) {
        int next = E[s][i];
        if (cap[s][next] && flow(next, e)) {
            cap[s][next]--;
            cap[next][s]++;
            return 1;
        }
    }
    return 0;
}

int sf() {
    for (int i=0;i<2002;++i) {
        E[i].clear();
    }
    int SRC = 2000;
    int SNK = 2001;
    memset(cap,0,sizeof(cap));
    map<string, int> lua, lub;
    vector<int> AW, BW;
    for (int i=0;i<N;++i) {
        if (lua.count(A[i]) == 0) {
            int z = lua.size();
            lua[A[i]] = z;
            AW.push_back(z);
            E[SRC].push_back(z);
            E[z].push_back(SRC);
        }
        An[i] = lua[A[i]];
        cap[SRC][An[i]] = 1;

    }
    for (int i=0;i<N;++i) {
        if (lub.count(B[i]) == 0) {
            int z = lub.size();
            lub[B[i]] = z;
            BW.push_back(z);
            E[z + 1000].push_back(SNK);
            E[SNK].push_back(z+1000);
        }
        Bn[i] = lub[B[i]];
        cap[Bn[i] + 1000][SNK] = 1;
    }
    for (int i=0;i<N;++i) {
        E[An[i]].push_back(Bn[i] + 1000);
        E[Bn[i] + 1000].push_back(An[i]);
        cap[An[i]][Bn[i] + 1000] = 1;
    }


        
    int goodppls = 0;
    memset(vis,0,sizeof(vis));
    while (flow(SRC, SNK)) {
        memset(vis,0,sizeof(vis));
        goodppls++;
    }
    //printf("Got %d flows\n", goodppls);

    for (int i=0;i<AW.size();++i) {
        if (cap[SRC][i] == 1) {
            goodppls++;
        }
    }

    for (int i=0;i<BW.size();++i) {
        if (cap[i+1000][SNK] == 1) {
            goodppls++;
        }
    }

    return N - goodppls;
}

int solve() {
    map<string, int> lu;
    set<int> Aw, Bw;
    for (int i=0;i<N;++i) {
        if (lu.count(A[i]) == 0) {
            int z = lu.size();
            lu[A[i]] = z;
        }
        An[i] = lu[A[i]];
        Aw.insert(An[i]);
    }
    for (int i=0;i<N;++i) {
        if (lu.count(B[i]) == 0) {
            int z = lu.size();
            lu[B[i]] = z;
        }
        Bn[i] = lu[B[i]];
        Bw.insert(Bn[i]);
    }

    int ans = 0;
    for (int i=0;i<(1<<N);++i) {
        set<int> Af, Bf;
        int gc = 0;
        for (int j=0;j<N;++j) {
            if (i & (1<<j)) {
                Af.insert(An[j]);
                Bf.insert(Bn[j]);
                ++gc;
            }
        }

        if (Af.size() == Aw.size() && Bf.size() == Bw.size()) {
            ans = max(ans, N - gc);
        }
    }
    return ans;
}

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cin>>N;
        for (int i=0;i<N;++i) {
            cin>>A[i]>>B[i];
        }

        int ans = sf();

        printf("Case #%d: %d\n", t, ans);
    }

}
