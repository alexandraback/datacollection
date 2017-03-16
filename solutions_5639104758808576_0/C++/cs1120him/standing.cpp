#include <bits/stdc++.h>

using namespace std;

char c[1001];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",&c);
        int count=0;
        int val=c[0]-'0';
        for(int i=1;i<=n;i++)
        {
            if(val<i)
            {
                count = count + (i-val);
                val = i;
            }
            val = val + (c[i]-'0');
        }
        cout<<"Case #"<<j<<": "<<count<<endl;
    }
}
