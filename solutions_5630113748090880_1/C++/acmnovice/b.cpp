#include<iostream>
#include<cstdio>
using namespace std;
int n,x,a[5000],tests;
int main()
{
  freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>tests;
	for (int test=1;test<=tests;test++)
	{
  cin>>n;
  for (int i=1;i<=2*n-1;i++)
  {
    for (int j=1;j<=n;j++)
    {
    	cin>>x;
    	a[x]++;
    }
  }
    printf("Case #%d: ",test);
  for (int i=1;i<=2500;i++)
    if (a[i]%2==1) cout<<i<<' ';
  cout<<endl;
  for (int i=1;i<=2500;i++) a[i]=0;
  }
  return 0;
}
