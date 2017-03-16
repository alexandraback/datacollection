#include<iostream>
#include<conio.h>
#include<stdio.h>
int a[120][120];
int entire_row_is_less_equal(int ,int, int );
int entire_col_is_less_equal(int ,int, int );
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
                                           if(entire_row_is_less_equal(i,j,m) || entire_col_is_less_equal(j,i,n) )
                                           continue;
                                           else 
                                           {
                                                done=0;
                                                break;
                                                }
                      }
      }
      if(done==1)
      fprintf(f2,"Case #%d: YES\n",tcn);
      else fprintf(f2,"Case #%d: NO\n",tcn);
    }
    return 0;
}
int entire_row_is_less_equal(int rowno,int colno,int sz_max)
{
    int i;
    for(i=0;i<sz_max;i++)
    {
                         if(a[rowno][i]<=a[rowno][colno])
                         continue;
                         else return 0;
                         }
     return 1;
     }                                                        
int entire_col_is_less_equal(int colno,int rowno,int sz_max)
{
    int i;
    for(i=0;i<sz_max;i++)
    {
                         if(a[i][colno]<=a[rowno][colno])
                         continue;
                         else return 0;
                         }
     return 1;
     } 
