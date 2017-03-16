#include<iostream>

using namespace std;

double t,n,A[1000],s;
double temp1,temp2;

int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    cin>>n;
    s=0;
    for(int i=1;i<=n;i++)
    {
      cin>>A[i];
      s+=A[i];
    }
    cout.precision(6);
    cout.setf(ios::fixed,ios::floatfield); 
    cout<<"Case #"<<q<<":";
    
    for(int i=1;i<=n;i++)
    {
      cout<<" ";
      temp1=200/n;
      temp2=(A[i]*100)/s;
      cout<<temp1-temp2;
    }
    cout<<endl;
  }
}