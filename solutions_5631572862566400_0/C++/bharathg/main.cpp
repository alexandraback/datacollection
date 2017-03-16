#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int t,i,j,k,count,maxcount,c=1,p;
    ofstream out;
    out.open("small1.out");
    int a[1001],n;
    bool bo[1001];
    cin>>t;
    while(t--)
    {
        cin>>n;
        maxcount=0;
        for(i=1;i<=n;i++)
            cin>>a[i];

        for(i=1;i<=n;i++)
        {
            count=0;
            for(j=0;j<=n;j++)
                bo[j]=0;
            j=i;
            while(!bo[j])
            {
                bo[j]=1;
                k=j;
                j=a[j];
                count++;
            }
            p=a[k];
            bool b=0,b1=0;
            bha:
            if(i!=a[k]||b)
            for(j=1;j<=n;j++)
            {b1=1;
                if(bo[j]==0&&a[j]==k)
                {
                    count++;
                    bo[j]=1;
                    b=1;
                    k=j;
                    goto bha;
                }
            }

            //cout<<count<<endl;
            if((a[k]==i||b||(a[p]==k))&&count>maxcount)
                maxcount=count;
        }
        out<<"Case #"<<c<<": ";
            c++;
        out<<maxcount<<endl;
    }
    return 0;
}
