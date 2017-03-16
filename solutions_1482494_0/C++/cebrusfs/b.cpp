#include<cstdio>
#include<algorithm>
#include<climits>

#define Max 1005

using namespace std;


bool vis[Max][2];
int arr[Max][2];

int main()
{
    int z;
    scanf("%d", &z);

    for(int zi=1;zi<=z;zi++)
    {
        int n;
        scanf("%d", &n);

        for(int i=0;i<n;i++)
            scanf("%d %d", &arr[i][0], &arr[i][1]);
        memset(vis, 0, sizeof(vis));

        int ans = 0, now = 0;
        while(1)
        {
            //printf("%d\n", now);

            int mi_id = -1;
            for(int i=0;i<n;i++)
                if(!vis[i][0] && !vis[i][1] 
                && arr[i][1] <= now)
                    mi_id = i;

            if(mi_id != -1)
            {
                //printf("!1 %d\n", mi_id);
                vis[mi_id][1] = 1;
                vis[mi_id][0] = 1;

                now += 2;
                ans++;
                continue;
            }


            for(int i=0;i<n;i++)
                if(vis[i][0] && !vis[i][1] && arr[i][1] <= now)
                    mi_id = i;

            if(mi_id != -1)
            {
                vis[mi_id][1] = 1;

                now += 1;
                ans++;

                continue;
            }

            int ma = -1;
            for(int i=0;i<n;i++)
                if(!vis[i][0] && arr[i][0] <= now && ma < arr[i][1])
                    mi_id = i, ma = arr[i][1];

            if(mi_id != -1)
            {
                vis[mi_id][0] = 1;

                now += 1;
                ans++;

                continue;
            }

            break;
        }
        
        for(int i=0;i<n;i++)
            if(!vis[i][1])
                ans = -1;

        printf("Case #%d: ", zi);
        if(ans == -1)
            printf("Too Bad\n");
        else
            printf("%d\n", ans);
    }
}

