#include<iostream>
using namespace std;

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,a,b,q,n,m,u,dig,mul,count,i;
    int x[]={9,99,999,9999,99999,999999,9999999};
    cin>>t;
    for(q=1;q<=t;q++)
    {
        cin>>a>>b;
        count=0;
        for(n=a;n<b;n++)
        {
            dig=0;
            while(n>x[dig++]);
            mul=(int)(pow(10.0,dig-1));
            u=n;
            for(i=1;i<dig;i++)
            {
                m=(u%10)*mul+(u/10);
                u=m;
                if(m==n)
                   break;
                if(m>n && m<=b)
                   count++;    
            }  
        }
        cout<<"Case #"<<q<<": "<<count<<endl;
    }
}


   
