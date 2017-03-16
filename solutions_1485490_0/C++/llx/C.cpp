#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long lint;

const int MAXN = 100;

typedef struct box_t {
    lint a;
    int A;
};

int N, M;
lint ans;
box_t box[MAXN+10], toy[MAXN+10];
int pos[MAXN+10];

void dfs(int id, int st) {
    if (id == N) {
        pos[N] = M+1;
        lint v[N+3];
        for (int i = 1; i <= N; i++) {
//            cout << "== " << pos[i] << " ";
            v[i] = 0;
            for (int j = pos[i-1]+1; j < pos[i]; j++) {
                if (toy[j].A == box[i].A) {
                    v[i] += toy[j].a;
                }
            }
        }
//        cout << endl;//
        
        if (N == 3 && pos[1] == pos[2] && box[1].A == box[3].A && box[1].A == toy[ pos[1] ].A) {
            v[1] += toy[ pos[1] ].a;
            if (v[1] > box[1].a) {
                v[3] += v[1] - box[1].a;
                v[1] = box[1].a;
            }
            if (v[3] > box[3].a) v[3] = box[3].a;
            lint res = v[1] + v[3];
//            cout << "same " << res << endl;///
            if (res > ans) ans = res;
            return ;
        }
        
        for (int i = 1; i < N; i++) {
            if (toy[ pos[i] ].A == box[i].A && pos[i-1] != pos[i]) {
                v[i] += toy[ pos[i] ].a;
            } else if (toy[ pos[i] ].A == box[i+1].A) {
                v[i+1] += toy[ pos[i] ].a;
            }
        }
        lint res = 0;
        for (int i = 1; i <= N; i++) {
            if (v[i] > box[i].a) {
                v[i] = box[i].a;
            } 
            res += v[i];
//            cout << v[i] << ",";//
        }
//        cout << "===" << res << endl;///
        if (res > ans) ans = res;
        
        //all last
        //st
        //last
        //mid
        return ;
    }
    for (int p = st; p <= M; p++) {
        pos[id] = p;
        dfs(id+1, p);
    }
}

int main() {
    int T;
    scanf("%d\n", &T);
    for (int ca = 1; ca <= T; ca++) {
        scanf("%d %d", &N, &M);
        
        for (int i = 1; i <= N; i++) {
            scanf("%lld %d", &box[i].a, &box[i].A);
        }
        for (int i = 1; i <= M; i++) {
            scanf("%lld %d", &toy[i].a, &toy[i].A);
        }
        int n = 1, m = 1;
        for (int i = 2; i <= N; i++) {
            if (box[i].A == box[n].A) {
                box[n].a += box[i].a;
            } else {
                n++;
                box[n].a = box[i].a;
                box[n].A = box[i].A;
            }
        }
        N = n;
        
        for (int i = 2; i <= M; i++) {
            if (toy[i].A == toy[m].A) {
                toy[m].a += toy[i].a;
            } else {
                m++;
                toy[m].a = toy[i].a;
                toy[m].A = toy[i].A;
            }
        }
        M = m;
        
        ans = 0;
        pos[0] = 0;
        dfs(1, 1);
    
        printf("Case #%d: %lld\n", ca, ans);
    }
    
    return 0;
}


