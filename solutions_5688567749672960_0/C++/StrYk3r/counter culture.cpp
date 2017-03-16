#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
int rev(int n)
{
    int i=0,t=0;
    while(n)
    {
        i=i*10+n%10;
        n/=10;
    }
    return i;
}
int a[1000005]={0};
int main()
{
    int t,n,l=-1,i,j,k,f,x,c;
    ifstream IF;
    ofstream OF;
    IF.open("input.txt");
    OF.open("output.txt");
    IF>>t;
    int b[t+4];
    for(i=0;i<=20;i++)
    {
        a[i]=i;
    }
    for(j=1;j<=t;j++)
    {
        IF>>b[j];
        l=max(l,b[j]);
    }
    i=21;
    while(i<=l)
    {
        k=rev(i);
        if(k<i&&i%10!=0)
        {
            if(a[i-1]<a[k])
                a[i]=a[i-1]+1;
            else
            {
                a[i]=a[k]+1;
            }
        }
        else
            a[i]=a[i-1]+1;
           // cout<<i<<" "<<k<<" "<<a[i]<<endl;
        i++;
    }
    for(j=1;j<=t;j++)
    {
        //cout<<"Case #"<<p<<": "<<x<<endl;
        OF<<"Case #"<<j<<": "<<a[b[j]]<<endl;
    }
    IF.close();
    OF.close();
    return 0;
}


