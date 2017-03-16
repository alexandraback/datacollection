#include<stdio.h>
#include<string.h>
int visited[2005][2005];
int del[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char string[5][5];
typedef struct __arb
{
  int x,y,steps;
  char str[50];
}arb;
arb queue[5000000];
int main()
{
  int x,y,steps,X,Y,t,i,j,head,tail,xx,yy,T;
  strcpy(string[0],"N");
  strcpy(string[1],"S");
  strcpy(string[2],"E");
  strcpy(string[3],"W");
  scanf("%d",&T);
  t=1;
  while(T--)
    {
      scanf("%d %d",&X,&Y);
      if(X==0 && Y==0)
	{
	  printf("Case #%d: \n",t);
	  t++;
	  continue;
	}
      for(i=0;i<=2004;i++)
	for(j=0;j<=2004;j++)
	  visited[i][j]=0;
      visited[1000][1000]=1;
      queue[0].x=0;
      queue[0].y=0;
      queue[0].steps=1;
      strcpy(queue[0].str,"");
      head=0;
      tail=1;
      while(head<tail)
	{
	  x=queue[head].x;y=queue[head].y;steps=queue[head].steps;
	  for(i=0;i<4;i++)
	    {
	      xx=x+del[i][0]*steps;
	      yy=y+del[i][1]*steps;
	      if(abs(xx)<=1000 && abs(yy)<=1000 && !visited[xx+1000][yy+1000])
		{
		  queue[tail].x=xx;
		  queue[tail].y=yy;
		  queue[tail].steps=steps+1;
		  strcpy(queue[tail].str,queue[head].str);
		  strcat(queue[tail].str,string[i]);
		  if(queue[tail].x==X && queue[tail].y==Y)
		    {
		      printf("Case #%d: %s\n",t,queue[tail].str);
		      break;
		    }
		  tail++;
		  visited[xx+1000][yy+1000]=1;
		}
	    }
	  if(i<4)
	    break;
	  head++;
	}
      //printf("Done\n");
      t++;
    }
  return 0;
}
