#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

typedef long long int int64;
typedef long double ext;

const int maxc = 10;

int triplets[maxc][maxc][maxc];
int jp[maxc][maxc], ps[maxc][maxc], js[maxc][maxc];

vector< tuple<int, int, int>  > tri, cur, ans;

int N;

void brute(int x, int cnt) {
    if (x == N){
        if (cur.size() > ans.size()) {
            ans.resize(cur.size());
            for (int i = 0; i < int(cur.size()); i++) {
                ans[i] = cur[i];
            }
        }
        return;
    }
    if (N - x + cnt < int(ans.size()))
        return;
    int j, p, s;
    tie(j, p, s) = tri[x];
    if (triplets[j][p][s] > 0 && jp[j][p] > 0 && ps[p][s] > 0 && js[j][s] > 0) {        
        cur.push_back(tri[x]);
        triplets[j][p][s]--;
        jp[j][p]--;
        ps[p][s]--;
        js[j][s]--;
        brute(x + 1, cnt + 1);
        triplets[j][p][s]++;
        jp[j][p]++;
        ps[p][s]++;
        js[j][s]++;
        cur.pop_back();
    }
    brute(x + 1, cnt);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test++) {       
        int J, P, S, K;        
        scanf("%d %d %d %d", &J, &P, &S, &K);
        N = J * P * S;
        tri.clear();
        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    tri.push_back(make_tuple(j, p, s));
                    triplets[j][p][s] = 1;
                    jp[j][p] = K;
                    ps[p][s] = K;
                    js[j][s] = K;
                }
            }
        }
        cur.clear();
        ans.clear();
        brute(0, 0);
        printf("Case #%d: %d\n", test + 1, int(ans.size()));
        for (int i = 0; i < int(ans.size()); i++) {
            int j, p, s;
            tie(j, p, s) = ans[i];
            printf("%d %d %d\n", j + 1, p + 1, s + 1);
        }    
    }
    return 0;
};
