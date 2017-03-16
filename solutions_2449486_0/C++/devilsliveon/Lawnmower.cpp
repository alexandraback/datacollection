#include<iostream>
#include<conio.h>
#include<stdio.h>
int a[20][20];
int entire_row_is_1(int ,int );
int entire_col_is_1(int ,int );
int main()
{
    int t,tcn,n,m,i,j;
    FILE *fp=fopen("input.txt","r");
    FILE *f2=fopen("output.txt","w");
    fscanf(fp,"%d",&t);
    for(tcn=1;tcn<=t;tcn++)
    {
      int done=1;
      fscanf(fp,"%d%d",&n,&m);
      for(i=0;i<n;i++)
      {
         for(j=0;j<m;j++)
         {
                         fscanf(fp,"%d",&a[i][j]);
                         }
                         }
      for(i=0;i<n;i++)
      {
                      for(j=0;j<m;j++)
                      {
                              if(a[i][j]==1)
                              {
                                           if(entire_row_is_1(i,m) || entire_col_is_1(j,n) )
                                           continue;
                                           else 
                                           {
                                                done=0;
                                                break;
                                                }
                              }
                      }
      }
      if(done==1)
      fprintf(f2,"Case #%d: YES\n",tcn);
      else fprintf(f2,"Case #%d: NO\n",tcn);
    }
    return 0;
}
int entire_row_is_1(int rowno,int sz_max)
{
    int i;
    for(i=0;i<sz_max;i++)
    {
                         if(a[rowno][i]==1)
                         continue;
                         else return 0;
                         }
     return 1;
     }                                                        
int entire_col_is_1(int colno,int sz_max)
{
    int i;
    for(i=0;i<sz_max;i++)
    {
                         if(a[i][colno]==1)
                         continue;
                         else return 0;
                         }
     return 1;
     } 
