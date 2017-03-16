#include <iostream>
#include <cstdio>

using namespace std;
typedef long long LL;

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int x,t;
    cin>>t;
    for(x = 1; x <= t; x++)
    {
        int a,b,k;
        LL count = 0;
        cin>>a>>b>>k;
        for(int i = 0;i < a; i++)
        {
            for(int j = 0;j < b; j++)
            {
                if((i&j) < k)
                    count++;
            }
        }
        cout<<"Case #"<<x<<": "<<count<<endl;
    }
    return 0;
}
