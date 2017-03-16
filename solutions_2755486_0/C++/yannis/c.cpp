#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>
#define wall(x) www[x+20000]

using namespace std;

int www[50000];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > p;

int success(int we, int e, int s) {
    int i;
    /* printf("attack [%d, %d] str %d\n", we, e, s); */

    for (i=we; i<e; ++i) {
        if ( wall(i) < s ) return 1;
    }

    return 0;
}

int toch[700000][3];
int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, T, i, j, ans, N;
    int d[200], n[200], w[200], e[200], s[200], delta_d[200], delta_p[200], delta_s[200];

    scanf("%d", &T);

    for (t=1; t<=T; ++t) {
        scanf("%d", &N);

        memset(www, 0, sizeof(www));

        ans = 0;

        for (i=0; i<N; ++i) {
            scanf("%d %d %d %d %d %d %d %d", &d[i], &n[i], &w[i], &e[i], &s[i],
                    &delta_d[i], &delta_p[i], &delta_s[i]);
            p.push(make_pair(d[i], i));
        }

        while(!p.empty()) {
            int day = 0;
            int cnt = 0;
            do {
                pair<int, int> cur = p.top();
                p.pop();
                int nom = cur.second;
                day = cur.first;
                n[nom]--;
                /* printf("-- %d --\n", nom); */
                if ( success(w[nom], e[nom], s[nom]) ) {
                    toch[cnt][0] = w[nom];
                    toch[cnt][1] = e[nom];
                    toch[cnt][2] = s[nom];
                    cnt++;
                    ans++;
                }
                if ( n[nom] != 0 ) {
                    d[nom] += delta_d[nom];
                    p.push(make_pair(d[nom], nom));
                    w[nom] += delta_p[nom];
                    e[nom] += delta_p[nom];
                    s[nom] += delta_s[nom];
                }
            } while(!p.empty() && p.top().first == day);
            /* printf("END OF DAY %d\n", day); */

            for (i=0; i<cnt; ++i) {
                for (j=toch[i][0]; j<toch[i][1]; ++j) {
                    wall(j) = max(wall(j), toch[i][2]);
                }
            }
        }

        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}

