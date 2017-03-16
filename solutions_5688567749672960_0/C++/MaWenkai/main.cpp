#include <iostream>
#include"cmath"
#include"string"
#include"string.h"
#include <fstream>
using namespace std;
int n,m,t1,t;
int a[2000000];
int stt(int x)
{
    int y=0;
    if(x%10==0)
        return 0;
    while(x!=0)
    {
        y=y*10+x%10;
        x=x/10;
    }
    return y;
}
int min1(int x,int y)
{
    if(y==0)
        return x;
    if(x>y)
        return y;
    return x;
}
int main()
{
    ifstream cin("2.in");
    ofstream cout("2.out");
    cin>>t1;
    for (t=1;t<=t1;t++)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        a[1]=1;
        for (int i=2;i<=n;i++)
            a[i]=min1(a[i-1],a[stt(i)])+1;
        cout<<"Case #"<<t<<": "<<a[n]<<endl;
    }
    return 0;
}
