#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
vector<pair<int,int> > L[101];
int main()
{
   int grid[102][102];
   int r_visit[102];
   int c_visit[102];
   int tc,N,M,_max=0,_min=101,pp=1;
   scanf("%d",&tc);
   while(tc--)
   {
	   _max=0;
	   scanf("%d%d",&N,&M);
	   for(int i=1;i<=100;i++)
		   grid[N+1][i]=0;
	   for(int i=1;i<=N;i++)
	   {
		   _min=0;
		   for(int j=1;j<=M;j++)
		   {
			   scanf("%d",&grid[i][j]);
			   _max=max(_max,grid[i][j]);
			   _min=max(_min,grid[i][j]);
			   grid[N+1][j]=max(grid[N+1][j],grid[i][j]);
			   L[grid[i][j]].push_back(make_pair(i,j));
		   }
		   grid[i][0]=_min;
	   }
	   memset(r_visit,0,sizeof r_visit);
	   memset(c_visit,0,sizeof c_visit);
	   int f1=0,f2=0,x,y;
	   for(int i=1;i<=_max;i++)
	   {
                       for(int j=0;j<L[i].size();j++)
		       {
			    
                            pair<int,int> P=L[i][j];
			    x=P.first,y=P.second;
			    if(grid[x][y]==grid[x][0]||grid[x][y]==grid[N+1][y])
			    {
                                     
			    }
			    else
			    {
                             f1=1;
			     break;
			    }

			    
		       }
		       if(f1)
			       break;
	   }
	   if(f1)
		   printf("Case #%d: NO\n",pp);
	   else
		   printf("Case #%d: YES\n",pp);
	   pp++;
	   for(int i=1;i<=_max;i++)
		   L[i].clear();

}

}
