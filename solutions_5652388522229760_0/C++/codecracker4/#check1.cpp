//Author : Jatin Goyal
//codecracker4

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007  //NA
#define N 111111
#define ll long long int
#define dt int
#define all(c) c.begin(), c.end()
#define dcl(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(dt i=a;i<=(dt)(b);i++)
#define tr(container, it) for(vector<dt> ::iterator it= container.begin(); it!=container.end(); it++)
#define trp(container, it) for(vector<pair<dt,dt> >::iterator it = container.begin(); it!=container.end(); it++)
#define cc1(a)cout<<#a<<": "<<a<<endl;
#define tra(container, it) for(typeof(container.begin()) it = container.begin(); it!=container.end(); it++)
#define cc2(a,b)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<< endl;
#define cc3(a,b,c)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<<" , "<<#c<<": "<<c<<endl;
#define cc4(a,b,c,d)cout<<#a<<": "<<a<<" , "<<#b<<": "<<b<<" , "<<#c<<": "<<c<<" , "<<#d<<": "<<d<<endl;
#define pr pair<dt,dt>  //NA
#define mp(a,b) make_pair(a,b)
#define pb push_back  //NA
#define gc getchar  //NA
#define F first
#define S second
int value(int x)
{
    int cur=0;
    while(x!=0)
    {
        int ok=x%10;
        cur|=(1<<ok);
        x/=10;
    }
    return cur;
}
int main()
{
	freopen("##inp.cpp","r",stdin);

    freopen("##out.cpp","w",stdout);
	//ios_base::sync_with_stdio(0);
    int t,n;
	cin>>t;
	rep(tes,1,t)
	{
	    cin>>n;
	    cout<<"Case #"<<tes<<": ";
	    if(n==0) cout<<"INSOMNIA"<<endl;
	    else
        {
            int now=n,cur=0;
            while(3)
            {
                cur|=value(now);
                if(cur==((1<<10)-1)) break;
                now+=n;
            }
            cout<<now<<endl;
        }
	}
}
