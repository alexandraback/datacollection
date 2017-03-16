#include<iostream>
#include<cstdio>
using namespace std;
int in_seq[1001]={0};
bool check(int x)
{
	int rev=0;
	int y=x;
	while(y)
	{
		rev=rev*10+y%10;
		y=y/10;

	}
	if(rev==x)
		return true;
	else
		return false;
}
void solve()
{
      for(int i=1;i*i<=1000;i++)
	      if(check(i)==true && check(i*i)==true )
	      {
		in_seq[i*i]=1;
	      	//printf("%d",i*i);
	      }
      for(int i=2;i<=1000;i++)
	      in_seq[i]+=in_seq[i-1];
}
int main()
{
	solve();
	int tc,a,b,pp=1;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d",&a,&b);
		printf("Case #%d: %d\n",pp,in_seq[b]-in_seq[a-1]);
		pp++;
	}
}
