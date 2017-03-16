//
// Created by Acka on 5/8/16.
//

#include <stdio.h>
#include <memory.h>

int J, P, S, K, ans, all;
int comb[1000][3], jp[100], ps[100], sj[100];
bool chk[1000];
int path[1000][1000];

bool wear(int cnt, int s, int p) {
    if(cnt == all) return true;
    if (S <= s) s -= S;

    int mp = comb[cnt][0] * 100 + comb[cnt][1] * 10 + s;
    if(chk[mp]) return false;
    else chk[mp] = true;

    bool psb = true;
    if (K < (++jp[comb[cnt][0] * 10 + comb[cnt][1]])) psb = false;
    if (K < (++ps[comb[cnt][1] * 10 + s])) psb = false;
    if (K < (++sj[s * 10 + comb[cnt][0]])) psb = false;

    if (psb) {
        if(ans <= cnt){
            ans = cnt + 1;
            path[cnt][mp] = p;
        }
        comb[cnt][2] = s;
        for(int i = 1; i <= S; i++)
            if(wear(cnt + 1, s + i, mp)) return true;
    }

    --jp[comb[cnt][0] * 10 + comb[cnt][1]];
    --ps[comb[cnt][1] * 10 + s];
    --sj[s * 10 + comb[cnt][0]];
    chk[mp] = false;
    return false;
}

int main()
{
    freopen("/Users/acka/ClionProjects/ProblemSolving/2016_Codejam_1C/C-small-attempt0.in", "r", stdin);
    freopen("/Users/acka/ClionProjects/ProblemSolving/2016_Codejam_1C/C-small-attempt0.out", "w", stdout);

    int tc, st = 1; for(scanf("%d", &tc); tc--;){
        scanf("%d %d %d %d", &J, &P, &S, &K);

        memset(jp, 0, sizeof(jp));
        memset(ps, 0, sizeof(ps));
        memset(sj, 0, sizeof(sj));
        memset(chk, 0, sizeof(chk));
        memset(path, 0xff, sizeof(path));

        for(int s = 0, idx = 0; s < S; s++)
        for(int i = 0; i < J; i++)
            for(int j = 0; j < P; j++){
                comb[idx][0] = i;
                comb[idx][1] = j;
                idx++;
            }

        all = J * P * S;
        ans = 0;
        if(wear(0, 0, 0)) ans = all;
        printf("Case #%d: %d\n", st++, ans);

        int get = 0, flag = 1;
        for(int i = 0; i < J && flag; i++)
            for(int j = 0; j < P && flag; j++)
                for(int k = 0; k < S; k++)
                    if(0 <= path[ans - 1][i * 100 + j * 10 + k]){
                        get= i * 100 + j * 10 + k;
                        flag = 0;
                        break;
                    }

        for(int i = ans - 1; 0 <= i; i--){
            printf("%d %d %d\n", get / 100 + 1, (get % 100) / 10 + 1, get % 10 + 1);
            get = path[i][get];
        }
    }
    return 0;
}
