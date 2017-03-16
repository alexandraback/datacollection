#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    int T,t;
    int i,j;

    int a,b,k,r;



    cin>>t;
    T=t;
    while(t--)
    {
        r=0;
        cin>>a>>b>>k;
        for (i=0;i<a;i++)
            for (j=0;j<b;j++)
            {
                int c=i&j;
                if (c<k) r++;
                //cout<<i&j<<endl;
            }


        cout<<"Case #"<<T-t<<": "<<r<<endl;

    }
    return 0;
}
