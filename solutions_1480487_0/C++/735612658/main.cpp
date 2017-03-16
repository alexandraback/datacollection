  #include <iostream>
    #include <cmath>
    #include<cstdio>
    using namespace std;
    int arr[220], n;
    bool vis[220];
    double ans[220];
    int main()
    {
        freopen("A-small-attempt4.in", "r", stdin);
        freopen("t.txt", "w", stdout);
        int cas;
        scanf("%d", &cas);
        for(int i = 1; i <= cas; i++)
        {
            scanf("%d", &n);
            for(int i = 0; i < n; i++)
                scanf("%d", arr+i);

            printf("Case #%d:", i);
            for(int i = 0; i < n; i++)
                vis[i] = false;
            int tmpn = n;
            int id, msc;


            while(true)
            {
                msc = 0;
                bool flag = false;

                int sum = 0;
                for(int i = 0; i < n ;i++)
                    sum += arr[i];
                int tsum = 0;
                for(int i = 0; i < n ;i++)
                    if(vis[i])
                        tsum += arr[i];

                for(int i = 0; i < n ;i++)
                {
                    if(vis[i])continue;

                    ans[i] = 100.0 * ( (sum*2.0 - tsum) / tmpn - arr[i]) / sum ;
                    if(ans[i] < 0)
                    {
                        if(arr[i] > msc)
                            msc = arr[i], id = i;
                        flag = true;
                    }
                }

                if(!flag)
                    break;
                else ans[id] = 0, vis[id] = true, tmpn --;
            }
            for(int i = 0; i < n; i++)
                printf(" %.6lf", ans[i]);
            printf("\n");
        }
        return 0;
    }
