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
int fun(int no,string str)
{
    reverse(all(str));
    rep(i,0,str.size()-1)
    {
        if(str[i]=='?');
        else if(str[i]-'0'==no%10);
        else return 0;
        no/=10;
    }
    if(no!=0) return 0;
    else return 1;
}
int main()
{
	freopen("##inp.cpp","r",stdin);
    freopen("##out.cpp","w",stdout);
	//ios_base::sync_with_stdio(0);
//	cout<<funk(19,"1?");
	int t;
	cin>>t;
	rep(tes,1,t)
	{
	    cout<<"Case #"<<tes<<": ";
	    string s,t;
	    int lt,rt;
	    cin>>s>>t;
	    int diff=MOD;
	    rep(i,0,999)
	    {
	        rep(j,0,999)
	        {
	            if(fun(i,s)&&fun(j,t))
                {
  //                  cc2(i,j)
                    if(diff>abs(i-j))
                    {
                        diff=abs(i-j);
                        lt=i;rt=j;
                    }
                    else if(diff==abs(i-j))
                    {
                        if(lt>i) {lt=i; rt=j;}
                        else if(lt==i){lt=i; rt=min(rt,j);}
                        else;
                    }
                }
	        }
	    }
	    string a,b;
	    while(a.size()!=s.size()) {a.pb(lt%10+'0'); lt/=10;}
	    while(b.size()!=s.size()) {b.pb(rt%10+'0'); rt/=10;}

	    reverse(all(a));
	    reverse(all(b));
 	    cout<<a<<' '<<b<<endl;
	}
}

