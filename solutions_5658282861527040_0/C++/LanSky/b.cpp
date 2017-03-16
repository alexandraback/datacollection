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

int main (void)
{
	freopen("D:\\B-small-attempt0.in", "r", stdin);
	freopen("D:\\B-small-attempt0.out", "w", stdout);
	int t;
	while(scanf("%d", &t) != EOF)
	{
		for(int ca = 0; ca < t; ++ca)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			int ans = 0;
			for(int i = 0; i < a; ++i)
			{
				for(int j = 0; j < b; ++j)
				{
					if((i & j) < c)
					{
						ans++;
					}
				}
			}
			printf("Case #%d: %d\n", ca + 1, ans);
		}
	}
	return 0;
}