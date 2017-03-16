#include <cstdio>
#include <cstring>

int n;
int bff[1024];
bool v[1024];
int mark[1024];
int len[1024];
int root[1024];
int blen[1024];

void gmax(int& a, int x)
{
	if(x>a)a=x;
}

int visit(int i, int c=0)
{
	if(v[i])return 0;
	v[i]=true;
	mark[i]=c;
	int next=bff[i]-1;
	//printf("%d next %d\n",i,next);
	if(v[next])
	{
		if(root[next]==-1)
		{
			blen[i]=len[i]=c+1-mark[next];
			root[i]=i;
			//printf("%d : %d %d %d\n",i,len[i],root[i],blen[root[i]]);
			return len[i]-1;
		}
		len[i]=len[next]+1;
		root[i]=root[next];
		gmax(blen[root[i]], len[i]);
		//printf("%d : %d %d %d\n",i,len[i],root[i],blen[root[i]]);
		return -len[i];
	}
	else
	{
		int l=visit(next, c+1);
		if(l>0)
		{
			blen[i]=len[i]=len[next];
			root[i]=i;
		}
		else
		{
			len[i]=len[next]+1;
			root[i]=root[next];
			gmax(blen[root[i]], len[i]);
		}
		//printf("%d : %d %d %d\n",i,len[i],root[i],blen[root[i]]);
		return l-1;
	}
	
}

int sumlen;
int count(int i)
{
	i=root[i];
	if(v[i])return 0;
	v[i]=true;
	for(int j=bff[i]-1;j!=i;j=bff[j]-1)
		v[j]=true;
	if(len[i]==2)
	{
		//printf("%d %d - %d %d\n",i,bff[i]-1,blen[i],blen[bff[i]-1]);
		return sumlen+=blen[i]+blen[bff[i]-1]-2;
	}
	//printf("%d - %d\n",i,len[i]);
	return len[i];
}

int main()
{
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int c=0; c<t; ++c)
	{
		scanf("%d",&n);
		for(int i=0; i<n; ++i)
			scanf("%d",&bff[i]);
		memset(v,0,sizeof(v));
		memset(root,-1,sizeof(root));
		for(int i=0; i<n; ++i)
			visit(i);
		memset(v,0,sizeof(v));
		int best=0;
		sumlen=0;
		for(int i=0; i<n; ++i)
			gmax(best,count(i));
		printf("Case #%d: %d\n",c+1,best);
	}
	return 0;
}

