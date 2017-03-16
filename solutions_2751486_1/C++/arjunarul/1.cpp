#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

long long int t,n,A[1000010],l,curr,ans1,B[1000010],E[1000010];
string s;
char ch;

int main()
{
  cin>>t;
  
  for(int q=1;q<=t;q++)
  {
    cin>>s>>n;
    //cout<<"\n\n"<<s<<n<<endl;
    
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='a' || s[i]=='e' ||s[i]=='i' || s[i]=='o' || s[i]=='u')
	A[i+1]=0;
      else
	A[i+1]=1;
    }
    l=s.size();
    
    
    curr=0;
    for(int i=1;i<=l;i++)
    {
      if(A[i]==1)
	curr++;
      else
	curr=0;
      if(curr>=n)
	E[i]=1;
      else
	E[i]=0;
    }
    
    
    ans1=0;
    B[l-n+2]=0;
    
	

    
    for(int i=l-n+1;i>0;i--)
    {

      if(A[i]==0)
      {
	B[i]=B[i+1];
	ans1+=B[i];
      }
      

      
      else
      {
	if(E[i+n-1]==1)
	  B[i]=l-i-n+2;
	else
	  B[i]=B[i+1];
	ans1+=B[i];
      }
    }
    
      
    
    
  
    cout<<"Case #"<<q<<": "<<ans1<<"\n";
    
  }
}
	