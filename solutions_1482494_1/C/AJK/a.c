#include <stdio.h>
int main()
{
  int T,N,i,j,k;
  int a[2000];
  int b[2000];
  int flag_compl;
  int flag222;
  int powerr;
  int try;
  int max;
  int max_arg;
  FILE *fp1,*fp2;
  fp1 = fopen("data.in","r");
  fp2 = fopen("data.out","w");
  fscanf(fp1,"%d",&T);
  for (i=1;i<=T;i++)
  {
    fscanf(fp1,"%d",&N);
    for (j=0;j<N;j++)
    {
      fscanf(fp1,"%d %d",a+j,b+j);
    }
    powerr=0;
    try=0;
    flag_compl=0;
    while(flag_compl==0)
    {
      flag_compl=1;
      for (j=0;j<N;j++)
      {
	if ((powerr >= a[j])||(powerr >= b[j]))
	{
	  flag_compl=0;
	}
      }
      flag222=0;
      for(j=0;j<N;j++)
      {
	if ((powerr >= b[j]) && (powerr >= a[j]))
	{
	  powerr=powerr+2;
	  a[j]=100000;
	  b[j]=100000;
	  flag222=1;
	  try++;
	}
      }
      if (flag222==0)
      {
	for(j=0;j<N;j++)
	{
	  if ((powerr >= b[j]) && (powerr < a[j]))
	  {
	    powerr=powerr+1;
	    b[j]=100000;
	    flag222=1;
	    try++;
	    break;
	  }
	}
      }
      if (flag222==0)
      {
	max=0;
	for(j=0;j<N;j++)
	{
	  if(powerr>=a[j])
	  {
	    if (b[j]>max)
	    {
	      max=b[j];
	      max_arg=j;
	    }
	  }
	}
	if (max!=0)
	{
	  powerr=powerr+1;
	  a[max_arg]=100000;
	  try++;
	}
      }
      if (powerr==2*N)
      {
	flag_compl=2;
      }
    }
    if(flag_compl==2)
    {
      fprintf(fp2,"Case #%d: %d\n",i,try);
    }
    if(flag_compl==1)
    {
      fprintf(fp2,"Case #%d: Too Bad\n",i);
    }
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}

