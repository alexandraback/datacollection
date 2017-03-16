#include<iostream>
using namespace std;
int main()
{
   int n,m,i,j,t,tt=1;
   bool flag=true;
   cin>>t;
   int ar[100][100];
   int max_row[100],max_col[100];
   while(t--)
   {
         cin>>n>>m;
         for(i=0;i<100;i++)
         max_row[i]=max_col[i]=0;
         for(i=0;i<n;i++)
         {
            for(j=0;j<m;j++)
            {
               cin>>ar[i][j];
               max_row[i]=max(max_row[i],ar[i][j]);
               max_col[j]=max(max_col[j],ar[i][j]);
            }
         }
         
         for(i=0;i<n;i++)
         {
            for(j=0;j<m;j++)
            {
               if(ar[i][j]<min(max_row[i],max_col[j]))
               {
                  flag=false;
                  break;
               }
            }
            if(flag==false)
            break;
         }
         if(flag==false)
         cout<<"Case #"<<tt<<": NO\n";
         else
         cout<<"Case #"<<tt<<": YES\n";
         tt++;
         flag=true;
   }
}
