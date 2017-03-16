#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <stdlib.h>
#include <vector>

using namespace std;

/*struct data
{
	int customer, brand;
	bool operator <(const data &a){
		if(a.customer == this->customer)
			return a.brand > this->brand;
		return a.customer > this->customer;
	}
};
map<data, int> ma;
*/

vector<int> Va, Vb;

int main (void)
{
	freopen("D:\\A-large.in", "r", stdin);
	freopen("D:\\A-large.out", "w", stdout);
	int t;
	while(scanf("%d", &t) != EOF)
	{
		long long a, b;
		for(int ca = 0; ca < t; ++ca)
		{
			scanf("%lld/%lld", &a, &b);
			int ans = 0;
			int cnt = 0;
			int flag = 0;
			long long ta, tb;
			ta = a;
			tb = b;
			printf("Case #%d: ", ca + 1);
			if(ta >= tb)
			{
				ta -= tb;
				flag = 1;
			}
			while(ta)
			{
				ta *= 2;
				if(!flag)
					ans++;
				cnt++;
				if(ta >= tb)
				{
					ta -= tb;
					flag = 1;
				}
				if(cnt > 40)
					break;
			}
			if(cnt > 40)
				printf("impossible\n");
			else
				printf("%d\n", ans);
		}
	}
	return 0;
}