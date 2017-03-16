#include<stdio.h>
#include"iostream"
using namespace std;
int main()
{
  int t,i,j,ct,max,ans;
  char str[2000];
  scanf("%d",&t);
  for(j=1;j<=t;j++)
    {
      scanf("%d",&max);
      scanf("%s",str);
      ct=0;
      ans=0;
      for(i=0;str[i]!='\0';i++)
	{
	  if(ct<i&&str[i]!='0') 
	    {
	      ans+=(i-ct);
	      ct+=ans;
	    }
	  ct+=(str[i]-'0');

	}
      printf("Case #%d: %d\n",j,ans);
    }
  return 0;
}
