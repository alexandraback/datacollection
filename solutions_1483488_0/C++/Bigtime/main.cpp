#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    freopen("out.out","w",stdout);
    freopen("C-small-attempt1.in","r",stdin);
    int t;
    cin>>t;
    int a,b;
    int n=0;
    while(t--)
    {
        n++;
        cin>>a>>b;
        cout<<"Case #"<<n<<": ";
        int counter=0;
        int digit=0;
        int tem=a;
        while(tem!=0)
        {
            digit++;
            tem/=10;
        }

        for(int i=a;i<=b;i++)
        {
            tem=i;
            for(int j=0;j<digit;j++)
            {
                int end=tem%10;
                tem=tem/10+end*pow(10,digit-1);
                if(tem>=a&&tem<=b&&tem>i)
                {
                    counter++;
                    //cout<<i<<" "<<tem<<endl;
                }
            }
        }
        cout<<counter<<endl;
    }
    return 0;
}
