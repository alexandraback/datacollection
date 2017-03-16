#include<stdio.h>
#include<memory.h>
FILE*in=fopen("input.txt","r");
FILE*out=fopen("output.txt","w");
int T;
struct LIST
{
	int x,y;
	bool operator()(LIST a,LIST b)
	{
		if(a.x!=b.x) return a.x<b.x;
		if(a.y!=b.y) return a.y<b.y;
	}
}list[500001];
int In[2001];
bool V[2001];
int Index[2001];
struct LIST2
{
	int x;
	int y[2001];
	bool V[2001];
}list2[2001];
int main()
{
	int N,M;
	fscanf(in,"%d",&T);
	int t;
	int i,c,x,j,k,l;
	int Min,flag;
	for(t=1;t<=T;t++)
	{
		fscanf(in,"%d",&N);
		M=0;
		for(i=1;i<=N;i++)
		{
			list2[i].x=V[i]=In[i]=0;
			memset(list2[i].V,0,sizeof(list2[i].V));
		}
		for(i=1;i<=N;i++)
		{
			fscanf(in,"%d",&c);
			while(c--)
			{
				fscanf(in,"%d",&x);
				list[++M].x=i;
				list[M].y=x;
				In[x]++;
			}
		}
		int C=0;
		int Ans=0;
		for(i=1;i<=N;i++)
		{
			if(In[i]==0)
			{
				list2[i].y[list2[i].x++]=++C;
				list2[i].V[C]=1;
			}
		}
		for(i=M;i>=1;i--) Index[list[i].x]=i;
		for(i=1;i<=N;i++)
		{
			flag=0;
			for(j=1;j<=N;j++)
			{
				if(V[j]) continue;
				if(In[j]==0) break;
			}
			x=j;
			V[x]=1;
			for(j=Index[x];j<=M;j++)
			{
				if(list[j].x!=x) break;
				for(l=0;l<list2[x].x;l++)
				{
					k=list2[x].y[l];
					if(list2[list[j].y].V[k])
					{
						Ans=1;
						break;
					}
					list2[list[j].y].V[k]=1;
					list2[list[j].y].y[list2[list[j].y].x++]=k;
				}
				In[list[j].y]--;
				if(Ans==1) break;
			}
			if(Ans==1) break;
		}
		fprintf(out,"Case #%d: ",t);
		if(Ans) fprintf(out,"Yes\n");
		else fprintf(out,"No\n");
	}
}