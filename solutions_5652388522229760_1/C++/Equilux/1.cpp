#include<stdio.h>
#include<iostream>
using namespace std;
int mod(long long int &a)
{
    if(a<0)
    {
        a=-1*a;
    }
    return 0;
}
long long int sheep(long long int a)
{
    long long int temp;
    int b[10]={0};
    int flag=1,i=0,j=1,k;
    do
    {
        temp=a*j;
        do
        {
            k=temp%10;
            b[k]=1;
            temp/=10;
        }
        while(temp!=0);
        flag=0;
        for(i=0;i<10;i++)
        {
            if(b[i]==0)
            {
                flag=1;
            }
        }
        j++;
    }
    while(flag);
    j--;
    temp=a*j;
    return temp;
}
int main()
{
    long long int n[100];
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n[i];
    }
    for(i=0;i<t;i++)
    {
        mod(n[i]);
        if(n[i]==0)
        {
            cout<<"Case #"<<i+1<<": "<<"INSOMNIA"<<"\n";
        }
        else
        {
            cout<<"Case #"<<i+1<<": "<<sheep(n[i])<<"\n";
        }

    }
    return 0;
}
