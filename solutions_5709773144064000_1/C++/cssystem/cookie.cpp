/*
Author:wuhuajun
*/
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef double dd;
const int maxn=210;

int T;
dd c,f,x,speed,t,ans,sum;

void close()
{
exit(0);
}


void init()
{
//freopen("cookie.in","r",stdin);
//freopen("cookie.out","w",stdout);
	scanf("%d",&T);
	for (int cas = 1;cas <= T;cas++)
	{
		printf("Case #%d: ",cas);
		scanf("%lf %lf %lf",&c,&f,&x);
		speed = 2;
		t = 0;
		ans = 1E10;
		while (1)
		{
			sum = (t + x / speed);//现在花的时间 + 生产的速率
			ans = min(ans, sum);
			if (ans < sum) break;
			t = t + c / speed;//现在造一个农场的价格
			speed = speed + f;
		}
		printf("%.7lf\n",ans);
	}
}

int main ()
{
	init();
	close();
	return 0;
}

