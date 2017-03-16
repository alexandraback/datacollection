#include<iostream>

using namespace std;

int main()
{
  int i,j,m,n,t,c;
  int a[110][110];
  int maxc[110], maxr[110];
  bool flag;
  cin>>t;
  c=1;
  while(t--)
  {
    cout<<"Case #"<<c<<": ";
    c++;
    cin>>n>>m;
    for(i=0; i<(n>m ? n : m); ++i)
      maxc[i]=maxr[i]=0;
    for(i=0; i<n; ++i)
    {
      for(j=0; j<m; ++j)
      {
	cin>>a[i][j];
	if(a[i][j]>maxr[i])
	  maxr[i]=a[i][j];
	if(a[i][j]>maxc[j])
	  maxc[j]=a[i][j];
      }
    }
    if(n==1 || m==1)
    {
      cout<<"YES\n";
      continue;
    }
    flag=false;
    for(i=0; i<n; ++i)
    {
      for(j=0; j<m; ++j)
      {
	if(a[i][j]<maxr[i] && a[i][j]<maxc[j])
	{
	  flag=true;
	  break;
	}
      }
      if(flag)
	break;
    }
    if(flag)
      cout<<"NO\n";
    else
      cout<<"YES\n";
  }
  return 0;
}