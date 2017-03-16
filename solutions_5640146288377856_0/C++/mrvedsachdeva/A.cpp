#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,w,r,c;
    cin>>t;

    for(int j=1;j<=t;j++)
    {
        printf("Case #%d: ",j);
        cin>>r>>c>>w;
        if(w==1)
        {
            cout<<r*c<<endl;
        }
        else if(w==c)
        {
            cout<<r+w-1<<endl;
        }
        else
        {
            if(w>c/2)
                cout<<r+w<<endl;

            else
            {

                int k=0;
                for(i=w-1;i<c;i+=w)
                    k+=r;
                if(i-w==c-1)
                    k+=w-1;
                else if(c-(i-w)>0)
                    k+=w;

                cout<<k<<endl;
            }
        }
    }
    return 0;
}

