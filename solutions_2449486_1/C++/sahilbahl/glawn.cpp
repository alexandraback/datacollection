#include<iostream>
using namespace std;
int rcheck(int a[][100],int i,int col,int n)
{
 for(int j=0;j<col;++j)
 if(a[i][j]>n)
 return 0;
 return 1;    
}
int ccheck(int a[][100],int j,int row,int n)
{
 for(int i=0;i<row;++i)
 if(a[i][j]>n)
 return 0;
 return 1;    
}
int main()
{
     freopen("B-large (2).in","r",stdin);
   freopen("otp2.in","w",stdout);
 
 int t,z=1;
 cin>>t;
 while(t--)
 {
           int row,col,k=0;
           cin>>row>>col;
           int a[100][100];
  for(int i=0;i<row;++i)
  {
   for(int j=0;j<col;++j)
           cin>>a[i][j];        
  }          
  for(int i=0;i<row;++i)
          for(int j=0;j<col;++j)
          {
           //if(a[i][j]==1)
           //{
            if(!(rcheck(a,i,col,a[i][j])||ccheck(a,j,row,a[i][j])))
                          {k=1;break;}
          // }        
          }
  if(k==1)
   cout<<"Case #"<<z++<<": NO"<<endl;
  else
   cout<<"Case #"<<z++<<": YES"<<endl;
 }
 return 0;    
}
