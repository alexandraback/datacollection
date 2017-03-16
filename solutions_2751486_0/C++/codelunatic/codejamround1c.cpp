#include <cstring>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAXN 1000010
#define ff first
#define ss second
#define get getchar//_unlocked
inline int inp()
{
    int n=0,s=1;
    char p=get();
    if(p=='-')
    s=-1;
    while((p<'0'||p>'9')&&p!=EOF)
    p=get();
    while(p>='0'&&p<='9')
    {
    n = (n<< 3) + (n<< 1) + (p - '0');
    p=get();
    };
    return n*s;
}
char s[100005];
int main()
{
    int i,n,j,k,l,m,t,c=0,ans,d;
    t=inp();
    for(int p=1;p<=t;p++)
    {
      scanf("%s",s);
      n=inp();
      //printf("%d\n",n);
      d=0;c=0;
      k=strlen(s);
      if(k==1)
      {
          m=0;
          if((s[m]!='a'&&s[m]!='e'&&s[m]!='i'&&s[m]!='o'&&s[m]!='u'))
          {printf("Case #%d: 1\n",p,d);continue;}
          else {printf("Case #%d: 0\n",p,d);continue;}
      }
      if(n==1)
      {
        for(l=n,d=0;l<=k;l++)
        {
          for(i=0;i<k-l+1;i++)
          {
              j=i+l-1;
              for(m=i,c=0;m<=j;m++)
              {
                  if(s[m]!='a'&&s[m]!='e'&&s[m]!='i'&&s[m]!='o'&&s[m]!='u')
                  c++;
                  else c=0;
                  if(c>=n)
                  {d++;break;}
              }
          }
        }
        printf("Case #%d: %d\n",p,d);
        continue;
      }
      for(l=n,d=0;l<=k;l++)
      {
          for(i=0;i<k-l+1;i++)
          {
              j=i+l-1;
              for(m=i,c=1;m<j;m++)
              {
                  if((s[m]!='a'&&s[m]!='e'&&s[m]!='i'&&s[m]!='o'&&s[m]!='u')&&s[m+1]!='a'&&s[m+1]!='e'&&s[m+1]!='i'&&s[m+1]!='o'&&s[m+1]!='u')
                  c++;
                  else c=1;
                  if(c>=n)
                  {d++;break;}
              }
          }
      }
      printf("Case #%d: %d\n",p,d);
    }
    return 0;
}

