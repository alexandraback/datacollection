#include <iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int qw,n,sum,ans;

int main()
{
    ifstream cin("A-small-attempt0.in");
    ofstream cout("A-small-attempt0.out");
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
