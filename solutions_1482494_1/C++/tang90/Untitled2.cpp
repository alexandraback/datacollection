#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
int n;
int a[1100],b[1100];
bool v1[1100],v2[1100];
bool pd()
{
     int i;
     for (i=0;i<n;i++)
     if (!v2[i])
     return false;
     return true;
}
int main()
{
    int t;
    //freopen("in1.in","r",stdin);
    //freopen("out.out","w",stdout);
    scanf("%d",&t);
    int num=0;
    while (t--)
    {
          scanf("%d",&n);
          int i;
          for (i=0;i<n;i++)
          {
              scanf("%d%d",&a[i],&b[i]);
          }
          memset(v1,0,sizeof(v1));
          memset(v2,0,sizeof(v2));
          int rt=0;
          int st=0;
          while (!pd())
          {
                bool ok=false;
                for (i=0;i<n;i++)
                {
                    if (b[i]<=rt&&!v2[i])
                    {
                                        // printf("%d\n",i);
                                         if (v1[i])
                                         rt+=1;
                                         else
                                         rt+=2;
                                         v1[i]=v2[i]=true;
                                         ok=true;
                                         break;
                    }
                }
                if (!ok)
                {
                        int bi=-1;
                        int s=0;
                        for (i=0;i<n;i++)
                        if (!v1[i]&&rt>=a[i])
                        {
                                   if (b[i]>s)
                                   {
                                              bi=i;
                                              s=b[i];
                                   }
                        }
                        if (bi!=-1)
                        {
                                   //printf("%d\n",bi);
                                   v1[bi]=true;
                                   rt+=1;
                                   ok=true;
                                   
                        }
                }
                if (!ok)
                break;
                st++;
          }
          printf("Case #%d: ",++num);
          if (!pd())
          printf("Too Bad\n");
          else
          printf("%d\n",st);
    }
}
                    
                
                
                
                
                
          
