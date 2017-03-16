#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;

int main() {
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int time_limits;
    cin >> time_limits;
    for (int time_count = 0; time_count < time_limits; time_count++)
    {
        printf("Case #%d: ",time_count+1);

        cin >> n;

        vector<int> edges(n,-1);
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            edges[i] = temp-1;
        }
        vector<int> dmax(n,-1);
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            vector<bool> flag(n,false);
            flag[i] = true;
            int cur = i;
            int dis = 1;
            while (!flag[edges[cur]])
            {
                cur = edges[cur];
                dis ++;
                flag[cur] = true;
            }
            dmax[cur] = max(dmax[cur],dis);
            dis = 1;
            flag = vector<bool>(n,false);
            flag[cur] = true;
            while (!flag[edges[cur]])
            {
                cur = edges[cur];
                dis ++;
                flag[cur] = true;
            }
            ans = max(ans,dis);
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (edges[edges[i]] == i)
            {
                count ++;
            }
        }
        if (ans == 2)ans = count - 2;
        for (int i = 0; i < n; i++)
        {
            if (edges[edges[i]] == i)
            {
                ans = max(ans,dmax[i]+dmax[edges[i]]+count-4);
            }
        }
        cout << ans;
        printf("\n");
    }
}