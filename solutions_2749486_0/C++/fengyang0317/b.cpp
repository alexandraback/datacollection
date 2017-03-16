#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
int dx,dy;
int myabs(int x)
{
	if(x<0)return -x;
	return x;
}
struct po
{
	po(int a,int b)
	{
		x=a;
		y=b;
		s[0]=0;
	}
	po()
	{
	}
	int x,y;
	const bool operator <(const po &b) const
	{
		//printf("%d %d\n%d %d\n----------\n",x,y,b.x,b.y);
		//printf("%d %d\n",myabs(dx-x)+myabs(dy-y),myabs(b.x-dx)+myabs(b.y-dy));
		//if((myabs(dx-x)+myabs(dy-y))==(myabs(b.x-dx)+myabs(b.y-dy)))
		//	return strcmp(s,b.s)<0;
		//return myabs(dx-x)+myabs(dy-y)<myabs(b.x-dx)+myabs(b.y-dy);
		
		if(strlen(s)==strlen(b.s))
			return strcmp(s,b.s)<0;
		else return strlen(s)<strlen(b.s);
	}
	char s[999];
};
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cas;
	int ki,i,j;
	scanf("%d",&cas);
	set<po>::iterator it;
	for(ki=1;ki<=cas;ki++)
	{
		set<po> sp;
		printf("Case #%d: ",ki);
		scanf("%d%d",&dx,&dy);
		while(dx||dy)
		{
			if(dx>0)
			{
				putchar('W');
				putchar('E');
				dx--;
			}
			if(dx<0)
			{
				putchar('E');
				putchar('W');
				dx++;
			}
			if(dy>0)
			{
				putchar('S');
				putchar('N');
				dy--;
			}
			if(dy<0)
			{
				putchar('N');
				putchar('S');
				dy++;
			}
		}
		puts("");
	}
	return 0;
}