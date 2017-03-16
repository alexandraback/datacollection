#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int m[13][12][50];
//int fac[11] = {0, 0, 3, 2, 3, 2, 7, 2, 3, 2, 3};
int fac[11] = {0, 0, 3, 2, 5, 2, 7, 2, 9, 2, 11};
vector<string>ans;
vector<vector<int> >g;
void gao(int n, int J) {
    g.clear(); 
    int now = (m[3][2][0] + m[3][2][n - 1]) % 3;
    int f = (3 - now) % 3;
    for(int i = 1; i < n - 1; i++) {
        if(m[3][2][i] == f) {
            int flag = 1;
            for(int p = 3; p <= 10; p++) {
                int z = (fac[p] - ((m[fac[p]][p][0] + m[fac[p]][p][n - 1]) % fac[p])) % fac[p];
                if(m[fac[p]][p][i] != z) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
                vector<int> v;
                v.push_back(i);
                g.push_back(v);
            }
        }
    }

    for(int i = 1; i < n - 1; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            if((m[3][2][i] + m[3][2][j]) % 3 == f) {
                int flag = 1;
                for(int p = 3; p <= 10; p++) {
                    int z = (fac[p] - ((m[fac[p]][p][0] + m[fac[p]][p][n - 1]) % fac[p])) % fac[p];
                    if((m[fac[p]][p][i] + m[fac[p]][p][j]) % fac[p] != z) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    g.push_back(v);
                }
            }
        }
    }
    for(int i = 1; i < n - 1; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n - 1; k++) {
                if((m[3][2][i] + m[3][2][j] + m[3][2][k]) % 3 == f) {
                    int flag = 1;
                    for(int p = 3; p <= 10; p++) {
                        int z = (fac[p] - ((m[fac[p]][p][0] + m[fac[p]][p][n - 1]) % fac[p])) % fac[p];
                        if((m[fac[p]][p][i] + m[fac[p]][p][j] + m[fac[p]][p][k]) % fac[p] != z) {
                            flag = 0;
                            break;
                        }
                    }
                    if(flag) {
                        vector<int> v;
                        v.push_back(i);
                        v.push_back(j);
                        v.push_back(k);
                        g.push_back(v);
                    }
                }
            }
        }
    }
    if(g.size() < J) {
    for(int i = 1; i < n - 1; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n - 1; k++) {
                for(int l = k + 1; l < n - 1; l++) {
                    if((m[3][2][i] + m[3][2][j] + m[3][2][k] + m[3][2][l]) % 3 == f) {
                        int flag = 1;
                        for(int p = 3; p <= 10; p++) {
                            int z = (fac[p] - ((m[fac[p]][p][0] + m[fac[p]][p][n - 1]) % fac[p])) % fac[p];
                            if((m[fac[p]][p][i] + m[fac[p]][p][j] + m[fac[p]][p][k] + m[fac[p]][p][l]) % fac[p] != z) {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag) {
                            vector<int> v;
                            v.push_back(i);
                            v.push_back(j);
                            v.push_back(k);
                            v.push_back(l);
                            g.push_back(v);
                        }
                    }
                }
            }
        }
    }

    }
    //printf("%d\n", (int)g.size());
}
int main() {
    for(int i = 2; i <= 11; i++) {
        for(int j = 2; j <= 10; j++) {
            int tmp = 1;    
            for(int k = 0; k < 33; k++) {
                m[i][j][k] = tmp % i;
                tmp = tmp * j % i;
            }
        }
    }
    int T, n, J, cas = 0;
    int x[34];
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &J);
        ans.clear();
        gao(n, J);
        printf("Case #%d:\n", ++cas);
        for(int i = 0; i < J; i++) {
            memset(x, 0, sizeof(x));
            x[0] = 1; x[n - 1] = 1;
            for(int j = 0; j < g[i].size(); j++) {
                x[g[i][j]] = 1;
            }
            for(int j = n - 1; j >= 0; j--) {
                putchar('0' + x[j]);
            }
            for(int j = 2; j <= 10; j++) {
                printf(" %d", fac[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
