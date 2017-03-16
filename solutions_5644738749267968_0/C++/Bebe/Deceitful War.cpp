#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cnt1, cnt2, N;
double a[1005], b[1005];
bool used[1005];

void solve ()
{
    cnt1 = cnt2 = 0;

    int i, j, lb = 0;
    for ( i = 0 ; i < N ; i ++)
    {
        if ( a[i] > b[lb] )
        {
            cnt1++;
            lb ++;
        }
    }

    memset(used,0,sizeof(used));
    int flag;
    for ( i = 0 ; i < N ; i ++ )
    {
        for ( flag = -1, j = 0 ; j < N ; j ++ )
        {
            if ( used[j] == false && flag == -1 ) flag = j;
            if ( a[i] < b[j] && used[j] == false )
            {
                break;
            }
        }

        if ( j == N )
        {
            cnt2 ++;
            used[flag] = true;
        }
        else
        {
            used[j] = true;
        }
    }
}

int main()
{
    freopen("D-small-attempt0.in.","r",stdin);
    freopen("Dans","w",stdout);
    int t, T, i;
    scanf("%d",&T);
    for ( t = 0 ; t < T ; t ++ )
    {
        scanf("%d",&N);
        for ( i = 0 ; i < N ; i ++ )
        {
            scanf("%lf",&a[i]);
        }
        for ( i = 0 ; i < N ; i ++ )
        {
            scanf("%lf",&b[i]);
        }

        sort(a,a+N); sort(b,b+N);

        solve();

        printf("Case #%d: %d %d\n",t+1,cnt1,cnt2);
    }


    return 0;
}
