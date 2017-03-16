#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int MAX_ITER = 10000;
#define MP make_pair
#define A first
#define B second
#define PB push_back
#define PQTYPE vector<pair<int, pair<int, int> > >
int T, J, P, S, K, cj, cp, cs;
int jp[20][20], js[20][20], ps[20][20];
bool vis[20][20][20];

bool exist(PQTYPE& pq) {
    int j = rand() % J, p = rand() % P, s = rand() % S;
    if (jp[j][p] < K && js[j][s] < K && ps[p][s] < K && !vis[j][p][s]) {
        jp[j][p] ++ , js[j][s] ++ , ps[p][s] ++ ;
        pq.push_back(MP(j, MP(p, s)));
        vis[j][p][s] = true;
        return true;
    }
    for (j = 0; j < J; ++j)
        for (p = 0; p < P; ++ p)
            if (jp[j][p] < K)
                for (s = 0; s < S; ++ s)
                    if (js[j][s] < K && ps[p][s] < K && !vis[j][p][s]) {
                        jp[j][p] ++ , js[j][s] ++ , ps[p][s] ++ ;
                        pq.push_back(MP(j, MP(p, s)));
                        vis[j][p][s] = true;
                        return true;
                    }
    return false;
}

bool exist(PQTYPE& pq, int& jj, int& pp, int& ss) {
    int j = rand() % J, p = rand() % P, s = rand() % S;
    if (jp[j][p] < K && js[j][s] < K && ps[p][s] < K && !vis[j][p][s]) {
        vis[jj][pp][ss] = false;
        jj = j, pp = p, ss = s;
        vis[jj][pp][ss] = true;
        return true;
    }
    for (j = 0; j < J; ++j)
        for (p = 0; p < P; ++ p)
            if (jp[j][p] < K)
                for (s = 0; s < S; ++ s)
                    if (js[j][s] < K && ps[p][s] < K  && !vis[j][p][s]) {
                        if (j == jj && p == pp && s == ss) continue;
                        vis[jj][pp][ss] = false;
                        jj = j, pp = p, ss = s;
                        vis[jj][pp][ss] = true;
                        return true;
                    }
    return false;
}


void get_ans() {
    PQTYPE anspq;
    int ans = 0;
    for (int i = 0; i < 20; ++ i) {
        PQTYPE pq;
        int cnt = 0;
        memset(jp, 0, sizeof(jp));
        memset(js, 0, sizeof(js));
        memset(ps, 0, sizeof(ps));
        memset(vis, 0, sizeof(vis));
        while (exist(pq)) cnt ++ ;
       
        for (int i = 0; i < MAX_ITER; ++ i) {
            int idx = rand() % pq.size();
            pair<int, pair<int, int> > tp = pq[idx];
            int j = tp.A, p = tp.B.A, s = tp.B.B;
            jp[j][p] --, js[j][s] --, ps[p][s] --;
            if (!exist(pq, j, p, s)) {
                jp[j][p] ++, js[j][s] ++, ps[p][s] ++;
            }
            else {
                jp[j][p] ++, js[j][s] ++, ps[p][s] ++;
                pq[idx]=MP(j,MP(p,s));
                while (exist(pq)) cnt ++ ;
            }
        }
        if (cnt > ans) {
            ans = cnt;
            anspq = pq;
        }
    }
    cout<<anspq.size()<<endl;
    for (int i = 0; i < anspq.size(); ++ i) {
        int a = anspq[i].A, b = anspq[i].B.A, c = anspq[i].B.B;
        cout<<a + 1 << " " << b + 1 <<" " << c + 1 <<endl;
    }
}

int main() {
    cin>>T;
    for (int ca = 1; ca <= T; ++ ca) {
        cin>>J>>P>>S>>K;
        cout<<"Case #"<<ca<<": ";
        get_ans();
    }
    return 0;
}
