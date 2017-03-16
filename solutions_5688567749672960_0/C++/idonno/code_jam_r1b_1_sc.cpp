#include<bits/stdc++.h>
using namespace std;
int dig(int n);
int two(int n)
{
    int count=0;
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
int first(int n,int i)
{
    while(dig(n)-i)
    {
        n=n/10;
    }
    return n;
}
int isten(int n)
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
int left(int n)
{
    int i=0;
    int num=0;
    while(n%10!=n)
    {
        num=num*10+9;
        n=n/10;
    }
    return num;
}
int dig(int n)
{
    int i=0;
    while(n>0)
    {
        i++;
        n=n/10;
    }
    return i;
}
int extra(int n)
{
    int i=dig(n);
    if(i%2==0)
    {
        i=i/2;
        int num=10;
        i--;
        while(i--)
            num=num*10;
        return n%num;
    }
    else
    {
        int num=10;
        i=i/2;
        while(i--)
            num=num*10;
        return n%num;
    }
}
int swap_1(int n)
{
    int i=0;
    while(n!=0)
    {
        i=i*10+n%10;
        n=n/10;
    }
    return i;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int count=0;
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

