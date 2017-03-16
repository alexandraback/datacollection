#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<cstring>
#include<climits>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<stack>
#include<deque>
#include<list>
#include<vector>
#define LL long long
using namespace std;
int n,m,cnt,snt,times;
LL oo=1000000007;
double C,F,X;
double calc(int t)
{
	double count=0,rate=2,tt=0;
	for (int i=1;i<=t;i++)
	{
		tt+=C/rate;
		rate+=F;
	}
	return tt+X/rate;
}
void work(int lab)
{
	printf("Case #%d: ",lab);
	scanf("%lf%lf%lf",&C,&F,&X);
	if (X==0)
	{
		printf("%.7lf\n",0.0);return;
	}
	double tans,ans=1e20;
	int i;
	for (i=0;true;i++)
	{
		tans=ans;
		ans=calc(i);
		if (tans<ans) break;
	}
	printf("%.7lf\n",tans);
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&times);
	for (int i=1;i<=times;i++)
	work(i);
    return 0;
}

