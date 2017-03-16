#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = numeric_limits<int>::max();

int main(int argc,char* argv[])
{
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		int a, b, k;
		cin >> a >> b >> k;
		ll c = 0;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				if((i&j)<k)
					c++;
		printf("Case #%d: %lld\n", test_case, c);
		
	}
	return 0;
}
