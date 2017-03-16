#include<iostream>
using namespace std;
double p[30];
double s[30];
int main()
{
    int i,j,k;
    int t,c,n,d,N,h,m;
    c=1;
    cin>>t;
    while(t--)
    {
        n=0;
        cin>>N;
        for(i=0;i<N;i++)
        {
            cin>>d>>h>>m;
            for(j=0;j<h;j++)
            {
                p[n]=d;
                s[n]=m+j;
                n++;
            }
        }
        if(n<2)
        {
            cout<<"Case #"<<c<<": "<<0<<endl;
            c++;
            continue;
        }
        if(s[0]>s[1])
        {
            int tmp =s[0];
            s[0]=s[1];
            s[1]=tmp;
            tmp =p[0];
            p[0]=p[1];
            p[1]=tmp;
        }
        //s[0]<=s[1]
        if(s[1]*(360-p[1]) >= s[0] * (720-p[0]))
        {
            cout<<"Case #"<<c<<": "<<1<<endl;
            c++;
            continue;
        }else
        {
            cout<<"Case #"<<c<<": "<<0<<endl;
            c++;

        }
    }
}
