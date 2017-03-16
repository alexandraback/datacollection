#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FE(a,b) for(__typeof((b).end()) a=(b).begin(); a!=(b).end(); ++a)
#define PII pair<int, int>
#define PDI pair<double, pair<int, int> >
#define x first
#define y second

using namespace std;

int N, t,lim;
long long T[600];
vector<bitset<20> > H[2][3][5][7][11];
bitset<20> B, RA, RB, G;

bool check(bitset<20> &A, bitset<20> &B){
    long long sum = 0;
    FWD(i,0,N){
        if(A.test(i))
            sum += T[i];
        if(B.test(i))
            sum -= T[i];
    }
    return sum == 0;
}

void wypisz(bitset<20> &A){
    FWD(i,0,N)
        if(A.test(i))
            printf("%lld ", T[i]);
    printf("\n");
}

bool search(){
    FWD(i,0,N){
        FWD(a,0,2)
            FWD(b,0,3)
                FWD(c,0,5)
                    FWD(d,0,7)
                        FWD(e,0,11)
                            FE(D,H[a][b][c][d][e]){
                                G = *D;
                                if(G.test(i))
                                    continue;
                                G.set(i);
                                FE(E,H[(a+T[i])%2LL][(b+T[i])%3LL][(c+T[i])%5LL][(d+T[i])%7LL][(e+T[i])%11LL])
                                    if(check(G, *E)){
                                        RA = G;
                                        RB = *E;
                                        return 1;
                                    }
                                if(H[(a+T[i])%2][(b+T[i])%3][(c+T[i])%5][(d+T[i])%7][(e+T[i])%11].size() < lim)
                                    H[(a+T[i])%2][(b+T[i])%3][(c+T[i])%5][(d+T[i])%7][(e+T[i])%11].push_back(G);
                            }
    }
    return 0;
}

int main(){
    lim = 5;
	scanf("%d", &t);
	FWD(ttt,1,t+1){
        FWD(a,0,2)
            FWD(b,0,3)
                FWD(c,0,5)
                    FWD(d,0,7)
                        FWD(e,0,11)
                            H[a][b][c][d][e].clear();

        scanf("%d", &N);
        B.reset();
        RA.reset();
        RB.reset();
        H[0][0][0][0][0].push_back(B);
        FWD(i,0,N)
            scanf("%d", &T[i]);
        if(search()){
            printf("Case #%d:\n", ttt);
            wypisz(RA);
            wypisz(RB);
        }else
            printf("Case #%d:\nImpossible\n", ttt);
    }
	return 0;
}
