#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

#define MAXN 205
using namespace std;

struct Constestant
{
    double judge;
    bool need_vote;
    int index;

}cont[MAXN];

bool cmp(Constestant A, Constestant B)
{
    return A.judge > B.judge;
}

void process(int case_number)
{
    int N;
    scanf("%d", &N);

    double sum = 0.0, X = 0.0;

    for(int i=0;i<N;i++)
    {
        scanf("%lf", &cont[i].judge);

        sum += cont[i].judge * 2;
        X += cont[i].judge;

        cont[i].index = i;
    }

    sort(cont, cont+N, cmp);

    double ans[MAXN];
    int tmp_n = N;

    // count the minimum percentage for each constent
    for(int i=0;i<N;i++)
    {
        // no need vote
        if( cont[i].judge > sum / tmp_n)
        {
            ans[cont[i].index] = 0.0;
            sum -= cont[i].judge;
            tmp_n--;

        }else{
            ans[cont[i].index] = (sum / tmp_n - cont[i].judge) * 100.0 / X;
        }
    }

    // output
    printf("Case #%d:", case_number);
    for(int i=0;i<N;i++)
        printf(" %lf", ans[i]);
    putchar('\n');

    return ;
}
int main(int argc, char *argv[])
{
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int i=1;i<=T;i++)
        process(i);
	return 0;
}
