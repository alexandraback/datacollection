#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	freopen("D-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	scanf("%d", &tc);
	for(int ti=1; ti<=tc; ti++){
		int x,r,c;
		scanf("%d%d%d",&x,&r,&c);
		if(x>=7)
			printf("Case #%d: RICHARD\n",ti);
		else if(x==4&&min(r,c)==2)
			printf("Case #%d: RICHARD\n",ti);
		else if(x==5&&min(r,c)==3&&max(r,c)==5)
			printf("Case #%d: RICHARD\n",ti);
		else if(x==6&&min(r,c)==3)
			printf("Case #%d: RICHARD\n",ti);
		else if((r*c)%x!=0)
			printf("Case #%d: RICHARD\n",ti);
		else if((x+1)/2>min(r,c))
			printf("Case #%d: RICHARD\n",ti);
		else if(x>max(r,c))
			printf("Case #%d: RICHARD\n",ti);
		else
			printf("Case #%d: GABRIEL\n",ti);
	}
	return 0;
}