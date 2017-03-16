#include<bits/stdc++.h>
using namespace std;
long long int dig(long long int n);
long long int two(long long int n)
{
    long long int count=0;
    if(n<=20)
        return n;
    else
    {
        count+=10;
        count+=(n-1)/10;
        count++;
        if(n%10==0)
        {
            count+=9;
        }
        else
            count+=n%10-1;
    }
    return count;
}
long long int first(long long int n,long long int i)
{
    while(dig(n)-i)
    {
        n=n/10;
    }
    return n;
}
long long int isten(long long int n)
{
    if(n==1)
        return 1;
    while(n%10==0&&n>0)
    {
        n=n/10;
    }
    if(n==1)
        return 1;
    else
        return 0;
}
long long int left(long long int n)
{
    long long int i=0;
    long long int num=0;
    while(n%10!=n)
    {
        num=num*10+9;
        n=n/10;
    }
    return num;
}
long long int dig(long long int n)
{
    long long int i=0;
    while(n>0)
    {
        i++;
        n=n/10;
    }
    return i;
}
long long int extra(long long int n)
{
    long long int i=dig(n);
    if(i%2==0)
    {
        i=i/2;
        long long int num=10;
        i--;
        while(i--)
            num=num*10;
        return n%num;
    }
    else
    {
        long long int num=10;
        i=i/2;
        while(i--)
            num=num*10;
        return n%num;
    }
}
long long int swap_1(long long int n)
{
    long long int i=0;
    while(n!=0)
    {
        i=i*10+n%10;
        n=n/10;
    }
    return i;
}
int main()
{
    long long int t;
    cin>>t;
    for(long long int i=0;i<t;i++)
    {
        long long int n;
        cin>>n;
        long long int count=0;
        if(n%100!=n)
        {
            if(n%10==0)
            {
                count++;
                n--;
            }
            while(n%100!=n)
            {
                //cout<<first(n,dig(n)/2)<<endl;
                if(isten(first(n,dig(n)/2))==1)
                {
                    count+=n-left(n);
                    //cout<<left(n);
                }
                else
                {
                    count+=swap_1(first(n,dig(n)/2));
                    count++;
                    count++;
                    count+=extra(n)-1;
                    //cout<<extra(n)<<endl<<n<<endl;
                }
                n=left(n);
            }
            count+=two(n);
        }
        else
            count+=two(n);
        cout<<"Case #"<<i+1<<": "<<count<<endl;
    }
    return 0;
}

