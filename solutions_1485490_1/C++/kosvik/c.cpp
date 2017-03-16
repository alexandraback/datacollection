// a.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
//#include <cmath>
#include <cstdlib>

using namespace std;

#define fori(i_,f_,t_) for(int i_=f_;i_<t_;++i_)
#define fore(i_,c_) for(auto i_=c_.begin();i_!=c_.end();++i_)
#define pb	push_back

typedef long long i64;


i64 ch[100][100];

vector<pair<i64,int> > as;

vector<pair<i64,int> > bs;

i64 sub(int n, int m, i64 r)
{
	if (n==(int)as.size() || m==(int)bs.size())
		return 0;
	if (r==0)
	{
		i64 x= ch[n][m];
		if (x>=0)
			return x;
		if (as[n].second == bs[m].second)
		{
			if (as[n].first > bs[m].first)
			{
				x= bs[m].first + sub(n,m+1,as[n].first - bs[m].first);
			} else 
			{
				x= as[n].first + sub(n+1,(as[n].first == bs[m].first)?m+1:m,as[n].first - bs[m].first);
			}
		} else
		{
			x=sub(n,m+1,0);
			i64 x0=sub(n+1,m,0);
			if (x0>x) x = x0;
		}

		ch[n][m]=x;
		return x;
	}

	if (r>0) // ar
	{
		i64 x=0;
		if (as[n].second == bs[m].second)
		{
			if (r > bs[m].first)
			{
				x= bs[m].first + sub(n,m+1,r - bs[m].first);
			} else 
			{
				x= r + sub(n+1,(r == bs[m].first)?m+1:m,r - bs[m].first);
			}
		} else
		{
			x=sub(n,m+1,r);
			i64 x0=sub(n+1,m,0);
			if (x0>x) x = x0;
		}
		return x;
	}

	
	i64 x=0;
	if (as[n].second == bs[m].second)
	{
		r=-r;
		if (as[n].first > r )
		{
			x= r + sub(n,m+1,as[n].first-r);
		} else 
		{
			x= as[n].first + sub(n+1,(r == as[n].first)?m+1:m,as[n].first-r);
		}
	} else
	{
		x=sub(n+1,m,r);
		i64 x0=sub(n,m+1,0);
		if (x0>x) x = x0;
	}

	return x;
}

int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	fori(t,0,T)
	{
		int N,M;
		cin>>N>>M;

		fori(n,0,N)
			fori(m,0,M)
				ch[n][m]=-1;

		
		as.clear();
		fori(n,0,N)
		{
			i64 a;
			int A;
			cin>>a>>A;
			as.pb(make_pair(a,A));
		}

		bs.clear();
		fori(m,0,M)
		{
			i64 b;
			int B;
			cin>>b>>B;
			bs.pb(make_pair(b,B));
		}
		i64 x=sub(0,0,0);
		cout<<"Case #"<<t+1<<": ";

		cout<<x<<std::endl;
	}

	return 0;
}

