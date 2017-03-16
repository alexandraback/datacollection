#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<algorithm>
#include<limits>
#include<utility>
#define PB push_back
#define MP make_pair
#define _F first
#define _S second
#define PP system("PAUSE");

using namespace std;

double jp[1000], jpn[1000], sum;
int T, N;
double min1, min2;
double L, R, M;

bool check(int now){
    double test = jp[now]+M*sum;
    double tempchk = 0.0;
    for(int l = 0; l < N; l++){
        if(l == now) continue;
        if(jp[l] > test) continue;
        tempchk += test-jp[l];
        }
    if((1-M)*sum >= tempchk) return false;
    return true;
    }

int main(void){
    freopen("A-small-attempt0 (2).in", "r", stdin);
    freopen("A-small-attempt0 (2).out", "w", stdout);

    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d", &N);
        for(int j = 0; j < N; j++)
            scanf("%lf", &jp[j]);
        for(int j = 0; j < N; j++) jpn[j] = jp[j];
        sort(jpn, jpn+N);
        min1 = jpn[0], min2 = jpn[1];
        sum = 0;
        for(int j = 0; j < N; j++) sum += jp[j];
        printf("Case #%d:", i);
        for(int j = 0; j < N; j++){
            L = 0.0, R = 1.0;
            for(int k = 0; k < 200; k++){
                M = (L+R)/2;
                if(check(j)) R = M;
                else L = M+(1e-9);
                }
            printf(" %lf", M*100.0);
            }
        puts("");
        }

    return 0;
    }
