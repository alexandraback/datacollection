#include <cstdio>
using namespace std;

int c, r, x;
int solve() 
{
	if(x==1)
	{
		return 2;
	}
	if(x == 2)
	{
		if(c*r%2==0)
		{
			return 2;
		}
		return 1;
	}
	if(x==3)
	{
		if(c%3==0&&r>=2)
			return 2;
		if(r%3==0&&c>=2)
			return 2;
		return 1;
	}
	if(x==4)
	{
		if(c%4==0&&r>=3)
			return 2;
		if(r%4==0&&c>=3)
			return 2;
		if(c%2==0&&r%2==0&&c>=6&&r>=6)
			return 2;
		return 1;
	}
	if(x==5)
	{
		if(c%5==0&&r>=3)
			return 2;
		if(r%5==0&&c>=3)
			return 2;
		return 1;
	}
	if(x == 6)
	{
		if(c%6==0&&r>=4)
			return 2;
		if(r%6==0&&c>=4)
			return 2;
		if(c%2==0&&r%3==0&&c>=4&&r>=9)
			return 2;
		if(c%3==0&&r%2==0&&c>=9&&r>=4)
			return 2;
		return 1;
	}
	return 1;
}
int main() {
	freopen("D-large.in", "r", stdin);
	freopen("4dout.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	for(int i = 1;i <= ncase;i++)
	{
		printf("Case #%d: ", i);
		scanf("%d%d%d", &x, &r, &c);
		if(solve()==1)
		{
			printf("RICHARD\n");
		}
		else
		{
			printf("GABRIEL\n");
		}
	}
	return 0;
}