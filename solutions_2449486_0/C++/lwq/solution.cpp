#include<stdio.h>
#include<set.h>
#include<conio.h>
FILE *fin,*fout;
struct node
{
	int i,v;
};
struct cmp
{
	bool operator()(node x,node y)
	{
		if( x.v!=y.v ) return x.v<y.v;
		return x.i<y.i;
	}
};
set<node,cmp> h;
node v;
int b[1024][1024];
bool u[1024][1024];
int main()
{
	fin=fopen("b.in","r");
	fout=fopen("b.out","w");
	int tc,test;
	int m,n;
	int x,y;
	bool t;
	int a,s;
	fscanf(fin,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		h.clear();
		fscanf(fin,"%d%d",&m,&n);
		for(a=0;a<m;a++) for(s=0;s<n;s++)
		{
			fscanf(fin,"%d",&b[a][s]);
			h.insert((node){a*n+s,b[a][s]});
			u[a][s]=false;
		}
		while( h.size()>0 )
		{
			v=*h.begin();
			x=v.i/n;
			y=v.i%n;
			s=y;
			t=true;
			for(a=0;a<m;a++)
			{
				if( u[a][s]==false && b[a][s]!=b[x][y] ) t=false;
			}
			if( t==true )
			{
				for(a=0;a<m;a++)
				{
					if( u[a][s]==false )
					{
						h.erase((node){a*n+s,b[a][s]});
						u[a][s]=true;
					}
				}
				continue;
			}
			a=x;
			t=true;
			for(s=0;s<n;s++)
			{
				if( u[a][s]==false && b[a][s]!=b[x][y] ) t=false;
			}
			if( t==true )
			{
				for(s=0;s<n;s++)
				{
					if( u[a][s]==false )
					{
						h.erase((node){a*n+s,b[a][s]});
						u[a][s]=true;
					}
				}
				continue;
			}
			break;
		}
		fprintf(fout,"Case #%d: ",test);
		fprintf(fout,(h.size()==0?"YES":"NO"));
		fprintf(fout,"\n");
	}
}