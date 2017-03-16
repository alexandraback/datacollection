#include<fstream>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<iostream>
#include<cassert>
#include<cmath>
#include<map>

#define f(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define x first
#define y second
#define mp make_pair
#define pb push_back



using namespace std;
typedef pair<pair<long long,long long>, long long> plll;
int p2[64];
map<plll,long long> memo;
long long cost(long long a, long long b, long long k)
{
	if(a<=k || b<=k) return a*b;
	if(a<b)
	{
		long long tmp=a;
		a=b;
		b=tmp;
	}
	plll id=mp(mp(a,b),k);
	if(memo.count(id)!=0)
		return memo[id];
	int ca=0,cb=0,ck=0;
	while(p2[ca]<a) ca+=1;
	while(p2[cb]<b) cb+=1;
	while(p2[ck]<k) ck+=1;
	ca-=1;
	cb-=1;
	ck-=1;
	long long ans=0;
	if(ca==cb)
	{
		if(ck==ca)
			ans=cost(a-p2[ca],b-p2[cb],k-p2[ck]);
		ans+=cost(p2[ca],p2[cb],k)+cost(p2[ca],b-p2[cb],k)+cost(p2[cb],a-p2[ca],k);
	}
	else
	{
		ans=cost(a-p2[ca],b,k)+cost(p2[ca],b,k);
	}
	memo[id]=ans;
	return ans;
}

int main()
{
	long long x=1;
	p2[0]=x;
	f(i,1,64)
	{
		x*=2;
		p2[i]=x;
	}
	ifstream fin("B-large.in");
	ofstream fout("B.out");
	int cases;
	fin>>cases;
	for(int cas=1;cas<=cases;++cas)
	{
		fout<<"Case #"<<cas<<": ";
		int a,b,k;
		fin>>a>>b>>k;
		fout<<cost(a,b,k);

		fout<<'\n';
	}
	return 0;
}
