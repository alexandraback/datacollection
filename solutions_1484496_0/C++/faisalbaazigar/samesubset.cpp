#include<iostream>

using namespace std;

int main()
{
  int t;
  cin>>t;
  int q=0;
  while(t--)
  {
    q++;
    cout<<"Case #"<<q<<":\n";
    int a[20];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>a[i];
    bool flag=0;
    for(int i=0;i<(1<<n) && !flag;i++)
    {
      int fsum=0;
      int x=i,k=0;
      while(x)
      {
	if(x&1)
	  fsum+=a[k];
	k++;
	x>>=1;
      }
      for(int j=0;j<(1<<n);j++)
      {
	int ssum=0;
	int x=j,k=0;
	while(x)
	{
	  if(x&1)
	    ssum+=a[k];
	  k++;
	  x>>=1;
	}
	if(fsum==ssum && i!=j)
	{
	  flag=1;
	  int x=i,k=0;
	  while(x)
	  {
	    if(x&1)
	      cout<<a[k]<<" ";
	    k++;
	    x>>=1;
	  }
	  cout<<"\n";
	  x=j;
	  k=0;
	  while(x)
	  {
	    if(x&1)
	      cout<<a[k]<<" ";
	    k++;
	    x>>=1;
	  }
	  cout<<"\n";
	  break;
	}
      }
    }
    if(!flag)
      cout<<"impossible\n";
  }
  return 0;
}