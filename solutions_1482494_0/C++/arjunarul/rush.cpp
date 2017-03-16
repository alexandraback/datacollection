#include<iostream>
#include<vector>

using namespace std;

int t,n,A[2000],B[2000],F[2000],S[2000],stars,ans1,flag1,flag2;

int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>A[i]>>B[i];
      F[i]=0;
      S[i]=0;
    }
       
  stars=0;
  ans1=0;
  
  while(1)
  {
    flag1=0;
    for(int i=1;i<=n;i++)
    {
      if(S[i]==1)
	continue;
      if(B[i]<=stars)
      {
	S[i]=1;
	if(F[i]==1)
	  stars+=1;
	else
	  stars+=2;
	ans1+=1;
	flag1=1;
	F[i]=1;
	break;
      }
    }
    if(flag1==1)
      continue;
    
    
    flag2=0;
    for(int i=1;i<=n;i++)
    {
      if(F[i]==1)
	continue;
      if(A[i]<=stars)
      {
	F[i]=1;
	stars+=1;
	ans1++;
	flag2=1;
	break;
      }
    }
    if(flag2==0)
      break;
  }
  flag1=0;
  for(int i=1;i<=n;i++)
  {
    if(S[i]==0)
    {
      cout<<"Case #"<<q<<": "<<"Too Bad\n";
      flag1=1;
      break;
    }
  }
  if(flag1==1)
    continue;
  cout<<"Case #"<<q<<": "<<ans1<<endl;
  }
}

    
  
  
    