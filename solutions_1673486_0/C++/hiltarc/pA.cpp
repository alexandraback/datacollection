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

double P[200000];
double ent;
double ans[200000];
double cor[200000];

int main(void){

    freopen("A-small-attempt1 (1).in", "r", stdin);
    freopen("A-small-attempt1 (1).out", "w", stdout);

    int T, A, B;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        scanf("%d%d", &B, &A);
        for(int j = 0; j < B; j++) scanf("%lf", &P[j]);
        for(int j = 0; j < B; j++) ans[j] = 0;
        cor[0] = P[0];
        for(int j = 1; j < B; j++) cor[j] = cor[j-1]*P[j];
        ent = 2.0+A;
        ans[0] = cor[B-1]*((A-B)+1);
        ans[0] += (1.0-cor[B-1])*(2*A-B+2);
        for(int j = 1; j <= B; j++){
            ans[j] = cor[B-j-1]*((A-B+j)+j+1);
            ans[j] += (1-cor[B-j-1])*((A-B+j)+j+1+A+1);
            }
        double res = 200000000.0;
        for(int j = 0; j < B; j++) if(res > ans[j]) res = ans[j];
        if(res > ent) res = ent;
        printf("Case #%d: %.9lf\n", i, res);
        //for(int j = 0; j < B; j++) printf("%.9lf ", ans[j]);
        //printf("%.9lf\n", ent);
        }

    return 0;
    }
