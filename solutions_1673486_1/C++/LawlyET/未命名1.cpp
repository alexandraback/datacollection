#include<iostream>
#include<iomanip>
using namespace std;


int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("op.txt", "w", stdout);
    int i,j,k,T,A,B;
    double p[100000],S,s;
    
    cin>>T;
    for (i=0;i<T;i++)
    {
        cin>>A>>B;
        
        memset(p,0,sizeof(p));
        for (j=0;j<A;j++) cin>>p[j];

        S=B+2;
        
        for (j=0;j<A;j++)
        {
            s=1;
            for (k=0;k<A-j;k++) s*=p[k];
            s=s*(B-A+1+j*2)+(1-s)*(2*j+2*B-A+2);
            if (s<S) S=s;
        }
        
        cout<<"Case #"<<i+1<<": "<<fixed<<setprecision(6)<<S<<endl;
    }

    return 0;
}
