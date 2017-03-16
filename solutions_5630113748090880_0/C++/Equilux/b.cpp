#include<iostream>
#include<math.h>
using namespace std;
int o[5000];
//int sol[100];
//int soln=0;
int n=0;
int c;
void inserti(int a,int i)
{
    int j;
    for(j=c-1;j>i;j--)
    {
        o[j]=o[j-1];
    }
    o[i]=a;
    n++;
}
int main()
{
    o[0]=0;
    int t,k,i,j,a,m;
    cin>>t;
    for(i=0;i<t;i++)
    {
        n=0;
        cin>>m;
        c=m*((2*m)-1);
        for(j=0;j<c;j++)
        {
            cin>>a;
            for(k=0;k<n;k++)
            {
                if(a<o[k])
                {
                    break;
                }
            }
            inserti(a,k);
        }
        cout<<"Case #"<<i+1<<": ";
        a=o[0];
        k=1;
        for(j=1;j<c;j++)
        {
            if(o[j]==a)
            {
                k++;
            }
            else
            {
                if(k%2!=0)
                {
                    cout<<a<<" ";
                    //sol[soln]=a;
                    //soln++;
                }
                a=o[j];
                k=1;
            }
        }
        if(k%2!=0)
        {
            cout<<a<<" ";
        }

        cout<<"\n";
    }
    return 0;
}
