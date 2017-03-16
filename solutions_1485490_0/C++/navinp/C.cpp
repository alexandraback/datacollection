#include<cstdio>
#include<map>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
typedef pair<long long , long long> PL;

int N,M;
	vector<PL> v1,v2;

long long f(int x,int y)
{
	if(x==N || y==M) return 0;
	long long ans=0;
	if(v1[x].second == v2[y].second)
	{
		ans=min(v1[x].first,v2[y].first)+  f(x+1,y+1);
	}
	return max(ans,max(f(x+1,y),f(x,y+1)));
	
}

int main()
{
	int X,tc;
	scanf(" %d",&X);
	for(tc=1;tc<=X;tc++){
	scanf(" %d %d",&N,&M);
	v1.clear();v2.clear();
	int i;
	map<long long , long long> M1,M2;
	map<long long , long long>::iterator it;
	for(i=0;i<N;i++){
		long long x,y;
		scanf(" %lld %lld",&x,&y);
		v1.push_back(make_pair(x,y));
		M1[y]+=x;
	}
	for(i=0;i<M;i++){
		long long x,y;
		scanf(" %lld %lld",&x,&y);
		v2.push_back(make_pair(x,y));
		M2[y]+=x;
	}
	long long ans=f(0,0);
	for(it=M1.begin();it!=M1.end();it++)
	{
		
		ans=max(ans,min(it->second,M2[it->first]));
	}
	printf("Case #%d: %lld\n",tc,ans);
}

	return 0;
}
