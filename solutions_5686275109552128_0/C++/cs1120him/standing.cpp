#include <bits/stdc++.h>

using namespace std;

int f(int s_m, int ans, priority_queue <int> pq)
{
    int element = pq.top();
    while(element!=1)
    {
        ans = min(ans,s_m+element);
        s_m++;
        pq.pop();
        if(element==9)
        {
            priority_queue <int> pq1,pq2;
            while(!pq.empty())
            {
                pq1.push(pq.top());
                pq2.push(pq.top());
                pq.pop();
            }
            pq1.push(4);
            pq1.push(5);
            pq2.push(6);
            pq2.push(3);
            ans = min(ans,min(f(s_m,ans,pq1),f(s_m,ans,pq2)));
            return ans;
        }
        else
        {
            pq.push(element/2);
            pq.push(element - (element/2));
        }
        element = pq.top();
    }
    ans = min(ans,s_m+1);
    return ans;
}

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
        cout<<"Case #"<<j<<": "<<f(0,pq.top(),pq)<<endl;
    }
    return 0;
}
