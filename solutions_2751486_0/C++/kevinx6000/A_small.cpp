#include<cstdio>
#include<cstring>
using namespace std;
bool isc(char ch)
{
  if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u'))return false;
  return true;
}
int main(void)
{
  int tc,cs,n,i,j,beg,cnt,len,ans;
  char str[102];
  bool flag;
int k;
  // Read Input
  scanf("%d",&tc);
  for(cs=1;cs<=tc;cs++)
  {
    scanf("%s %d",str,&n);
    ans=0;
    len=strlen(str);
    for(i=0;i<len;i++)
    {
      cnt=0;
      for(j=i;j<len;j++)
      {
        if(isc(str[j]))
        {
          ++cnt;
          if(cnt>=n) break;
        }
        else cnt=0;
      }
      ans+=(len-j);
    }
    printf("Case #%d: %d\n",cs,ans);
    /*ans=cnt=0;
    len=strlen(str);
    flag=false;
    for(i=0;i<len;i++)
    {
      if(isc(str[i]))
      {
        if(!flag)
        {
          flag=true;
          beg=i;
        }
        ++cnt;
      }
      else
      {
        if(cnt>=n)
        {
          ans+=(beg+1)*(len-i+1);
          for(j=cnt-1;j>=n;j--)
          {
            ans+=(beg+1);
            ans+=(len-i+1);
            if(cnt-j-1>0) ans+=(cnt-j-1);
          }
        }
        cnt=0;
        flag=false;
      }
    }
    if(flag&&cnt>=n)
    {
      ans+=(beg+1)*(len-i+1);
      for(j=cnt-1;j>=n;j--)
      {
        ans+=(beg+1);
        ans+=(len-i+1);
        if(cnt-j-1>0) ans+=(cnt-j-1);
      }
    }
    printf("%d\n",ans);
    */

  }
  return 0;
}
