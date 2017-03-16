#include<stdio.h>
#include<string.h>
#define MOD 1000000007
#define start 0
#define end 1
#define mid 2
#define free 3

int fact(int num)
{
    //printf("%d num",num);
    int ans =1,i;
    for(i=2;i<=num;i++)
    ans = (ans*i)%MOD;
    return ans;
}
int main()
{
    
    freopen("thiss.in","r",stdin);
    freopen("out1.txt","w",stdout);
    int t,N,i,term,j,len,flag,ans,test = 1;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&N);
              char arr[N][500];
              char b[N][500];
              for(i=0;i<N;i++)
              scanf("%s",arr[i]);
              
              
              int e[260][4];
              for(i=0;i<26;i++)
              {e[i][0] = 0;e[i][1] = 0;e[i][2] = 0;e[i][3] = 0;}
              for(i=0;i<N;i++)
              {
                              term = 0;
                              b[i][term++] = arr[i][0];
                              for(j=1;j<strlen(arr[i]);j++)
                              {
                                                         if(arr[i][j]!=arr[i][j-1])
                                                         b[i][term++] =arr[i][j];
                                                   
                              }
                              b[i][term] = '\0';
                              
              }
              
              
              for(i=0;i<N;i++)
              {
                              
                              len = strlen(b[i]);
                              
                              if(len==1)
                              e[ b[i][0] - 'a' ][free] ++;
                              else
                              {
                              e[ b[i][0] - 'a' ][start] ++; 
                              for(j=1;j<len-1;j++)
                              {
                                                     e[ b[i][j] - 'a' ][mid] ++;    
                              }
                              e[ b[i][j] - 'a'] [ end] ++;
                              
                              
                              
                              }
                              
              }
              
              
              flag = 0;
              for(i=0;i<26;i++)
              {
                               if(e[i][mid] !=0 && (e[i][start] + e[i][end]  + e[i][free]) >0)
                               {
                                            flag = 1;
                                           // printf("%d %d ",i, e[i][mid]);
                                            break;
                               }
                               else if (e[i][mid] > 1)
                               {
                                    flag = 1;break;}
                               if( e[i][start] >1 || e[i][end]>1)
                               {flag=1;break;}
                               
              }
              ans = 1;
              term = N;
              if(!flag)
              {
              for(i=0;i<26;i++)
              {
                             
                               if(e[i][start] == 1 && e[i][end] == 1)
                               term--;
                            //    printf("Eis  %d\n", e[i][free]);
                               ans = (ans *fact(e[i][free]) ) %MOD;
                               term-=e[i][free];
                               if(e[i][start] ==0 && e[i][end] ==0  && e[i][free]>0)
                               term++;
              }
            //  printf("%d ",ans);
              ans  = (ans*fact(term))%MOD;
              
              }
              if(flag)
              printf("Case #%d: 0\n",test++);
              else
              printf("Case #%d: %d\n",test++,ans);
              
    }
}
 
