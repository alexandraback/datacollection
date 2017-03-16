#include<iostream>
#include<math.h>
using namespace std;
long long int jamcoin=1;
int n;
long divisors[9];
long long power(int base,int e)
{
    long long int r = 1;
    while(e)
    {
        r=base*r;
        e--;
    }
    return r;
}
long long int convert(long long int a,int base)
{
    int i=0;
    int k;
    long long int con=0;
    do
    {
        k=a%10;
        a/=10;
        con+=k*power(base,i);
        i++;
    }
    while(a!=0);
    return con;
}
long int prime(long long int x)
{
    long int i,j;
    j=sqrt(x);

    if(x==2)
        return 1;

    if (x%2==0)
        return 2;

    for (i=3;i<=j;i+=2)
        if (x%i==0)
            return i;

    return 1;
}
int increment(long long int &a)
{
    long long int b;
    int i=0;
        do
        {
            i++;
            b=a/power(10,i);
            if(b%2==0)
            {
                a+=power(10,i);
                break;
            }
            else
            {
                a-=power(10,i);
            }
        }
        while(i<n-1);
    if(i==n-1)
    {
        return 0;
    }
    return 1;
}
int main()
{
    int t,j=0,i,flag=1,k;
    cin>>t;
    for(k=0;k<t;k++)
    {
        cin>>n;
        cin>>j;
        cout<<"Case #"<<k+1<<": ";
        jamcoin+=power(10,n-1);
        do
        {
            if(increment(jamcoin)==0)
            {
                break;
            }
            flag=1;
            for(i=2;i<=10;i++)
            {
                divisors[i-2]=prime(convert(jamcoin,i));
                if(divisors[i-2]==1)
                {
                    flag=0;
                }
            }
            if(flag)
            {
                j--;
                cout<<"\n"<<jamcoin;
                for(i=0;i<9;i++)
                {
                    cout<<" "<<divisors[i];
                }
            }
        }
        while(j);
        jamcoin=1;
    }

    return 0;
}
