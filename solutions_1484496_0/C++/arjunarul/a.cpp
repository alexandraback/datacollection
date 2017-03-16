#include<iostream>

using namespace std;

int t,n,A[100],S[2000000],flag1,flag2,temp1,B[100],ans1;

int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
      cin>>A[i];
    
    for(int i=0;i<=2000000;i++)
      S[i]=-1;
    
    flag1=-1;
    for(int i=0;i<=1048575;i++)
    {
      temp1=i;
      for(int j=1;j<=20;j++)
      {
	if(temp1%2==0)
	{
	  B[j]=1;
	}
	else
	  B[j]=0;
	temp1/=2;
      }
      ans1=0;
      for(int j=1;j<=20;j++)
      {
	if(B[j]==1)
	  ans1+=A[j];
      }
      
      if(S[ans1]>=0)
      {
	flag1=i;
	flag2=S[ans1];
	break;
      }
      S[ans1]=i;
    }
    
    if(flag1==-1)
    {
      cout<<"Case #"<<q<<":"<<endl<<"Impossible"<<endl;
      continue;
    }
    cout<<"Case #"<<q<<":"<<endl;
    
    temp1=flag1;
      for(int j=1;j<=20;j++)
      {
	if(temp1%2==0)
	{
	  B[j]=1;
	}
	else
	  B[j]=0;
	temp1/=2;
      }
	  
	  
	  for(int i=1;i<=20;i++)
	  {
	    if(B[i]==1)
	      cout<<A[i]<<" ";
	  }
	  cout<<endl;
	
	  
    temp1=flag2;
      for(int j=1;j<=20;j++)
      {
	if(temp1%2==0)
	{
	  B[j]=1;
	}
	else
	  B[j]=0;
	temp1/=2;
      }
	  
	  
	  for(int i=1;i<=20;i++)
	  {
	    if(B[i]==1)
	      cout<<A[i]<<" ";
	  }
	  cout<<endl;
  }
}

  