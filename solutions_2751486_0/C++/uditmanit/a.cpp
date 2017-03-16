#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef unsigned long long int64;
int is(char a)
{
    char b[] = "aeiou";
    int i;
    for(i=0;b[i];i++)
    if(a==b[i])return 0;
    return 1;
}
int check(char *a)
{
 int hi = 0;
 int cur = 0;
 int pr = 0;
 int i;
 for(i=0;a[i];i++)
 {
                  int tmp = is(a[i]);
                 
                //  printf("%c is cons\n",a[i]);
                  if(tmp && pr){
                         cur++;
                         }
                         else {
                             
                              pr = tmp;
                              if(cur>hi)hi = cur;
                              if(tmp){cur = 1;
                            //  printf("%c is first time\n",a[i]);
                              }
                              else {
                                   cur = 0;
                                  //  printf("%c is not cons\n",a[i]);
                                   }
                              }
                  } 
                  if(cur>hi)hi = cur;
             return hi;  
}
int main()
{
    int64 i,j,k,n,cas=0;
    char a[500];
 //  while(scanf("%s",&a)==1)
 //  printf("%s has %d\n",a,check(a));
    scanf("%llu",&n);
    while(n--){
               cas++;
               scanf("%s",&a);
               int ti ;
               scanf("%d",&ti);
              // printf("we want %d\n",ti);
               char b[500];
               int l =strlen(a);
               int ans = 0;
               for(i=0;i<l;i++)
               for(j=i;j<l;j++)
               {
                               int cur = 0;
                               for(k=i;k<=j;k++)
                               b[cur++] = a[k];
                               b[cur] = 0;
                             // printf("%s has %d\n",b,check(b));
                               if(check(b)>=ti)
                               {
                                               ans++;
                                             //  printf("%s\n",b);
                                               }
                               
                               }
                               printf("Case #%llu: %d\n",cas,ans);
              
     
    }
    
}
