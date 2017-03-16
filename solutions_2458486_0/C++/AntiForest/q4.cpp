#include <cstdio>
#include <queue>

#define MAX_M 1100000
using namespace std;

struct keySet {
    int k[45];
    keySet operator+ (keySet _a) {
        keySet _t;
        for (int i = 0; i < 45; i++) {
            _t.k[i] = k[i] + _a.k[i];
        }
        return _t;
    }
    void reset() {
        for (int i = 0; i < 45; i++) {
            k[i] = 0;
        }
    }
};

struct aWay {
    int w[25];
    int nW;
    bool operator < (const aWay &a) const {
        for (int i = 0; i < nW; i++) {
            if (w[i] != a.w[i]) {
                return w[i] < a.w[i];
            }
        }
        return false;
    }
    void add (int c) {
        w[nW++] = c;
    }
};

int T, N, K, M, nDK, pow2[25];
bool noAns;
int startK[45], cNKeys[25], sChKeys[25][45];
int cTyp[25];
keySet cKeys, sKeys, chKeys[25];
aWay tWay, bWay[MAX_M];

bool isK[205];
int reMapK[205];

queue <int> bfs;
int fro, nex;
bool seen[MAX_M];
    

void reset() {
    for (int i = 0; i <= M; i++) {
        seen[i] = false;
    }
    for (int i = 1; i <= 200; i++) {
        isK[i] = false;
    }
    sKeys.reset();
    for (int i = 0; i < N; i++) {
        chKeys[i].reset();
    }
    noAns = false;
    scanf ("%d %d", &K, &N);
    for (int i = 0; i < K; i++) {
        scanf ("%d", &startK[i]);
        isK[startK[i]] = true;
    }
    for (int i = 0; i < N; i++) {
        scanf ("%d", &cTyp[i]);
        scanf ("%d", &cNKeys[i]);
        for (int p = 0; p < cNKeys[i]; p++) {
            scanf ("%d", &sChKeys[i][p]);
            isK[sChKeys[i][p]] = true;
        }
    }
    M = (1 << N) - 1;
    seen[0] = true;
    bfs.push (0);
    return;
}

void mapKeys() {
    nDK = 0;
    for (int i = 1; i <= 200; i++) {
        if (isK[i]) {
            reMapK[i] = nDK;
            nDK++;
        }
    }
    for (int i = 0; i < K; i++) {
        sKeys.k[reMapK[startK[i]]]++;
    }
    for (int i = 0; i < N; i++) {
        for (int p = 0; p < cNKeys[i]; p++) {
            chKeys[i].k[reMapK[sChKeys[i][p]]]++;
        }
    }
    return;
}
    

int main() {
    freopen ("q4.in", "r", stdin);
    freopen ("q4.out", "w", stdout);
    pow2[0] = 1;
    for (int i = 1; i < 25; pow2[i]=2*pow2[i-1], i++);
    scanf ("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        printf ("Case #%d: ", tc);
        reset();
        mapKeys();
        for (int i = 0; i < N; i++) {
            if (!isK[cTyp[i]]) {
                noAns = true;
                break;
            }
        }
        if (noAns) {
            printf ("IMPOSSIBLE\n");
            continue;
        }
        for (int i = 0; i < N; i++) {
            cTyp[i] = reMapK[cTyp[i]];
            chKeys[i].k[cTyp[i]]--;
        }
        /*for (int i = 0; i < N; i++) {
            for (int p = 0; p < nDK; p++) {
                printf ("%d %d: %d\n", i, p, chKeys[i].k[p]);
            }
        }*/
        while (!bfs.empty() ) {
            fro = bfs.front();
            //printf ("FRO: %d\n", fro);
            bfs.pop();
            cKeys = sKeys;
            for (int i = 0; i < N; i++) {
                if (fro & pow2[i]) {
                    cKeys = chKeys[i] + cKeys;
                }
            }
            /*for (int i = 0; i < nDK; i++) {
                printf ("%d: %d\n", i, cKeys.k[i]);
            }*/
            for (int i = 0; i < N; i++) {
                if (!(fro & pow2[i]) ) {
                    if (cKeys.k[cTyp[i]]) {
                        nex = fro | pow2[i];
                        //printf ("Nex: %d %d %d\n", nex, fro, pow2[i]);
                        tWay = bWay[fro];
                        tWay.add (i);
                        if (!seen[nex]) {
                            seen[nex] = true;
                            bWay[nex] = tWay;
                            bfs.push (nex);
                        } else {
                            if (tWay < bWay[nex]) {
                                bWay[nex] = tWay;
                            }
                        }
                    }
                }
            }
        }
        if (!seen[M]) {
            printf ("IMPOSSIBLE");
        } else {
            for (int i = 0; i < N; i++) {
                printf ("%d ", bWay[M].w[i]+1);
            }
        }
        printf ("\n");
    }
    return 0;
}
                            
