#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for(int i=a;i<b;++i)

#define repl(i,a,b) for(long long int i=a;i<b;++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define vi vector<int>
#define sc(a) scanf("%d",&a)
#define pb(x) push_back(x)
long long int a[1000001];
long long int rev(long long int i)
{
	long long j=0;
	while(i>0)
	{
		j=j*10 + (i%10);
		i/=10;
	}
	return j;
}
string tostrg(long long x)
{
	string a;
	while(x>0)
	{
		a.pb(x%10);
		x/=10;
	}
}
int numdig(long long x)
{
	int a = 0;
	while(x>0)
	{
		x/=10;
		++a;
	}
	return a;
}
int main()
{
	int t;
	cin>>t;
	repl(i,0,1000001)a[i]=i;

	repl(i,1,1000001)
	{
		long long j = rev(i);
		a[i] = min(a[i],a[i-1]+1);
		a[j] = min(a[j],a[i]+1);
	}
	repi(t_in,1,t+1)
	{
		long long x;
		cin>>x;
	//	cout<<x<<endl;
		long long int ans = 10, cur = 10;
		if(x<10)
		{
			cout<<"Case #"<<t_in<<": "<<a[x]<<endl;
			continue;
		}
		while(numdig(cur)<numdig(x))
		{
			int nd = numdig(cur);
			ans += pow(10,nd/2) + pow(10,(nd+1)/2) - 1;
			cur *= 10;
	//		cout<<ans<<" -->cur "<<cur<<" \n";
		}
		int nd = numdig(cur);
	//	cout<<"nd "<<nd<<" ";
	//	cout<<x<<endl;
		long long mods = 1;
		for(int i=1;i<=(nd+1)/2;++i)
		{
			mods*=10;
		}
	//	cout<<mods<<endl;
		long long left = x/mods;
		long long right = x%mods;
		long long leftr = rev(left);
	//	cout<<left<<" "<<right<<" "<<leftr<<endl;
		if(cur==x)
		{

			cout<<"Case #"<<t_in<<": "<<ans<<endl;
			continue;
		}
		if(right==0)
		{
			ans += 1;
			x--;
			left = x/((long long)pow(10,(nd+1)/2));

			right = x%((long long)pow(10,(nd+1)/2));
			leftr = rev(left);

		}
		if(leftr == 1)
		{
			ans += right;
			cout<<"Case #"<<t_in<<": "<<ans<<endl;
			continue;
		}
		ans += leftr;
		ans += right;
		cout<<"Case #"<<t_in<<": "<<ans<<endl;
			continue;
	}
	return 0;
}