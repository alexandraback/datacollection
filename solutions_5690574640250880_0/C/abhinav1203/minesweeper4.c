#include<stdio.h>
int neigh[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int sel[30];
char cnf[10][10];
int R,C;
int visited[10][10];
int answerFound;
void dfs(int x,int y)
{
  int value,X,Y,i;
  visited[x][y]=1;
  value=0;
  for(i=0;i<8;i++)
    {
      X=x+neigh[i][0];
      Y=y+neigh[i][1];
      if(X>=0 && X<R && Y>=0 && Y<C && cnf[X][Y]=='*')
	value++;
    }
  if(value==0)
    {
      for(i=0;i<8;i++)
	{
	  X=x+neigh[i][0];
	  Y=y+neigh[i][1];
	  if(X>=0 && X<R && Y>=0 && Y<C && visited[X][Y]==0)
	    dfs(X,Y);
	}
    }
}
void choose(int curr,int R,int C,int M)
{
  int i,j,x,y,k;
  if(answerFound)return;
  //printf("%d\n",curr);
  if(curr==R*C && M==0) 
   {
     /*
      for(i=0;i<R*C;i++)
	printf("%d",sel[i]);
      printf("\n");
     */
      for(i=0;i<R;i++)
	for(j=0;j<C;j++)
	  cnf[i][j]='.';
      for(i=0;i<R*C;i++)
	{
	  if(sel[i])
	    cnf[i/C][i%C]='*';
	}
      /*
      for(i=0;i<R;i++)
	{
	  for(j=0;j<C;j++)
	    printf("%c",cnf[i][j]);
	  printf("\n");
	}
      */
      for(i=0;i<R;i++)
	{
	  for(j=0;j<C;j++)
	    {
	      for(k=0;k<8;k++)
		{
		  x=i+neigh[i][0];
		  y=j+neigh[i][1];
		  if(x>=0 && x<R && y>=0 && y<C && cnf[x][y]=='*')
		    break;
		}
	      if(cnf[i][j]=='*')
		continue;
	      if(k>=8)
		break;
	    }
	  if(j<C)
	    break;
	}
      if(i<R)
	{
	  x=i;y=j;
	  for(i=0;i<R;i++)
	    for(j=0;j<C;j++)
	      visited[i][j]=0;
	  dfs(x,y);
	  for(i=0;i<R;i++)
	    {
	      for(j=0;j<C;j++)
		if(cnf[i][j]!='*' && !visited[i][j])
		  break;
	      if(j<C)
		break;
	    }
	  if(i>=R)
	    {
	      answerFound=1;
	      for(i=0;i<R;i++)
		{
		  for(j=0;j<C;j++)
		    if(i==x && j==y)
		      printf("c");
		    else 
		      printf("%c",cnf[i][j]);
		  printf("\n");
		}
	    }
	}
      return;
    }
  if(M>0)
    {
      sel[curr]=1;
      choose(curr+1,R,C,M-1);
      sel[curr]=0;
    }
  if(R*C-curr>M)
    {
      sel[curr]=0;
      choose(curr+1,R,C,M);
      sel[curr]=1;
    }
}
int main()
{
  int T,M,test=1;
  scanf("%d",&T);
  while(test<=T)
    {
      scanf("%d %d %d",&R,&C,&M);
      answerFound=0;
      printf("Case #%d:\n",test++);
      choose(0,R,C,M);
      if(!answerFound)
	printf("Impossible\n");
    }
  return 0;
}
