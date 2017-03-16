#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
using namespace std;
void get_data();
void solve();
int t=0;
int n,p,s;
int ar[500];
float ar1[500];
char ch;
int ctr=0;
int j;
ifstream afile("c:/users/chaturvedi/desktop/code/today/small.in");
main()
{
      get_data();
}     
void get_data()
{
      cout<<"the contents of file are : ";
      while(1)
      {
      afile.get(ch);
      if(ch!=10)
      t=(t*10)+((int) ch)-48;
      else
      break;
      cout<<t<<"\n";                     
      }
      while(afile)
      {
      for(j=0;j<t;j++)
      solve();   
      }    
}

void solve()
{
     float sum,min;
     float req;
     float sum2;
     n=p=s=0;
     while(1)
      {
      afile.get(ch);
      if(ch!=32)
      n=(n*10)+((int) ch)-48;
      else
      break;
      //cout<<n<<"\t";
      }
      /*while(1)
      {
      afile.get(ch);
      if(ch!=32)
      s=(s*10)+((int) ch)-48;
      else
      break;
      //cout<<s<<"\n";
      }
      while(1)
      {
      afile.get(ch);
      if(ch!=32)
      p=(p*10)+((int) ch)-48;
      else
      break;
      //cout<<p<<"\n";
      }*/
      sum=0;
      for(int i=0;i<n;i++)
      {
      ar[i]=0;
      while(1)
              {
              afile.get(ch);
              if(ch!=32&&ch!=10&&afile.eof()==0)
              ar[i]=(ar[i]*10)+((int) ch)-48;
              else
              break;
              //cout<<ar[i]<<"\n";
              }  
      sum+=ar[i];       
      }
      sum2=sum*2;
      min=(sum*2)/n;
      ctr=n;
      for(int i=0;i<n;i++)
      {
      
      if(ar[i]>min)
      {
      sum2-=ar[i];
      ctr--;
      }
      
      }
      min=sum2/ctr;
      for(int i=0;i<n;i++)
      {
      if(ar[i]>min)
      ar1[i]=0;
      else
      {
      req=min-ar[i];
      ar1[i]=(req*100)/sum;
      }
      }
      ofstream bfile("c:/users/chaturvedi/desktop/code/today/small_out.in",ios::app);
      bfile<<"Case #";
      bfile<<j+1;
      bfile<<": ";
      for(int i=0;i<n;i++)
      {
      bfile<<ar1[i];
      bfile<<" ";        
      }
      bfile<<"\n";
      if(afile.eof()!=0)
      {
      afile.close();
      bfile.close();
      exit(0);
      }     
}
