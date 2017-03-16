#include <stdio.h>
int main()
{
  int T,A,B,i,j;
  double P[100000];
  double product;
  double expected[200000];
  double p_correct[200000];
  double min_exp;
  FILE *fp1,*fp2;
  fp1 = fopen("data.in","r");
  fp2 = fopen("data.out","w");
  fscanf(fp1,"%d",&T);
  for (i=1;i<=T;i++)
  {
    fscanf(fp1,"%d %d",&A,&B);
    for(j=0;j<A;j++)
    {
      fscanf(fp1,"%lf",P+j);
    }
    p_correct[0]=1;
    for(j=1;j<=A;j++)
    {
      p_correct[j]=p_correct[j-1]*P[j-1];
    }

    for(j=0;j<=A;j++)
    {
      expected[j]=(A-j+B-j+1)+(1-p_correct[j])*(B+1);
    }
    expected[A+1]=B+2;
    
    min_exp=10000000;
    for(j=0;j<A+2;j++)
    {
      if (expected[j]<min_exp)
      {
	min_exp=expected[j];
      }
    }
    fprintf(fp2,"Case #%d: %lf\n",i,min_exp);
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}

