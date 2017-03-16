
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long a,b;

long exp10[] =
{
	1,
	10,
	100,
	1000,
	10000,
	100000,
	1000000,
	10000000,
};

void load()
{
	cin>>a>>b;
}

int getdigs(long n)
{
	int r=0;
	while(n)
	{
		n/=10;
		++r;
	}
	return r;
}

vector<long> gens;

int countrecy(int n,int digs)
{
	gens.clear();

	for(int i=1;i<digs;++i)
	{
		long mp=exp10[i];
		long left=n/mp;
		long right=n%mp;
		long gen = right*exp10[digs-i] + left;

		if(gen<=n)continue;
		if(gen>b)continue;

		gens.push_back(gen);
	}

	sort(gens.begin(), gens.end());

	return unique(gens.begin(),gens.end())-gens.begin();
}

void dbg()
{
	cout<<"ab "<<a<<" "<<b<<endl;
}

long solve()
{
	load();

	int digs=getdigs(a);

	long res=0;
	for(long i=a;i<b;++i)
	{
		int c=countrecy(i, digs);
		res+=c;
	}
	return res;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cout<<"Case #"<<i+1<<": "<<solve()<<endl;
	}
	return 0;
}

