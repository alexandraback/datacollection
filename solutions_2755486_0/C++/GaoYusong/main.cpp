#include <cstdio>
#include <map>
#include <vector>

using namespace std;

struct NN {
    int w, e;
    int h;

    NN(int a = 0, int b = 0, int c = 0) {
        w = a;
        e = b;
        h = c;
    }
};


int main()
{
    int T;
    int cn = 0;

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);

        map<int, vector<NN> > hh;

        for (int i = 0; i < N; i++) {
            int d, n, w, e, s, delta_d, delta_p, delta_s;

            scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &delta_d, &delta_p, &delta_s);

            for (int j = 0; j < n; j++) {
                int nd = d + delta_d * j;
                int nw = w + delta_p * j;
                int ne = e + delta_p * j;
                int ns = s + delta_s * j;
                hh[nd].push_back(NN(nw, ne, ns));
            }

        }
        map<int, int> ff;

        int ans = 0;
        for (map<int, vector<NN> >::iterator it = hh.begin(); it != hh.end(); ++it) {
            int d = it->first;
            vector<NN> &inter = it->second;

            for (int i = 0; i < inter.size(); i++) {
                int w = inter[i].w, e = inter[i].e,
                    h = inter[i].h;
                bool ok = false;
                for (int j = w; j <= e - 1; j++) {
                    if (ff[j] < h) {
                        ok = true;
                        break;
                    }
                }
                if (ok) {
                    ans++;
                }
            }


            for (int i = 0; i < inter.size(); i++) {
                int w = inter[i].w, e = inter[i].e,
                    h = inter[i].h;

                for (int j = w; j <= e - 1; j++) {
                    if (ff[j] < h) {
                        ff[j] = h;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", ++cn, ans);

    }

    return 0;
}
