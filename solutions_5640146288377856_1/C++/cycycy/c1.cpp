#include<iostream>
#include<algorithm>
using namespace std;


int ans[20];

int main()
{
    int T;
    cin>>T;
    for (int t=0;t<T;t++)
    {
        cout<<"Case #"<<t+1<<": ";
        int n,m,c;
        cin>>m>>n>>c;
        int ans=0;
        ans+=n/c;    
        if (n % c == 0)
            ans+=c-1;
        else
            ans+=c;
        cout<<ans*m<<"\n";
    }

}
