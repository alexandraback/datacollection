#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int flag[7000] = {0};

int Multi(int *a,int n);
int InFlag(int n);
void MakeFlag(int n);

int main() 
{ 

#ifdef FILEIO
  freopen("in.txt","r",stdin); 
  freopen("out.txt","w",stdout); 
#endif

  int T;
  int caseNum = 1;
  int start;
  int end;
  int totalNumber = 0;
  int bit[30] = {0};
  int temp;
  int i,j,k,x,y;
  int n;

  scanf("%d\n",&T);


  while(T-- > 0) 
    {
      scanf("%d %d",&start, &end);

      memset(bit,0,30*sizeof(int));
      memset(flag,0,7000*sizeof(int));
      totalNumber = 0;
      for(i = start;i<=end;i++)
        {
          if(InFlag(i) == 1)
            continue;
          MakeFlag(i);
          int tempTotalNumber = 0;
          j = 0;
          x = i;
          while(x>0)
            {
              bit[j++] = x%10;
              x = x/10;
            }
          n = j;

          for(j = 0;j<n;j++)
            {
              for(k = n-1; k>=0; k--)              
                {
                  temp = bit[k + 1];
                  bit[k + 1] = bit[k];
                  bit[k] = temp;
                }
              bit[0] = bit[n];

              temp = Multi(bit,n);

              if(temp >= start && temp <= end && temp > i)
                {
                  if(InFlag(temp) == 0  && InFlag(i) == 1) 
                    tempTotalNumber++;
                  MakeFlag(temp);
                }
            }
          totalNumber += (tempTotalNumber + 1)*tempTotalNumber/2; 
        }

      printf("Case #%d: %d\n",caseNum++,totalNumber);

      //      printf("Case #%d: %d %d\n",caseNum++,start,end);
    }

#ifdef FILEIO
  fclose(stdin);
  fclose(stdout);
#endif  

  return 0; 
}

int InFlag(int n)
{
  return flag[n/32]>>(n%32 - 1) & 1;
}

void MakeFlag(int n)
{
  flag[n/32] |= 1<<(n%32-1);
}

int Multi(int *a,int n)
{
	int total = 0;
	int index = 1;
	int i;

	for(i = 0;i<n;i++)
	{
		total += a[i]*index;
		index *= 10;
	}
	return total;
}
