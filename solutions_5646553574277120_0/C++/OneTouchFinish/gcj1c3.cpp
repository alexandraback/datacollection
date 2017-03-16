#include<bits/stdc++.h>
#define rep(i,s,n) for((i)=(s);(i)<=(n);(i)++)
#define getint(x) scanf("%d",&x)
#define getlong(x) scanf("%lld",&x)
#define putint(x) printf("%d",x)
#define putintln(x) printf("%d\n",x)
#define putlong(x) printf("%lld",x)
#define putlongln(x) printf("%lld\n",x)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
	int t,c,d,v,ind,i,j;
	getint(t);
	rep(ind,1,t)
	{
		getint(c);
		getint(d);
		getint(v);
		int ar[d];
		int tr[31]={0},tr1[31]={0};
		rep(i,0,d-1)
		{
			getint(ar[i]);
			tr[ar[i]]=1;
		}
		int sub=1<<d;
		rep(i,1,sub-1)
		{
			int x=0,s=0,temp=i;
			while(x!=d)
			{
				if(temp&1)
					s+=ar[x];
				x++;
				temp/=2;
			}
			if(s<=v)
				tr1[s]=1;
		}
		int xr[31]={0};
		rep(i,1,v)
		{
			if(tr[i]==1)
				continue;
			int xrr[31]={0};
			xrr[i]=1;
			rep(j,1,v)
			{
				if(j==i||(tr1[j]!=1))
					continue;
				if(abs(j-i)<=v)
					xrr[abs(j-i)]=1;
			}
			rep(j,1,v)
				if(xrr[j])
					xr[j]++;
		}
		vector<pair<int,int> > p;
		rep(i,1,v)
			p.pb(mp(xr[i],i));
		sort(p.begin(),p.end());
		vector<pair<int,int> >::reverse_iterator it;
		int res=0;
		for(it=p.rbegin();it!=p.rend();it++)
		{
			pair<int,int> itt=*it;
			int pos=itt.second;
			if(tr1[pos])
				continue;
			rep(i,1,v)
			{
				if(tr1[i])
				{
					if(i+pos<=v)
						tr1[i+pos]=1;
				}
			}
			res++;
			rep(i,1,v)
				if(tr1[i]==0)
				break;
			if(i>v)
				break;
		}
		printf("Case #%d: %d\n",ind,res);
	}
}