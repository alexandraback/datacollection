#include<stdio.h>
#include<string.h>
char str[1000005];
int mark[1000005];
int main()
{
  int T,n,t=1,val,j,len,i,ans;
  scanf("%d",&T);
  while(T--)
    {
      scanf("%s %d",str,&n);
      len=strlen(str);
      val=0;j=1;mark[0]=-1;
      for(i=0;i<len;i++)
	{
	  if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u')
	    val++;
	  else
	    val=0;
	  //printf("%d %d\n",i,val);
	  if(val>=n)
	    mark[j++]=i-n+1;
	}
      ans=0;
      //for(i=1;i<j;i++)
      //printf("%d\n",mark[i]);
      for(i=1;i<j;i++)
	{
	  ans+=(len-mark[i]-n+1)*(mark[i]-mark[i-1]);
	  /*
	  if(i!=0)
	    {
	      ans+=len-n-mark[i-1];
	      printf("%d\n",len-mark[i]-n+mark[i]-mark[i-1]);
	    }
	  else
	    {
	      ans+=len-mark[i]-n+1;
	      printf("%d\n",len-mark[i]-n+1);
	    }
	  */
	}
      printf("Case #%d: %d\n",t,ans);
      t++;
    }
  return 0;
}
