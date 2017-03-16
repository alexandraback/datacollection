#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output4.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
        int n;
        scanf("%d",&n);
        int arr[n];
        priority_queue <int> pq;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            pq.push(arr[i]);
        }
        int s_m=0;
        int element = pq.top();
        int ans = element;
        while(element!=1)
        {
            ans = min(ans,s_m+element);
            s_m++;
            pq.pop();
            if(element==9)
            {
                if(pq.empty() || pq.top()<=3)
                {
                    pq.push(6);
                    pq.push(3);
                }
                else
                {
                    pq.push(4);
                    pq.push(5);
                }
            }
            else
            {
                pq.push(element/2);
                pq.push(element - (element/2));
            }
            element = pq.top();
        }
        ans = min(ans,s_m+1);
        /*for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";*/
        cout<<"Case #"<<j<<": "<<ans<<endl;
    }
    return 0;
}
