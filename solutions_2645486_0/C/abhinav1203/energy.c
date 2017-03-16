#include<stdio.h>
int v[10005],sum[10005];
int main()
{
  int T,E,R,N,i,j,gain;
  scanf("%d",&T);
  for(i=1;i<=T;i++)
    {
      scanf("%d %d %d",&E,&R,&N);
      for(j=0;j<N;j++)scanf("%d",&v[j]);
      sum[N-1]=0;
      for(j=N-2;j>=0;j--)
	sum[j]=sum[j+1]+v[j+1];
      gain=0;
      for(j=0;j<N;j++)
	{
	  if(v[j]>sum[j])
	    {
	      gain+=E*v[j];
	      //printf("%d\n",E);
	      E=R;
	    }
	  else
	    {
	      gain+=R*v[j];
	      //printf("%d\n",E);
	    }
	  //printf("%d\n",gain);
	}
      printf("Case #%d: %d\n",i,gain);
    }
  return 0;
}
