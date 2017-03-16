#include<iostream>
#include<cstdio>

using namespace std;


int main()
{
    int t,n;
    int *s;
    int x;
    double *ans;
    double dist;
    int nonzeros;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        nonzeros = n;
        s = new int[n];
        ans = new double[n];
        dist=0;
        x=0;
        for(int j=0;j<n;j++)
        {
            cin>>s[j];
            x+=s[j];
        }
        int temp = 2*x;
        cout<<"Case #"<<i<<":";
        for(int j=0;j<n;j++)
        {
            ans[j] = (2*x - s[j]*n)*100 / (float)(n*x);
            //cout<<" "<<ans;
            if(ans[j] < 0)
            {
                nonzeros--;
                //dist += -(ans[j]);
                temp -= s[j];
                ans[j] = 0;
            }


        }

        dist = dist/nonzeros;
        for(int j=0;j<n;j++)
        {
           //ans[j] = (2*x - s[j]*n)*100 / (float)(n*x);
            //cout<<" "<<ans;

            if(ans[j] > 0)
            {
                ans[j] = (temp - s[j]*nonzeros)*100 / (float)(nonzeros*x);
                //nonzeros--;
                //dist += -(ans[j]);
                //ans[j] += dist;
            }


        }

        for(int j=0;j<n;j++)
        {
            printf(" %.8f",ans[j]);
        }
        cout<<endl;
        delete[] s;
        delete[] ans;

    }

    return 0;
}
