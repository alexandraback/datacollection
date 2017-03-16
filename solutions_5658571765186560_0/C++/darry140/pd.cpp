#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
bool sol(int x,int r,int c)
{
	if(r>c)//r<=c
		swap(r,c);
	if(x==1)
		return true;
	if(x==2)
		return (r*c)%2==0;
	if(x==3)
	{
		if(c<=2||(r*c)%3)
			return false;
		//(1,3) , (2,3) , (3,3) , (3,4)
		if(r+c==4)
			return false;
		if(r+c==5)
			return true;
		if(r+c==6)
			return true;
		if(r+c==7)
			return true;
	}
	if(x==4)
	{
		if(c<=3||(r*c)%4)
			return false;
		if(r+c==5)
			return false;//....
		if(r+c==6)       //....
			return false;//....
		if(r+c==7)
			return true;
		if(r+c==8)
			return true;
	}
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		int x,r,c;
		scanf("%d%d%d",&x,&r,&c);
		printf("Case #%d: ",cas);
		puts(sol(x,r,c)?"GABRIEL":"RICHARD");
	}
	return 0;
}
