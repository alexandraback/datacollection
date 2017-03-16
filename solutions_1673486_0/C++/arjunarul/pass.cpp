#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int t,a,b,c;
double A[1000000],B[1000000],min1,min2;

int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    cin>>a>>b;
    
    for(int i=1;i<=a;i++)
    {
      cin>>A[i];
    }
    
    B[0]=1;
    B[1]=A[1];
    
    for(int i=2;i<=a;i++)
    {
      B[i]=B[i-1]*A[i];
    }
    
    c=b-a;
    
    min1= (c+1)*B[a];
    min1+= (c+1+b+1)*(1-B[a]);
    
    for(int i=1;i<=a;i++)
    {
      min2=(i+i+c+1)*B[a-i];
      min2+=(i+i+c+1+b+1)*(1-B[a-1]);
      
      if(min2<min1)
	min1=min2;
    }
    
    min2=1+b+1;
    
    if(min2<min1)
      min1=min2;
    cout.precision(6);
    cout.setf(ios::fixed,ios::floatfield); 
    cout<<"Case #"<<q<<": "<<min1<<endl;
  }
}
    
    
    
      