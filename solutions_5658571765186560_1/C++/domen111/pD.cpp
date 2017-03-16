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
		if(c<=3)return false;
		if(r<=2)return false;
		return true;
	}
	else if(x==5)
	{
		if(c<=4)return false;
		if(r>=4)return true;
		if(r==3)
			return c>5;
		if(r==2)return false;
		if(r==1)return false;
		throw;
	}
	else if(x==6)
	{
		if(c<=5)return false;
		if(r==5)return true;
		if(r==4)return true;
		if(r<=3)return false;
		return true;
	}
	else //x>=7
	{
		return false;
	}
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
