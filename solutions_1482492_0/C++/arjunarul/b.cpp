#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double t,d,n,a,T[100],A[100],X[100],temp1,temp2;

int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    cin>>d>>n>>a;
    
    for(int i=0;i<n;i++)
      cin>>T[i]>>X[i];
    for(int i=1;i<=a;i++)
      cin>>A[i];
    
    
    	cout<<"Case #"<<q<<":"<<endl;
	  cout.precision(10);
	  cout.setf(ios::fixed,ios::floatfield);   // floatfield set to fixed
	
	if(n==2)
	{
    temp2=((d-X[0])*T[1]);
    temp2/=(X[1]-X[0]);
	}
	else
	{
	  temp2=-1;
	}
    
    for(int i=1;i<=a;i++)
    {
      temp1=2*d;
      temp1/=A[i];
      temp1=sqrt(temp1);
      
      if(n==1)
      {
	cout<<temp1<<endl;
	continue;
      }
      
      if(temp1<=temp2)
      {
	cout<<temp2;
      }
      else
	cout<<temp1;
      cout<<endl;
    }
    cout<<endl;
  }
}
      