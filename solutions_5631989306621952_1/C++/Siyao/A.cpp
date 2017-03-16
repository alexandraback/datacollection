#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


char str[1100];
char output[1100];
char tmp1[1100];

void deal()
{
  int  len=strlen(str);
  for(int i=0;i<len;++i)
  {
    if(i==0) {output[i]=str[i]; output[i+1]=0;}
    else
    {
      output[i]=0;
      strcpy(tmp1+1,output);
      tmp1[0]=str[i];
      //    printf("tmp1:%s out: %s\n",tmp1, output);
      output[i]=str[i];
      output[i+1]=0;
      //    printf("str:%c out: %s\n",str[i], output);
 
      //   printf("tmp1:%s out: %s\n",tmp1, output);
      if(strcmp(tmp1,output)>0) strcpy(output,tmp1);
    }
    // printf("%s\n",output);
  }
  // output[len]=0;
}
int main()
{
  int  T;
  scanf("%d",&T);
  for(int i=1;i<=T;++i)
  {
    printf("Case #%d: ", i);
    scanf("%s",str);
    deal();
    printf("%s\n",output);   
    // deal 
  
  }
  //printf("%d\n",maxt);
  return 0;
}
