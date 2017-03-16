#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#define si(i) scanf("%d",&i)
#define sl(i) scanf("%ld",&i)
#define sll(i) scanf("%lld",&i)
#ifndef ONLINE_JUDGE
    #define gc getchar
#else
    #define gc getchar_unlocked
#endif
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,a,b) for(int i=a;i>b;i--)
#define MOD 1000000007


/*inline long double log2(const long double x)
{
    return  log(x) * M_LOG2E;
}*/


using namespace std;
const int _limit=100001;
template <class T> inline T read()
{
    T ret=0;
    char c=gc();
    while(c<'0'||c>'9')
        c=gc();
    while(c>='0'&&c<='9')
    {
        ret=10*ret+c-48;
        c=gc();
    }
    return ret;
}

int main()
{
    int t=read<int>();
    rep(i,0,t)
    {
        int n, m, k;
        n=read<int>();
        m=read<int>();
        k=read<int>();
        int minimum, maximum;
        if(n<=2 || m<=2)
        {
            { cout<<"Case #"<<i+1<<": "<<k<<endl; continue; }
        }
        else
        {
            minimum=min(n,m);
            maximum=max(n,m);
            if(minimum==3)
            {
                if(maximum==3)
                {
                    if(k==5)
                    {
                        { cout<<"Case #"<<i+1<<": "<<4<<endl; continue; }
                    }
                    else
                    {
                        if(k<=8)
                            { cout<<"Case #"<<i+1<<": "<<k<<endl; continue; }
                        else
                        {
                            { cout<<"Case #"<<i+1<<": "<<8<<endl; continue; }
                        }
                    }
                }
                if(maximum==4)
                {
                    if(k==5)
                    {
                        { cout<<"Case #"<<i+1<<": "<<4<<endl; continue; }
                    }
                    else
                    {
                        if(k<=8)
                            { cout<<"Case #"<<i+1<<": "<<6<<endl; continue; }
                        if(k==9)
                            { cout<<"Case #"<<i+1<<": "<<8<<endl; continue; }
                        else
                            { cout<<"Case #"<<i+1<<": "<<k<<endl; continue; }
                    }
                }
                else
                {
                    if(k==5)
                    {
                        { cout<<"Case #"<<i+1<<": "<<4<<endl; continue; }
                    }
                    else
                    {
                        if(k<=8)
                            { cout<<"Case #"<<i+1<<": "<<6<<endl; continue; }
                        else
                        {
                            if(k<=11)
                                { cout<<"Case #"<<i+1<<": "<<8<<endl; continue; }
                            else
                            {
                                { cout<<"Case #"<<i+1<<": "<<12<<endl; continue; }
                            }
                        }
                    }
                }
            }
            if(minimum==4)
            {
                if(maximum==4)
                {
                    if(k==5)
                    {
                        { cout<<"Case #"<<i+1<<": "<<4<<endl; continue; }
                    }
                    else
                    {
                        if(k<=8)
                            { cout<<"Case #"<<i+1<<": "<<6<<endl; continue; }
                        else
                        {
                            if(k<=12)
                               { cout<<"Case #"<<i+1<<": "<<8<<endl; continue; }
                            else
                            {
                                { cout<<"Case #"<<i+1<<": "<<12<<endl; continue; }
                            }
                        }
                    }
                }
                else
                {
                    if(k==5)
                    {
                        { cout<<"Case #"<<i+1<<": "<<4<<endl; continue; }
                    }
                    else
                    {
                        if(k<=8)
                                { cout<<"Case #"<<i+1<<": "<<6<<endl; continue; }
                        else
                        {
                            {
                                if(k<=10)
                                   { cout<<"Case #"<<i+1<<": "<<8<<endl; continue; }
                                else
                                {
                                    if(k<=16)
                                        { cout<<"Case #"<<i+1<<": "<<10<<endl; continue; }
                                    else
                                        { cout<<"Case #"<<i+1<<": "<<14<<endl; continue; }
                                }
                            }
                        }
                    }
                }
            }

        }
    }
}
