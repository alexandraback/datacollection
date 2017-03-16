#include<cstdio>
#include<iostream>
#define lli long long int
using namespace std;
int main()
{
    lli tt,c,d,v,a[101],n,m,s;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>tt;
    for(int j=0;j<tt;j++)
    {
        cin>>c>>d>>v;
        for(int i=0;i<d;i++)
            cin>>a[i];

        n=0;
        s=0;
        m=1;
        for(int i=0;m<=v && i<d;m++)
        {
            if(m>=a[i])
            {
                s=s+c*a[i];
                i++;
            }
            else if(m>s)
            {
                s=s+m*c;
                n++;
            }
        }
        while(m<=v)
        {
            if(m>s)
            {
                s=s+m*c;
                n++;
            }
            m++;
        }
        cout<<"Case #"<<j+1<<": "<<n<<endl;
    }
    return 0;
}
