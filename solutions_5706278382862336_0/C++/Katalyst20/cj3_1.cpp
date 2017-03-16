#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
long long int arr[42];
void pre()
{
    for(int i=1;i<42;i++)
        arr[i]=arr[i-1]*2;
}

bool check(long long int q)
{
    for(int i=0;i<42;i++)
    {
        if(q == arr[i])
            return true;

    }
    return false;
}

int findans(long long int p,long long int q)
{
    int c=0;
    while(p<q)
    {
        c++;
        q=q/2;
    }
    return c;
}

long long int tolowest(long long int p,long long int q)
{

    long long int c;
    while (q != 0)
    {
        c = p % q;
        p = q;
        q = c;
    }
    return p;

}

int main()
{
    arr[0]=1;
    pre();

    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    long long int p,q,l;
    int i,t,test;
    cin>>t;
    for(test=1 ;test<=t;test++)
    {
        bool ch=false;
        string s;
        p=0;
        q=0;
        cin>>s;
        bool found =false;
        for(i=0;i<s.length();i++)
        {
            if(s[i] == '/')
            {
                found =true;
                continue;
            }
            if(!found)
            {
                p=(p*10)+int(s[i]-48);
            }
            else
            {
                q=(q*10)+int(s[i]-48);
            }
        }
        //cout<<p<<" "<<q<<endl;;
        l = tolowest(p,q);
        p=p/l;
        q=q/l;
        ch=check(q);
        if(ch)
        {
            cout<<"Case #"<<test<<": "<<findans(p,q)<<endl;
        }
        else
            cout<<"Case #"<<test<<": "<<"impossible"<<endl;

    }


    return 0;
}
