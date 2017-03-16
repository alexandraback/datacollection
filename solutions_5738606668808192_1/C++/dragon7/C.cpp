#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
bool f(vi v, int b,int x)
{
	ll res = 0;
	for(int i=0;i<v.size();i++)
		res = (res * b + v[i])%x;
	return res==0;
}

ll fac(vi v,int b)
{
	for(ll y = 2 ; y<=100000;y++)
	{
		if(f(v,b,y))return y;
	}
	return -1;
}

vi sol(vi v)
{
	vi res;
	for(int i=2;i<=10;i++)
	{
		ll y = fac(v,i);
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
	srand(time(NULL));
	int cnt = 0;
	cout<<"Case #1:"<<endl;
	for(;;)
	{
		vi v ;
		v.push_back(1);
		for(int i=2;i<=31;i++)
			v.push_back(rand()%2);
		v.push_back(1);
		vi vv = sol(v);
		if(!vv.empty())
		{
			cnt++;
			for(int i=0;i<32;i++)
				cout<<v[i];
			cout<<" ";
			for(int i=0;i<vv.size();i++)
				cout<<vv[i]<<" ";
			cout<<endl;
			if(cnt==500)break;
		}
	}	
}
