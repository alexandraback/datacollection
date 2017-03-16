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

ll gcd(ll a, ll b) {
  ll tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

int main(int argc,char* argv[])
{
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		ll p, q;
		scanf("%lld/%lld", &p, &q);
		ll g = gcd(p, q);
		p /= g;
		q /= g;
		
		printf("Case #%d: ", test_case);
		if((1LL<<40) % q != 0)
		{
			printf("impossible\n");
			continue;
		}
		int k;
		for(k=0; p < q; k++)
			p *= 2;
		printf("%d\n", k);
	}
	return 0;
}
