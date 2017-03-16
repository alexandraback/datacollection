#include<iostream>
using namespace std;
long long power(int base,int e)
{
    long long int r = 1;
    while(e)
    {
        r=base*r;
        e--;
    }
    return r;
}
int main()
{
    int t,k,c,s,i,j,n,temp;
    long long int r;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>k;
        cin>>c;
        cin>>s;
        temp=k/c;
        cout<<"Case #"<<i+1<<": ";
        if(k%c!=0)
        {
            temp++;
        }
        if(temp>s)
        {
            cout<<"IMPOSSIBLE\n";
        }
        else
        {
            for(int i=1;i<=k;i+=c)
            {
                r=1;
                for(j=0;j<c;j++)
                {
                    if(i+j>k)
                    {
                        r+=(k-1)*power(k,c-j-1);
                    }
                    else
                    {
                        r+=(i+j-1)*power(k,c-j-1);
                    }
                }
                cout<<r<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
