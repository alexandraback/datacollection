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
char no[][234]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<string>str;
int ans[10]={0};
int fun(int ct[],int ind)
{
    int cur=MOD;
    rep(i,0,str[ind].size()-1) cur=min(cur,ct[str[ind][i]-'A']);
    //cc3(cur,ind,str[ind])
    rep(i,0,str[ind].size()-1) ct[str[ind][i]-'A']-=cur;
    ans[ind]+=cur;
}

int main()
{
	freopen("##inp.cpp","r",stdin);

    freopen("##out.cpp","w",stdout);
	//ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	rep(i,0,9) str.pb(no[i]);
	rep(tes,1,t)
	{
	    cout<<"Case #"<<tes<<": ";
	    int ct[44]={0};
	    string st;
	    cin>>st;
	    rep(i,0,st.size()-1) ct[st[i]-'A']++;

	    fun(ct,0);
	    fun(ct,6);
	    fun(ct,8);
	    fun(ct,4);
	    fun(ct,2);
	    fun(ct,5);
	    fun(ct,7);
	    fun(ct,1);
	    fun(ct,9);
	    fun(ct,3);
        rep(i,0,9) while(ans[i]--) cout<<i;
        dcl(ans);
        cout<<endl;
	}
}
