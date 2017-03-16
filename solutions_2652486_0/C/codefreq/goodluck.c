#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int comparator(const void* e1, const void* e2) {
  int c1 = *(int*)e1;
  int c2 = *(int*)e2;
  return c1-c2;
}

void calcval(int *products,int lim, int n,char *ret)
{
  int i,j1,j2,j3,flag=0;
  qsort(products,lim,sizeof(int),comparator);
  for(i=0;i<lim;++i)
    {
      for(j1=2;j1<=5;++j1)
	for(j2=2;j2<=5;++j2)
	  for(j3=2;j3<=5;++j3)
	    {
	      if(products[i]==j1*j2*j3)
		{
		  ret[0]=j1+48;
		  ret[1]=j2+48;
		  ret[2]=j3+48;
		  ret[3]='\0';
		  flag = 1;
		  break;
		}
	    }
    }
  if(flag!=1)
    strcpy(ret,"243");
}
void main()
{
  char *ret = (char*)malloc(sizeof(*ret)*4);
  int r,n,m,k,t,i,j,prods[12],val;
  scanf("%d%d%d%d%d",&t,&r,&n,&m,&k);
  printf("Case #1:\n");
  for(i=1;i<=r;++i)
    {
      for(j=0;j<k;++j)
	scanf("%d",&prods[j]);
      calcval(prods,k,n,ret);
      printf("%s\n",ret);
    }
}
