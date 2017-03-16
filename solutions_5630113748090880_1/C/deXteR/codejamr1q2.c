#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    int n;
    cin>>t;
    int i,j,k,m,x=0;
    //a[99][50];
    int b[50],l;
    int z[4950];
    while(t--)
    {
        x++;
        cin>>n;
        l=(2*n-1);
        k=0;
        for(i=0;i<l;i++)
            for(j=0;j<n;j++)
            cin>>z[k++];

        l=k;
        m=0;
        sort(z,z+l);
        for(i=0;i<l;i++)
        {
            int s=z[i];
            int f=0;
            for(j=i;j<l;j++)
            {
                if(z[j]==s)
                 f++;
                 else
                 break;
            }
            i=i+f-1;
            //cout<<s<<' '<<f<<' ';
            if(f%2!=0)
                b[m++]=s;
               // cout<<s<<' '<<f<<' '<<i<<' '<<m<<endl;}
        }
		//cout<<m<<endl;
        sort(b,b+m);
        cout<<"Case #"<<x<<":";
        for(i=0;i<m;i++)
            cout<<" "<<b[i];
        cout<<endl;
    }
}
