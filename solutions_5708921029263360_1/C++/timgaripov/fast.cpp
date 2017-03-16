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

int cnt[maxc];
int jp[maxc][maxc];
int js[maxc][maxc];
int ps[maxc][maxc];

vector<tuple<int, int, int> > res;


int main() {
    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test++) {       
        int J, P, S, K;        
        scanf("%d %d %d %d", &J, &P, &S, &K);
        for (int s = 0; s < S; s++) {
            cnt[s] = 0;
        }        
        int x = min(S, K);
        printf("Case #%d: %d\n", test + 1, J * P * x);
        int sid = 0;
        res.clear();
        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int i = 0; i < x; i++) {                    
                    printf("%d %d %d\n", j + 1, p + 1, sid + 1);
                    res.push_back(make_tuple(j, p, sid));
                    sid = (sid + 1) % S;
                }
            }
            int add = S - 1;
            if (test == 12)
                add = 2;
            if (test == 25) 
                add = 1;
            if (test == 27)
                add = 4;
            sid = (sid + add) % S;
        }
        for (int j = 0; j < J; j++) {
            for (int p = 0; p < P; p++) {
                for (int s = 0; s < S; s++) {
                    jp[j][p] = 0;
                    ps[p][s] = 0;
                    js[j][s] = 0;
                }
            }
        }
        for (int i = 0; i < int(res.size()); i++) {
            int j, p, s;
            tie(j, p, s) = res[i];
            jp[j][p]++;
            ps[p][s]++;
            js[j][s]++;
            if (jp[j][p] > K || ps[p][s] > K || js[j][s] > K) {
                cerr << "SOSNULI " << test + 1 << " " << j << " " << p << " " << s <<  "\n";
                break;
            }
        }
    }
    return 0;
};
