#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("check.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        int c,d,v;
        scanf("%d %d %d",&c,&d,&v);
        int ar[d];
        for(int i=0;i<d;i++)
        {
            scanf("%d",&ar[i]);
        }
        int m = 1<<d;
        vector <int> u;
        for(int i=1;i<m;i++)
        {
            int x = i;
            int ind = 0,sum=0;
            while(x!=0)
            {
                if(x%2)
                {
                    sum = sum + ar[ind];
                }
                x = x/2;
                ind++;
            }
            u.push_back(sum);
        }
        sort(u.begin(),u.end());
        int ans=0;
        for(int i=1;i<=v;i++)
        {
            if(!binary_search(u.begin(),u.end(),i))
            {
                ans++;
                int x = i;
                vector <int> temp;
                temp.push_back(x);
                for(int j=0;j<u.size();j++)
                {
                    temp.push_back(x+u[j]);
                }
                for(int j=0;j<temp.size();j++)
                    u.push_back(temp[j]);
                sort(u.begin(),u.end());
            }
        }
        cout<<"Case #"<<k<<": "<<ans<<endl;
    }
    return 0;
}
