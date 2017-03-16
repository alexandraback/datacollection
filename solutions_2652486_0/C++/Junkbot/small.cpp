#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#undef DEBUG
#ifdef DEBUG
#define D(x...) fprintf(stderr,x)
#else
#define D(x...)
#endif

const int MAX_M = 10;

typedef long long ll;

int T, R, N, M, K;
ll setWays[MAX_M][MAX_M][MAX_M];
ll prodWays[MAX_M][MAX_M][MAX_M][130];

int prods[20];

int main() {
    scanf("%d %d %d %d %d",&T,&R,&N,&M,&K);

    for(int i=2;i<=M;i++) {
        for(int j=2;j<=M;j++) {
            for(int k=2;k<=M;k++) {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(k);

                sort(temp.begin(), temp.end());
                setWays[temp[0]][temp[1]][temp[2]]++;
            }
        }
    }

    for(int i=2;i<=M;i++) {
        for(int j=i;j<=M;j++) {
            for(int k=j;k<=M;k++) {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                temp.push_back(k);

                for(int l=0;l<(1<<N);l++) {
                    int prod = 1;
                    for(int m=0;m<N;m++) {
                        if(l & (1<<m)) {
                            prod *= temp[m];
                        }
                        prodWays[i][j][k][prod] += setWays[i][j][k];
                    }
                }
            }
        }
    }

    printf("Case #1:\n");

    for(int z=0;z<R;z++) {
        for(int j=0;j<K;j++) {
            scanf("%d",&prods[j]);
        }

        ll bestWays = 0ll;
        int bi = 2;
        int bj = 2;
        int bk = 2;

        for(int i=2;i<=M;i++) {
            for(int j=2;j<=M;j++) {
                for(int k=2;k<=M;k++) {
                    ll totWays = 1ll;
                    for(int l=0;l<K;l++) {
                        totWays *= prodWays[i][j][k][prods[l]];
                        D("prodWays[%d][%d][%d][%d] = %lld\n",i,j,k,prods[l],prodWays[i][j][k][prods[l]]);
                    }

                    if(totWays > bestWays) {
                        bi = i;
                        bj = j;
                        bk = k;
                    }
                }
            }
        }

        printf("%d%d%d\n",bi,bj,bk);
    }

    return 0;
}
