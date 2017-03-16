#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define _ ios::sync_with_stdio(false);
#define mem(x,a) memset(x,(a),(int)(sizeof(x)))
#define pii pair<int,int>
#define fr(i,a,n) for(int i=(a);i<=(n);i++)
#define frd(i,a,n) for(int i=(a);i>=(n);i--)
#define nl cout<<endl
#define sp cout<<" "
#define pb push_back
#define mp make_pair 
#define F first 
#define S second
#define si size()
#define V vector
ll mod=1e9+7;
int main() {_
	int t;cin>>t;
	fr(Z,1,t)
	{
		string s;
		map<char,int> c;
		int a[10]={0};
		cin>>s;
		int n=s.size();
		fr(i,0,n-1)c[s[i]]++;
		if(c['G'])
		{
			int val=c['G'];
			c['G']-=val;
			c['I']-=val;
			c['H']-=val;
			c['E']-=val;
			c['T']-=val;
			a[8]+=val;
		}
		if(c['X'])
		{
			int val=c['X'];
			c['S']-=val;
			c['I']-=val;
			c['X']-=val;
			a[6]+=val;
		}
		if(c['S'])
		{
			int val=c['S'];
			c['E']-=val;
			c['E']-=val;
			c['V']-=val;
			c['N']-=val;
			c['S']-=val;
			a[7]+=val;
		}
		if(c['V'])
		{
			int val=c['V'];
			c['E']-=val;
			c['F']-=val;
			c['I']-=val;
			c['V']-=val;
			//c['T']-=val;
			a[5]+=val;
		}
		if(c['U'])
		{
			int val=c['U'];
			c['F']-=val;
			c['O']-=val;
			c['R']-=val;
			c['U']-=val;
			//c['T']-=val;
			a[4]+=val;
		}
		if(c['W'])
		{
			int val=c['W'];
			c['W']-=val;
			c['T']-=val;
			c['O']-=val;
			
			a[2]+=val;
		}
		if(c['Z'])
		{
			int val=c['Z'];
			c['Z']-=val;
			c['E']-=val;
			c['R']-=val;
			c['O']-=val;
			a[0]+=val;
		}
		if(c['R'])
		{
			int val=c['R'];
			c['T']-=val;
			c['H']-=val;
			c['R']-=val;
			c['E']-=val;
			c['E']-=val;
			a[3]+=val;
		}
		if(c['I'])
		{
			int val=c['I'];
			c['N']-=val;
			c['I']-=val;
			c['N']-=val;
			c['E']-=val;
			//c['E']-=val;
			a[9]+=val;
		}
		if(c['N'])
		{
			int val=c['N'];
			c['O']-=val;
			c['N']-=val;
			//c['R']-=val;
			//c['E']-=val;
			c['E']-=val;
			a[1]+=val;
		}
		string ans;
		fr(i,0,9)
		{
			while(a[i])ans+='0'+i,a[i]--;
		}
		cout<<"Case #"<<Z<<": ";
		cout<<ans<<endl;
	}
	
	return 0;
}