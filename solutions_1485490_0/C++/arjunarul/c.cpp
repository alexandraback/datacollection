#include<iostream>

using namespace std;

long long int t,A[200][2],n,m,B[200][2],ans1,temp1,temp2,temp3,temp4;

int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
        ans1=0;

    for(int i=1;i<=3;i++)
    {
      A[i][0]=0;
      A[i][1]=0;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      cin>>A[i][0]>>A[i][1];
    }
    
    for(int i=1;i<=m;i++)
    {
      cin>>B[i][0]>>B[i][1];
    }
    
    if(A[1][1]==A[2][1])
    {
      if(A[2][1]==A[3][1])
      {
	A[1][0]+=(A[2][0]+A[3][0]);
	A[2][0]=0;
	A[3][0]=0;
      }
      else
      {
	A[2][0]+=A[1][0];
	A[1][0]=0;
      }
    }
    
    else if(A[2][1]==A[3][1])
    {
      A[2][0]+=A[3][0];
      A[3][0]=0;
    }
    
    else if(A[1][1]==A[3][1])
    {
      for(int i=1;i<=m;i++)
      {
	if(B[i][1]==A[1][1])
	  ans1+=B[i][0];
      }
      if(ans1>(A[1][0]+A[3][0]))
	ans1=(A[1][0]+A[3][0]);
    }
    
    
    
    
    for(int i=0;i<=m;i++)
    {
      for(int j=i;j<=m;j++)
      {
	temp4=0;
	
	temp1=A[1][0];
	temp2=A[1][1];
	temp3=0;

	for(int k=1;k<=i;k++)
	{
	  if(B[k][1]==temp2)
	  {
	    temp3+=B[k][0];
	  }
	}
	if(temp3>temp1)
	  temp3=temp1;
	temp4+=temp3;
	
	
	
	
	temp1=A[2][0];
	temp2=A[2][1];
	temp3=0;

	for(int k=i+1;k<=j;k++)
	{
	  if(B[k][1]==temp2)
	  {
	    temp3+=B[k][0];
	  }
	}
	if(temp3>temp1)
	  temp3=temp1;
	temp4+=temp3;
	
	
	
	temp1=A[3][0];
	temp2=A[3][1];
	temp3=0;

	for(int k=j+1;k<=m;k++)
	{
	  if(B[k][1]==temp2)
	  {
	    temp3+=B[k][0];
	  }
	}
	if(temp3>temp1)
	  temp3=temp1;
	temp4+=temp3;
	
	if(temp4>ans1)
	  ans1=temp4;
	
      }
    }
    
    cout<<"Case #"<<q<<": "<<ans1<<endl;
  }
}
	