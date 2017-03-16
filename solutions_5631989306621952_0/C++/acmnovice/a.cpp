#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ch[4000],s[4000];
int n,l,r,tests;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>tests;
	for (int test=1;test<=tests;test++)
	{
  scanf("%s",ch);
  n=strlen(ch);
  l=2000;r=2000;s[l]=ch[0];
  for (int i=1;i<n;i++)
  {
  	if (ch[i]>=s[l])
  	{
  	  l--;
  	  s[l]=ch[i];
  	}
  	else
  	{
  		r++;
  		s[r]=ch[i];
  	}
  }
  printf("Case #%d: ",test);
  for (int i=l;i<=r;i++)
    cout<<s[i];
  cout<<endl;
  }
  return 0;
}  
