#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define Min(x,y) ((x)<(y)?(x):(y))
#define Max(x,y) ((x)>(y)?(x):(y))

using std::sort;

#define N 10005

FILE *in=fopen("B-small-attempt0.in","rt");
FILE *out=fopen("B-small-attempt0.out","wt");

__int64 E,R,n;
__int64 left[N],right[N],st[N][2],top;
__int64 Limit[N],Init[N];

struct data
{
	__int64 x;
	__int64 v;
}a[N];

void input()
{
	int i;
	fscanf(in,"%I64d %I64d %I64d",&E,&R,&n);
	for(i=1;i<=n;i++)
	{
		fscanf(in,"%I64d",&a[i].v);
		a[i].x=i;
	}
}

int st_push_l(int i)
{
	while(st[top][0]<=a[i].v) top--;
	st[++top][0]=a[i].v;
	st[top][1]=i;
	return st[top-1][1];
}

int st_push_r(int i)
{
	while(st[top][0]<a[i].v) top--;
	st[++top][0]=a[i].v;
	st[top][1]=i;
	return st[top-1][1];
}

bool compare(data x, data y)
{
	return (y.v<x.v || x.v==y.v && y.x<x.x);
}

void process()
{
	int i,l,r,limit,init;
	__int64 sum=0;

	memset(Init,0,sizeof(Init));
	memset(Limit,0,sizeof(Limit));

	Limit[0]=E;

	st[0][0]=1000000000;
	st[0][1]=0;
	top=0;
	for(i=1;i<=n;i++) left[i]=st_push_l(i);

	st[0][0]=1000000000;
	st[0][1]=n+1;
	top=0;
	for(i=n;i>=1;i--) right[i]=st_push_r(i);

	sort(a+1,a+n+1,compare);

	for(i=1;i<=n;i++)
	{
		l=left[a[i].x];
		r=right[a[i].x];
		init=Min(E,Limit[l]+(a[i].x-l)*R);
		limit=Max(0,Init[r]-(r-a[i].x)*R);
		sum+=(init-limit)*a[i].v;
		Limit[a[i].x]=limit;
		Init[a[i].x]=init;
	}
	fprintf(out,"%I64d",sum);
}

int main()
{
	int t,i;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fprintf(out,"Case #%d: ",i);
		input();
		process();
		fprintf(out,"\n");
	}


	fclose(in);
	fclose(out);
	return 0;
}