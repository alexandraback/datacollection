#include <cstdio>
#include <cstdlib>
using namespace std;

int T,R,C,W;

int main()
{
	
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	scanf("%d",&T);
	for (int Case=1;Case<=T;Case++)
	{
		scanf("%d%d%d",&R,&C,&W);
		int tt=R*(C/W);
		tt+=W-1;
		if (C%W!=0) tt++;
		printf("Case #%d: %d\n",Case,tt);
	}
}

