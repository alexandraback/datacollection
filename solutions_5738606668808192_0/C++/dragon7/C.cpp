#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
ll fac(ll x)
{
	for(ll y = 2 ; y*y <= x;y++)
	{
		if(x%y==0)return y;
	}
	return -1;
}
ll f(vi v, int b)
{
	ll res = 0;
	for(int i=0;i<v.size();i++)
		res = res * b + v[i];
	return res;
}

vi val(int x)
{
	vi v;
	while(x)
	{
		v.push_back(x%2);
		x/=2;
	}
	int n = v.size();
	for(int i=n+1;i<=16;i++)
		v.push_back(0);
	reverse(v.begin(), v.end());
	return v;
}
vi valid (int x)
{
	vi res;
	vi v = val(x);
	for(int i=2;i<=10;i++)
	{
		ll x = f(v,i);
		ll y = fac(x);
		if(y == -1 )
		{
			vi fu;
			return fu;
		}
		res.push_back(y);
	}
	return res;
}
int main()
{
	int x = 1<<16;
	x--;
	int cnt = 0;
	cout<<"Case #1:"<<endl;
	for(int y = 1; y <=x; y++)
	{
		vi v = val(y);
		if(v[0]==0 || v[15]==0)continue;
		vi vv = valid(y);
		if(!vv.empty())
		{
			cnt++;
			for(int i=0;i<16;i++)
				cout<<v[i];
			cout<<" ";
			for(int i=0;i<vv.size();i++)
				cout<<vv[i]<<" ";
			cout<<endl;
			if(cnt==50)break;
		}
	}	
}
