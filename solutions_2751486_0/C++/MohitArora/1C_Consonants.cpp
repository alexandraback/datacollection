// Mohit Arora

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define STL_LOOP(X) for (typeof(X.begin()) it = X.begin(); it!=X.end(); it++)

char input[1000000];
int n,len;

bool isVowel(char x)
{
  if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
    return true;
  else
    return false;
}

int process()
{
  int i,j,count=0,cons=0;
  bool set=false;
  for(i=0;i<len;i++)
  {
    cons=0;
    set=false;
    for(j=i;j<len;j++)
    {
      if( isVowel(input[j]) )
        cons=0; 
      else
        cons++;
      if(cons>=n)
        set=true;
      if(set)
        count++;
    }
  }
  return count;
}

int main()
{
  freopen("A-small-attempt0.in","r",stdin);
  freopen("1C_Consonants.out","w",stdout);
  int i,result;

  int t;
  scanf("%d",&t);

  for(i=1; i<=t; i++)
  {
    memset(input,0,sizeof input);
    scanf("%s%d",input,&n);
    len = strlen(input);
    result = process();
    printf("Case #%d: %d\n",i,result);
  }

  return 0;
}
