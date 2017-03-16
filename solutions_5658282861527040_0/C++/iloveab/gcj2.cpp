#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
  
  int TC;
  cin>>TC;
  for(int test_case=1;test_case<=TC;test_case++){
	 
	  unsigned int a,b,k;
	  cin>>a>>b>>k;
	  long long ans=0;
	  for(unsigned int i=0;i<a;i++)
	  {
		  for(unsigned int j=0;j<b;j++)
		  {
			  unsigned c=i&j;
			  if(c<k)
			  {
				  ans++;
			  }
		  }
	  }printf("Case #%d: ",test_case);;
	  cout<<ans<<endl;
	 }	
  return 0;
}
