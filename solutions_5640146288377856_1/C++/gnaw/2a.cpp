#include <cstdio>
using namespace std;
int c,w,r;
int hehe(int x)
{
    return c/w;
}
int haha(int x)
{
    if(x%w==0)return x/w+w-1;
    return x/w+w;
}

int main() {
	int T;
	freopen("A-large.in","r",stdin);
	freopen("A-haha.out","w",stdout);

	scanf("%d", &T);
	for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: %d\n", cas, hehe(c)*(r-1)+haha(c));
	}
	return 0;
}


