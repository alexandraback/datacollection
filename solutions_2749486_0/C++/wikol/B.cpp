#include <cstdio>
#include <algorithm>

using namespace std;

void goUp()
{
	printf("SN");
}
void goDown()
{
	printf("NS");
}
void goRight()
{
	printf("WE");
}
void goLeft()
{
	printf("EW");
}
void solve(int tc)
{
	int x,y;
	scanf("%d%d", &x, &y);
	printf("Case #%d: ", tc);
	for(int i = 0;i<x;i++)
		goRight();
	for(int i = 0;i<-x;i++)
		goLeft();
	for(int i = 0;i<y;i++)
		goUp();
	for(int i = 0;i<-y;i++)
		goDown();
	printf("\n");
}
int main()
{
	int Z;
	scanf("%d", &Z);
	for(int i = 1;i<=Z;i++)
		solve(i);
	return 0;
}
