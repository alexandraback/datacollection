#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define IsSup 0
#define IsPer 1
#define NoSolution 2

#define min(x,y) (x<y? x:y)

int IsPerfect(int n,int p);

int main() 
{ 

#ifdef FILEIO
  freopen("in.txt","r",stdin); 
  freopen("out.txt","w",stdout); 
#endif

  int T;
  int caseNum = 0;
  int N,S,p;
  int t[300];

  int i,j,k;
  int prefect;
  int suprise;
  int noResult = 0;
  int a[3] = {0};
  scanf("%d\n",&T);

  while(T--> 0) 
    {
      caseNum++;
      scanf("%d",&N);
      scanf("%d",&S);
      scanf("%d",&p);
      prefect = 0;
      suprise = 0;
      noResult = 0;
      for(i = 0;i<N;i++)
        {
          scanf("%d\n",&t[i]);
          
          switch(IsPerfect(t[i],p))
            {
            case IsSup:
              suprise++;
              break;
            case IsPer:
              prefect++;
              break;
            case NoSolution:
              noResult++;
              break;
            }
        }
      
      //printf("Case #%d: %d %d %d %d\n",caseNum,N,S,p,prefect + min(suprise,S));
	  printf("Case #%d: %d\n",caseNum,prefect + min(suprise,S));
    }

#ifdef FILEIO
  fclose(stdin);
  fclose(stdout);
#endif  
  
  return 0; 
}


int IsPerfect(int n,int p)
{
  int a[3] = {0};

  int i = 0;
  int hasPerfect = 0;
  int hasSolution = 0;
  int avg = n/3;

  if(avg >= p)
    return IsPer;
  
  a[0] = p;

  for(i = p - 1;i <= p + 1;i++)
    {
      a[1] = i;
      a[2] = n - a[0] - a[1];

      if(a[1]>=0 && a[2] >= 0 && abs(a[2] - a[1]) <= 1 && abs(a[2] - a[0]) <= 1)
        {
          return IsPer;
        }
    }

  a[1] = p - 2;
  a[2] = n - a[0] - a[1];
  
  if(a[0]>=0 && a[1] >= 0 && a[2] >= 0 && abs(a[2] - a[1]) <= 2 && abs(a[2] - a[0]) <= 2)
    {
      return IsSup;
    }

  a[1] = p + 2;
  a[2] = n - a[0] - a[1];  

  if(a[0]>=0 && a[1] >= 0 && a[2] >= 0 && abs(a[2] - a[1]) <= 2 && abs(a[2] - a[0]) <= 2)
    {
      return IsSup;
    }
  return NoSolution;  
}
