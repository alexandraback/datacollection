#include<stdio.h>
#include<set.h>
FILE *in,*out;
struct node
{
	int i,v;
};
struct cmp
{
	bool operator()(node x,node y)
	{
		if( x.v!=y.v ) return x.v<y.v;
		if( x.i!=y.i ) return x.i<y.i;
		return false;
	}
};
set<node,cmp> h;
int main()
{
	in=fopen("a.in","r");
	out=fopen("a.out","w");
	int tc,test;
	fscanf(in,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		int x,n,i,c,v,m,a;
		node p;
		fscanf(in,"%d%d",&x,&n);
		h.clear();
		for(a=0;a<n;a++)
		{
			fscanf(in,"%d",&i);
			h.insert((node){a,i});
		}
		m=n;
		if( x>1 )
		{
			c=0;
			for(a=0;a<n;a++)
			{
				p=*h.begin();
				h.erase(p);
				i=p.v;
				while( x<=i )
				{
					x=x*2-1;
					c++;
				}
				x+=i;
				v=c+(n-1-a);
				if( v<m ) m=v;
			}
		}
		fprintf(out,"Case #%d: ",test);
		fprintf(out,"%d",m);
		fprintf(out,"\n");
	}
	return 0;
}