#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>

const int N=2000010;
const int mod=1e9+7;

using namespace std;
typedef long long ll;

#define pb push_back

struct seg
{
	int l,r;
	ll sum;
}tree[N*4];

void b_tree(int l,int r,int idx)
{
	tree[idx].l=l;
	tree[idx].r=r;
	tree[idx].sum=0;
	if(l==r) return ;
	int mid=(l+r)>>1;
	b_tree(l,mid,idx<<1);
	b_tree(mid+1,r,idx<<1|1);
}

void insert(int id,int x,int idx)
{
	tree[idx].sum+=x;
	if(tree[idx].l==tree[idx].r)	
		return ;
	int mid=(tree[idx].l+tree[idx].r)>>1;
	if(id<=mid) insert(id,x,idx<<1);
	else insert(id,x,idx<<1|1);
}

ll query(int l,int r,int idx)
{
	if(tree[idx].l==l && tree[idx].r==r)
		return tree[idx].sum;
	int mid=(tree[idx].l+tree[idx].r)>>1;
	if(r<=mid) return query(l,r,idx<<1);
	else if(l>mid) return query(l,r,idx<<1|1);
	return query(l,mid,idx<<1) + query(mid+1,r,idx<<1|1);
}

int v[N],w[N];

struct data
{
	int v,id;
	bool operator < (const data &a) const
	{
		if(v==a.v) return id>a.id;
		return v<a.v;
	}
};

int main()
{
	int ca,t=0;
	for(scanf("%d",&ca);ca--;)
	{
		int e,r,n,l=-1;
		scanf("%d%d%d",&e,&r,&n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]),w[i]=0;
		priority_queue<data> que;
		printf("Case #%d: ",++t);
		ll ret=0;
		b_tree(1,n,1);
		for(int i=0;i<n;i++)
		{
			que.push(data{v[i],i});
			if(i==n-1) continue;
			int tmp=r;
			while(tmp)
			{
				data da=que.top();
				int id=da.id;
				if(id<=l)
				{
					que.pop();
					continue;
				}
				if(w[id]==e)
				{
					que.pop();
					continue;
				}
				ll w1=w[id];
				ll w2=(id)*r + e - query(1,id+1,1);
				if(w2==0)
				{
					que.pop();
					l=id;
					continue;
				}
				if(e-w1>=tmp && w2>=tmp)
				{
					w[id]+=tmp;
					insert(id+1,tmp,1);
					ret+=1ll*v[id]*tmp;
					tmp=0;
				}
				else
				{
					ll s=min(e-w1,w2);
					w[id]+=s;
					insert(id+1,s,1);
					ret+=1ll*v[id]*s;
					tmp-=s;
				}
			}
		}
		int tmp=e;
			while(tmp)
			{
				data da=que.top();
				int id=da.id;
				if(id<=l)
				{
					que.pop();
					continue;
				}
				if(w[id]==e)
				{
					que.pop();
					continue;
				}
				ll w1=w[id];
				ll w2=(id)*r+e - query(1,id+1,1);
				if(w2==0)
				{
					que.pop();
					l=id;
					continue;
				}
				if(e-w1>=tmp && w2>=tmp)
				{
					w[id]+=tmp;
					insert(id+1,tmp,1);
					ret+=1ll*v[id]*tmp;
					tmp=0;
				}
				else
				{
					ll s=min(e-w1,w2);
					w[id]+=s;
					insert(id+1,s,1);
					ret+=1ll*v[id]*s;
					tmp-=s;
				}
			}
		printf("%I64d\n",ret);
	}
    return 0;
}