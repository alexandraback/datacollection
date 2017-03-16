#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;

int t[110];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int nt;
    cin>>nt;
    for(int i=1; i<=nt; i++)
    {
        int n, s, p;
        cin>>n>>s>>p;
        cout<<"Case #" << i<<": ";

        for(int j=0; j<n; j++)
        {
            cin>>t[j];
        }
        int ans=0;
        for(int j=0; j<n; j++)
        {
            if(t[j]==0&&p>0)
                continue;
            if(t[j]>=(3*p-2))
                ans++;
            else if((t[j]>=3*p-4)&&s>0)
            {
                ans++;
                s--;
            }
        }
        cout<<ans<<endl;
    }
}
