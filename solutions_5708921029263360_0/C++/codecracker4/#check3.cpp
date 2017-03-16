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
vector<pair<pr,int> >vec;
int ct;
int possible(int mid)
{
    int cur=vec.size();

    rep(i,0,(1<<cur)-1)
    {
        if(__builtin_popcount(i)==mid)
        {
            int ma[4][4][4]={0},fg=0;
            rep(j,0,cur-1)
            {
                if((1<<j)&i)
                {
                    int x=vec[j].F.F,y=vec[j].F.S,z=vec[j].S;
                    ma[x][y][0]++;
                    if(ma[x][y][0]==ct+1) fg=1;
                    ma[0][y][z]++;
                    if(ma[0][y][z]==ct+1) fg=1;
                    ma[x][0][z]++;
                    if(ma[x][0][z]==ct+1) fg=1;
                }
            }

            if(fg==0)
            {
                return i;
            }

        }
    }
    return 0;
}
int main()
{
	freopen("##inp.cpp","r",stdin);
    freopen("##out.cpp","w",stdout);
	//ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	rep(tes,1,t)
	{
	    cout<<"Case #"<<tes<<": ";
	    int jac,p,s;
	    cin>>jac>>p>>s>>ct;
	    rep(i,1,jac)
	    {
	        rep(j,1,p)
	        {
	            rep(k,1,s)
	            {
       //             cc3(i,j,k)
	                vec.pb(mp(mp(i,j),k));
	            }
	        }
	    }
	    int l=1,r=jac*p*s,ans=0;
	    while(l<=r)
        {
            int mid=(l+r)/2;
            if(possible(mid)) {ans=mid;l=mid+1;}
            else r=mid-1;
        }
        int cur=possible(ans);

        cout<<ans<<endl;
        rep(i,0,vec.size()-1)
        {
            if((1<<i)&cur) printf("%d %d %d\n",vec[i].F.F,vec[i].F.S,vec[i].S);
        }

        vec.clear();
	}
}

