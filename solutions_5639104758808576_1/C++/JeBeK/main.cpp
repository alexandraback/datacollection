#include <iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int qw,n,sum,ans;

int main()
{
    ifstream cin("A-large.in");
    ofstream cout("A-large.out");
    cin>>qw;
    for(int q=1;q<=qw;q++)
    {
        cin>>n;
        sum=0;
        ans=0;
        for(int i=0;i<=n;i++)
        {
            char c;
            cin>>c;
            int k=int(c-'0');
            if(sum<i)
                sum++,ans++;
            sum+=k;
        }
        cout<<"Case #"<<q<<": "<<ans<<endl;
    }
}
