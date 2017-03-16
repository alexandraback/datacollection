#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,a[1000][1000];

bool checkrow(int row,int num)
      {//cout<<"hi"<<m;
      int i;
       for(i=0;i<m;i++)
               {//cout<<"hi";
               //cout<<a[row][i]<<" "<<num;
                if(a[row][i]>num)
                                 break;
               }
       if(i==m)
               return 1;
       return 0;
      }

bool checkcol(int col,int num)
      {int i;
       for(i=0;i<n;i++)
               {
                if(a[i][col]>num)
                                 break;
               }
       if(i==n)
               return 1;
       return 0;
      }
      

void cutrow(int row,int num)
      {int i;
       for(i=0;i<m;i++)
               {
                if(a[row][i]>num)
                                 a[row][i]=num;
               }
       
      }

void cutcol(int col,int num)
      {int i;
       for(i=0;i<n;i++)
               {
                if(a[i][col]>num)
                                 a[i][col]=num;
               }
      }


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
            for(int j=0;j<m;j++)
                    {
                     scanf("%d",&a[i][j]);
                    }
           int awai=0; 
           int i,j;
         //cout<<checkrow(1,1);
         for(i=0;i<n;i++)
                 {for(j=0;j<m;j++)
                          {
                           if(checkrow(i,a[i][j]) || checkcol(j,a[i][j]))
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
