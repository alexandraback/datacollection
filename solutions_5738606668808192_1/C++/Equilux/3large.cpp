#include<iostream>
#include<math.h>
using namespace std;
int jama[33]={0};
int root[33]={0};
int temp[33]={0};
long long int divisors[9];
int n=0;
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
int sqroot(int arr[],int proot[])
{
    int i,j,m;
    m=(n/2)+1;
    for(j=n;j>n/2;j--)
    {
        proot[j]=0;
    }
    proot[(int)(n/2)]=1;
    if(n%2==0)
    {
        for(j=(n/2)-1;j>=0;j--)
        {
            proot[j]=0;
        }
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(arr[i])
            {
                proot[(int)(i/2)]=arr[i];
            }
        }

    }
    return m;
}
int increment(int arr[],int n)
{
    int i=0;
        do
        {
            i++;
            if(arr[i]==0)
            {
                arr[i]++;
                break;
            }
            else
            {
                arr[i]=0;
            }
        }
        while(i<n-1);
    if(i==n-1)
    {
        return 0;
    }
    return 1;
}
int print(int arr[],int n)
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        cout<<arr[i];
    }
    return 0;
}
long long int prime(int b)
{
    int m,j,flag=1;
    long long int mid=0,i,trem=0,rem[33]={0};
    rem[0]=1;
    m=sqroot(jama,root);
    for(i=0;i<m;i++)
    {
        mid+=power(b,root[i]);
    }
    for(i=2;i<=mid;i++)
    {
        trem=0;
        for(j=1;j<n;j++)
        {
            rem[j]=b*(rem[j-1]);
            rem[j]=rem[j]%i;

        }
        for(j=0;j<n;j++)
        {
            trem+=rem[j]*jama[j];
            trem%=i;
        }

        if(trem==0)
        {
            return i;
        }
    }
    return 1;

}
int main()
{
    jama[0]=1;
    int m=0;
    int t,j=0,i,flag=1,k;
    cin>>t;
    for(k=0;k<t;k++)
    {
        cin>>n;
        cin>>j;
        jama[n-1]=1;
        if(k>0)
        {
            cout<<"\n";
        }
        cout<<"Case #"<<k+1<<": ";
        do
        {
            flag=1;
            for(i=2;i<=10;i++)
            {
                divisors[i-2]=prime(i);
                if(divisors[i-2]==1)
                {
                    flag=0;
                }
            }
            if(flag)
            {
                j--;
                cout<<"\n";
                print(jama,n);
                for(i=0;i<9;i++)
                {
                    cout<<" "<<divisors[i];
                }
            }
            if(increment(jama,n)==0)
            {
                break;
            }
        }
        while(j);

    }
    for(i=0;i<33;i++)
    {
        jama[i]=0;
    }
    jama[0]=1;
    return 0;
}
