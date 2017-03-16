#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;
typedef map<int,int>::iterator mit;


void work(int no)
{
	LL r,t;
	scanf("%lld%lld",&r,&t);
	LL ans = 0;
	for (LL i = r;t >= (i + 1) * (i + 1) - i * i;i += 2)
	{
		ans ++;
		t -= (i + 1) * ( i + 1) - i * i ;
	}
	printf("Case #%d: %lld\n",no,ans);
}

int main()
{
	int times;
	scanf("%d",&times);
	for (int i = 1;i <= times;++i)
		work(i);
	return 0;
}
