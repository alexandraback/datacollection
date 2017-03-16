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
typedef long double LD;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;
typedef map<int,int>::iterator mit;


void work(int no)
{
	LL R,t;
	scanf("%lld%lld",&R,&t);
	LL l = 1,r = 1000000000000000000ll;
	while (l < r)
	{
		if ((2 * R + 2 * r - 1) <= t / r)
		{
			l = r;
			break;
		}
		else r--;
		LL mid = (l + r) >> 1;
		if ((2 * R + 2 * mid - 1) <= t / mid) l = mid;
		else r = mid - 1;
	}
	printf("Case #%d: %lld\n",no,l);
}

int main()
{
	int times;
	scanf("%d",&times);
	for (int i = 1;i <= times;++i)
		work(i);
	return 0;
}
