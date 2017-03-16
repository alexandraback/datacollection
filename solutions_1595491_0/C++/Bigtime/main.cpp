#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    freopen("out.out","w",stdout);
    freopen("B-small-attempt1.in","r",stdin);
    int t;
    cin>>t;
    int c=0;
    while(t--)
    {
        c++;
        int n,s,p;
        cin>>n>>s>>p;
        cout<<"Case #"<<c<<": ";
        int counter=0;
        int tem;
        for(int i=0;i<n;i++)
        {
            cin>>tem;
            if(p==0)
                continue;
            if(tem==0)
                continue;
            if(tem%3==0)
            {
                if(tem/3>=p)
                    counter++;
                else if(s>0&&(tem/3+1)>=p&&(tem/3+1)<=10)
                {
                    counter++;
                    s--;
                }
            }
            if(tem%3==1)
            {
                if(tem/3+1>=p)
                    counter++;
            }
            if(tem%3==2)
            {
                if(tem/3+1>=p)
                    counter++;
                else if(s>0&&(tem/3+2)>=p&&(tem/3+2)<=10)
                {
                    counter++;
                    s--;
                }
            }
        }
        if(p==0)
            cout<<n<<endl;
        else
            cout<<counter<<endl;
    }
    return 0;
}
