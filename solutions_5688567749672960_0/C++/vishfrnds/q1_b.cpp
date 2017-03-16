
#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
using namespace std;
ll rev(ll a)
{
    ll v=a;
    int c=0,d;
    char arr[100];
    while(a)
    {
        d=a%10;
        arr[c++]=d+'0';
        a=a/10;
    }
    arr[c]='\0';
   // printf("string=%s\n",arr);
    ll val=atoi(arr);
    return val;
}
int d[1000009];
#define INF 1e9
ll brute(ll a,ll b)
{
    ll n1,n2,v2;
    ll a1=a;
    queue<pair<ll,ll> > q;
    q.push(mp(a,0));
    for(ll i=0;i<=1000000;i++)
        d[i]=INF;
    d[a]=0;
    while(!q.empty())
    {
       ll v1=q.front().first;
       ll v3=q.front().second;
        if(v1==b)
            return v3;
        q.pop();
        n1=rev(v1);
        n2=v1+1;
        if(d[n1]>d[v1]+1)
        {
            d[n1]=d[v1]+1;
            q.push(mp(n1,d[n1]));
        }
        if(d[n2]>d[v1]+1)
        {
            d[n2]=d[v1]+1;
            q.push(mp(n2,d[n2]));
        }
    }
}
int main()
{
    ll t,a,b,ans;
    cin>>t;
   	for (int tc = 1; tc <= t; tc++) {
        cin>>b;
        ans=brute(1,b);
   		cout << "Case #" << tc << ": " << ans + 1 << endl;
       // cout<<"rev1="<<rev(a)<<" ";
       //  cout<<"rev1="<<rev(b)<<"\n ";

    }
    return 0;
}
