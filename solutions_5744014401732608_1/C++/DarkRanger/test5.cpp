#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("b2.in","r",stdin);
    freopen("out2.out","w",stdout);

    int t;
    int cases;
    int b;
    long long int m,n,x,y,j,i,k,mx;

    cin>>cases;

    t=1;
    while(t<=cases)
    {
        cin>>b>>m;

        cout<<"Case #"<<t<<": ";
        
        mx=pow(2,(b-2));

        if(m<=mx)
        {
            //possible
            cout<<"POSSIBLE";
            cout<<endl;

            x=(mx-m);

            //now, generate and print the matrix
            
            //for 1
            cout<<0;

            for(j=2;j<b;j++)
            {
                if(x & (1<<(j-2)))
                {
                    cout<<0;
                }

                else
                    cout<<1;
            }

            cout<<1<<endl;

            i=2;
            while(i<b)
            {
                cout<<0;

                for(j=2;j<i;j++)
                    cout<<1;

                cout<<0;
                
                for(j=i+1;j<b;j++)
                    cout<<0;

                cout<<1;

                cout<<endl;
                
                i++;
            }
            
            //for b
            for(j=1;j<=b;j++)
                cout<<0;

            cout<<endl; 

        }

        else
        {
            //impossible
            cout<<"IMPOSSIBLE";
            cout<<endl;
        }
       
        t++;
    }

    return 0;
}
