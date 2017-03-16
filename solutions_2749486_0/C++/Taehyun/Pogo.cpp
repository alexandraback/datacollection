#include<stdio.h>
#include<memory.h>
FILE*in=fopen("input.txt","r");
FILE*out=fopen("output.txt","w");
int T;
int t;
struct QUE
{
	int x,y;
	int head;
}que[8000000];
int X[4]={-1,0,0,1};
int Y[4]={0,-1,1,0};
char P[4]={'W','S','N','E'};
int Sx,Sy;
int V[1001][1001];
int Pos[1001][1001];
char Ans[101];
int main()
{
	fscanf(in,"%d",&T);
	int head,tail;
	head=tail=0;
	tail++;
	V[500][500]=1;
	int cnt=0;
	int x,y,k;
	int max=0;
	while(cnt<=201*201&&head!=tail)
	{
		x=que[head].x;
		y=que[head].y;
		if(max<V[x+500][y+500])
		{
			max=V[x+500][y+500];
		}
		for(k=0;k<4;k++)
		{
			if(-500<=x+X[k]*V[x+500][y+500]&&x+X[k]*V[x+500][y+500]<=500&&-500<=y+Y[k]*V[x+500][y+500]&&y+Y[k]*V[x+500][y+500]<=500)
			{
				if(V[x+X[k]*V[x+500][y+500]+500][y+Y[k]*V[x+500][y+500]+500]) continue;
				V[x+X[k]*V[x+500][y+500]+500][y+Y[k]*V[x+500][y+500]+500]=V[x+500][y+500]+1;
				if(-100<=x+X[k]*V[x+500][y+500]&&x+X[k]*V[x+500][y+500]<=100&&-100<=y+Y[k]*V[x+500][y+500]&&y+Y[k]*V[x+500][y+500]<=100) cnt++;
				que[tail].head=head;
				que[tail].x=x+X[k]*V[x+500][y+500];
				que[tail++].y=y+Y[k]*V[x+500][y+500];
				Pos[x+X[k]*V[x+500][y+500]+500][y+Y[k]*V[x+500][y+500]+500]=tail-1;
			}
		}
		head++;
	}
	int ac,i;
	for(t=1;t<=T;t++)
	{
		fscanf(in,"%d %d",&Sx,&Sy);
		x=Sx; y=Sy;
		ac=0;
		tail=Pos[x+500][y+500];
		memset(Ans,0,sizeof(Ans));
		while(x!=0||y!=0)
		{
			Sx=que[que[tail].head].x; Sy=que[que[tail].head].y;
			for(k=0;k<4;k++)
			{
				if(Sx+X[k]*V[Sx+500][Sy+500]==x&&Sy+Y[k]*V[Sx+500][Sy+500]==y)
				{
					Ans[ac++]=P[k];
					break;
				}
			}
			x=Sx; y=Sy;
			tail=que[tail].head;
		}
		fprintf(out,"Case #%d: ",t);
		for(i=ac-1;i>=0;i--) fprintf(out,"%c",Ans[i]);
		fprintf(out,"\n");
	}
}