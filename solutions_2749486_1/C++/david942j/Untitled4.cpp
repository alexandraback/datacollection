#include <cstdio>
bool rx,ry;
int sta[4000],ans;
bool calc(int need,int rc)
{
	for(int i=ans;i>=1;i--)
		if(need >=i && sta[i]==0){
			need-=i;
			sta[i]=rc;
		}
	if(need!=0){
		//fprintf(stderr,"QAQ");
		return false;
	}
	return true;
}
void search(int sum,int x,int y,int minus)
{
	//printf("%d %d %d %d\n",sum,x,y,minus);
	
	if(!calc(minus,-1) || !calc(y,2))
	{
		for(int i=1;i<=ans;i++)
			sta[i]=0;
		if(!calc(minus,-2) || !calc(x,1))
		{
			fprintf(stderr,"QAQ");
		}
		else{
			for(int i=1;i<=ans;i++)
			if(sta[i]==0)
				sta[i]=2;
		}
	}
	else
		for(int i=1;i<=ans;i++)
			if(sta[i]==0)
				sta[i]=1;
}
void checkans(int x,int y)
{
	for(int i=1;i<=ans;i++)
		if(sta[i]==1)
			x-=i;
		else if(sta[i]==-1)
			x+=i;
		else if(sta[i]==2)
			y-=i;
		else y+=i;
	if(x!=0||y!=0)fprintf(stderr,"QAQ");
}
int main()
{
	int T,w=1;
	scanf("%d",&T);
	while(T--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<0)rx=true,x=-x;
		else rx=false;
		if(y<0)ry=true,y=-y;
		else ry=false;
		int now=0;
		ans=0;
		while(now<x+y)
			now+=++ans;
		while((now - (x+y))%2==1)now+=++ans;
		//printf("%d\n",ans);
		for(int i=ans;i>=1;i--)
			sta[i]=0;
		int minus = now-(x+y);
		minus/=2;
		search(now,x,y,minus);
		checkans(x,y);
		if(rx)
			for(int i=1;i<=ans;i++)
				if(sta[i]==1||sta[i]==-1)
					sta[i]*=-1;
		if(ry)
			for(int i=1;i<=ans;i++)
				if(sta[i]==2||sta[i]==-2)
					sta[i]*=-1;
		printf("Case #%d: ",w++);
		for(int i=1;i<=ans;i++)
			if(sta[i]==1)
				putchar('E');
			else if(sta[i]==2)
				putchar('N');
			else if(sta[i]==-1)
				putchar('W');
			else putchar('S');
		puts("");
	}
}
