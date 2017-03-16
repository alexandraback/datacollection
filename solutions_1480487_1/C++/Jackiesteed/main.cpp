#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <fstream>
#include <algorithm>



using namespace std;

const int MAXN = 300;

int T;
int N;
int array[MAXN];
double ans[MAXN];
bool vis[MAXN];


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    scanf("%d", &T);

    for(int ncase = 1; ncase <= T; ncase++)
    {
        scanf("%d", &N);
        int tot = 0;
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &array[i]);
            tot += array[i];
        }
        double ave = double(tot * 2) / N;
        //cout << tot << endl;
        int bgcnt = 0;
        int cut = 0;

        for(int i = 0; i < N; i++)
        {
            if(array[i] > ave)
            {
                bgcnt++;
                cut += array[i];
                continue;
            }
        }
        //cout << cut << "cut" << endl;
        for(int i = 0; i < N; i++)
        {
            if(array[i] > ave)
            {
                ans[i] = 0.0;
                continue;
            }
            ans[i] = double(double(tot * 2 - cut) / (N - bgcnt) - array[i]) / tot;
        }
//        if(N == 1)
//        {
//            ans[0] = 0.0;
//        }
        printf("Case #%d:", ncase);
        for(int i = 0; i < N; i++)
        {
            printf(" %0.6f", ans[i] * 100);
        }
        puts("");

    }










    return 0;
}
