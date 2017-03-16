#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
#define M 1000006
ll arr[M];
int solve()
{
    ll r,c,w;
    cin>>r>>c>>w;
    /*ll tm=c/2;
    ll cnt=0;
   /* if(w>=tm&&w!=c)
        cnt+=1;
    while(w<tm)
    {
        if((c%2==1)&&cnt==0)
        {
            cnt=1;
           // tm--;
            continue;
        }
        cnt+=2;
        tm-=w;
    }
    cnt+=w;
    if(w!=c)
        cnt++;*/
    ll cnt=0;
    ll start=w;
    while(start<=c)
    {
        cnt++;
        start+=w;
    }
    if(w!=1)
        cnt+=w;
    if(c%w==0&&w!=1)
        cnt--;
    return cnt;
}
int main()
{
    freopen("mn1.in","r",stdin);
    freopen("mn1.out","w",stdout);
	ll test,t;
    cin>>test;
	for(int t=1;t<=test;t++)
	{
        cout<<"Case #"<<t<<": "<<solve()<<endl;
	}
}
