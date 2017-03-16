#include <stdio.h>
#include <algorithm>

using namespace std;

struct edge_info
{
	int x;
	int y;
};
edge_info edge[1000002];

bool edgeslt(edge_info a,edge_info b)
{
	if(a.x<=b.x)
	{
		if(a.x==b.x)
			return 1;
		else
		{
			if(a.y<b.y)
				return 1;
			else
				return 0;
		}
	}
	else
		return 0;
}

int check[1002];

struct queue_info
{
	int x;
};
queue_info queue[1000002],temp,tempin;
int incnt,outcnt;

void push(queue_info x)
{
	queue[incnt++]=x;
}
queue_info pop()
{
	queue_info x;
	x=queue[outcnt++];
	return x;
}

int main()
{
	int i,j,t,tcase,cnt,re;
	int n,num[1002],pl[1002][2];

	FILE *in,*out;
	in=fopen("A-small-attempt1.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	for(t=0;t<tcase;t++)
	{
		fscanf(in,"%d",&n);
		for(i=0;i<1002;i++)
			check[i]=0;
		cnt=0;
		for(i=0;i<n;i++)
		{
			fscanf(in,"%d",&num[i]);
			pl[i][0]=cnt;
			for(j=0;j<num[i];j++)
			{
				edge[cnt].x=i+1;
				fscanf(in,"%d",&edge[cnt++].y);
			}
			pl[i][1]=cnt;
		}
		re=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<1002;j++)
				check[j]=0;
			incnt=0;
			outcnt=0;

			temp.x=i+1;
			push(temp);
			check[temp.x-1]=1;
			while(1)
			{
				if(incnt==outcnt)
					break;
				temp=pop();
				for(j=pl[temp.x-1][0];j<pl[temp.x-1][1];j++)
				{
					if(check[edge[j].y-1]==1)
					{
						re=1;
						break;
					}
					else
					{
						check[edge[j].y-1]=1;
						tempin.x=edge[j].y;
						push(tempin);
					}
				}
				if(re==1)
					break;
			}
			if(re==1)
				break;
		}

		fprintf(out,"Case #%d: ",t+1);
		if(re==0)
			fprintf(out,"No\n");
		else
			fprintf(out,"Yes\n");
	}

	return 0;
}