#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,a[1000][1000];
int row[1000];
int col[1000];


int main()
{
 int t;
 scanf("%d",&t);
 int count=0;
 while(t--)
           {
            count++;
            scanf("%d %d",&n,&m);
            
            for(int i=0;i<n;i++)
            { row[i]=0;
            for(int j=0;j<m;j++)
                    {
                     scanf("%d",&a[i][j]);
                    if(row[i]<a[i][j])
                                      row[i]=a[i][j];
                    }
            //cout<<row[i]<<"\n";
            }
            
            for(int i=0;i<m;i++)
            { col[i]=0;
            for(int j=0;j<n;j++)
                    {
                     
                    if(col[i]<a[j][i])
                                      col[i]=a[j][i];
                    }
            //cout<<col[i]<<"\n";
            }
            
            
           int awai=0; 
           int i,j;
         //cout<<checkrow(1,1);
         for(i=0;i<n;i++)
                 {for(j=0;j<m;j++)
                          {
                           if(row[i]<=a[i][j] || col[j]<=a[i][j])
                                                  {
                                                   awai++;
                                                  }
                          else break;
                          }
                  if(j<m)
                        break; 
                  }
           
           if(i<n)
           printf("Case #%d: NO\n",count);
           else
           printf("Case #%d: YES\n",count);
           
           }
}
