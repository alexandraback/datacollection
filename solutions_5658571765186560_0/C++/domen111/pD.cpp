#include <iostream>
#include <algorithm>
using namespace std;
bool solve(int x,int r,int c)
{
	if(r*c%x!=0)return false;
	if(x==1)return true;
	else if(x==2)return true;
	else if(x==3)
	{
		if(r==1)return false;
		if(c<=2)return false;
		return true;
	}
	else if(x==4)
	{
		if(r<=2)return false;
		if(c<=3)return false;
		return true;
	}
	throw;
}
int main()
{
	int T;
	scanf("%d",&T);
	int no=1;
	while(no<=T)
	{
		int x,r,c;
		cin>>x>>r>>c;
		if(r>c)swap(r,c);
		if(solve(x,r,c))
			printf("Case #%d: GABRIEL\n",no++);
		else
			printf("Case #%d: RICHARD\n",no++);
	}
}
