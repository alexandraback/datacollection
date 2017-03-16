#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

FILE *fin  = fopen("b.in",  "r");
FILE *fout = fopen("b.out", "w");
static bool DBG = 0;

int adj[100][100];
int main() {
    int T;
    fscanf(fin, "%d", &T);
    for(int t = 1; t <= T; t++) {
        if(!DBG) fprintf(fout, "Case #%d: ", t);
        if(DBG) cout << "Case #" << t << ": ";
        ll B,M;
        fscanf(fin, "%d %lld", &B, &M);
        ll x = 0, m = M;
        while(m>1) {
            m >>= 1;
            x++;
        }
        if(DBG) cout << B << " " << M << " " << x << endl;
        if(1LL << x == M) {
            if(DBG) cout << "PWR2" << endl;
            if(B < 2 + x) {
                if(!DBG) fprintf(fout, "IMPOSSIBLE\n");
                if(DBG) cout << "IMPOSSIBLE\n";
                continue;
            } else {
                for(int i = 0; i < B - 1; i++) {
                    for(int j = 0; j <= i; j++) {
                        adj[i][j] = 0;
                    }
                    for(int j = i+1; j < B-1; j++) {
                        adj[i][j] = 1;
                    }
                    adj[i][B-1] = 0;
                }
                for(int j = 0; j < B; j++) adj[B-1][j] = 0;
                for(int i = 0; i <= x; i++) adj[i][B-1] = 1;
            }
        } else {
            if(DBG) cout << "!PWR2" << endl;
            if(B < 3 + x) {
                if(!DBG) fprintf(fout, "IMPOSSIBLE\n");
                if(DBG) cout << "IMPOSSIBLE\n";
                continue;
            } else {
                for(int i = 0; i < B - 1; i++) {
                    for(int j = 0; j <= i; j++) {
                        adj[i][j] = 0;
                    }
                    for(int j = i+1; j < B-1; j++) {
                        adj[i][j] = 1;
                    }
                    adj[i][B-1] = 0;
                }
                for(int j = 0; j < B; j++) adj[B-1][j] = 0;
                for(int i = 0; i <= x; i++) adj[i+1][B-1] = (0 != (M & (1LL << i)));
            }
        }
        if(!DBG) fprintf(fout, "POSSIBLE\n");
        if(DBG) cout << "POSSIBLE\n";
        for(int i = 0; i < B; i++) {
            for(int j = 0; j < B; j++) {
                if(!DBG) fprintf(fout, "%d", adj[i][j]);
                if(DBG) cout << adj[i][j];
            }
                if(!DBG) fprintf(fout, "\n");
                if(DBG) cout << endl;
        }
    }

    return 0;
}
