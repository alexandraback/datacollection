#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main()
{
    int t,a,n,c,op,ans,i,tc,b,a1,k;
    ifstream cin("input");
    ofstream cout("output");
    cin>>t;

    for(k=1;k<=t;k++)
    {
        cin>>a>>n;

        int m[n];

        for(i=0;i<n;i++)
        {
            cin>>m[i];
        }

        sort(m,m+n);

        c=a;

        op=0;
        ans=n;
        for(i=0;i<n;i++)
        {
            if(m[i]<c)
                c+=m[i];
            else
            {
                tc=c;
                a1=0;
                b=n-i;
                ans=min(ans,op+b);
                if(tc==1)
                {
                    op=ans;
                    break;
                }
                while(tc<=m[i])
                {
                    tc*=2;
                    tc-=1;
                    a1++;
                }

                op+=a1;
                c=tc;
                c+=m[i];
            }
        }

        cout<<"Case #"<<k<<": "<<min(ans,op)<<"\n";
    }

    return 0;
}
