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

int main()
{
	freopen("##inp.cpp","r",stdin);
    freopen("##out.cpp","w",stdout);
	//ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	rep(tes,1,t)
	{
	    int b;
	    ll m;
	    cout<<"Case #"<<tes<<": ";
	    cin>>b>>m;
	    if(b==2)
        {
            if(m==1) printf("POSSIBLE\n01\n00\n");
            else printf("IMPOSSIBLE\n");
        }
        else
        {
            ll ct[62]={0},ma[62][62]={0};
            for(int i=2;i<=b;i++)
            {
                for(int j=i+1;j<=b;j++)
                {
                    ma[i][j]=1;
                }
            }

            ct[b]=1;
            ct[b-1]=1;
            ll sum=2;
            for(int i=b-2;i>=2;i--)
            {
                ct[i]=sum;
                sum+=ct[i];
            }

            if(sum<m) cout<<"IMPOSSIBLE"<<endl;
            else
            {
                cout<<"POSSIBLE"<<endl;
                for(int i=2;i<=b;i++)
                {
                    if(ct[i]<=m)
                    {
                        m-=ct[i];
                        ma[1][i]=1;
                    }
               //     cc3(i,ct[i],m)
                }
                rep(i,1,b) {rep(j,1,b)cout<<ma[i][j];cout<<endl;}
                //cout<<endl;
            }
            //cc2(m,sum);
            //cout<<sum<<endl;
           // rep(i,2,b) cc2(i,ct[i]);
        }
	}
}

