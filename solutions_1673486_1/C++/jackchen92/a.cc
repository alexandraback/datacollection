#include <cstdio>
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

double p[100005];
double cp[100005];

int main(int argc,char* argv[])
{
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		int a,b;
		scanf("%d%d", &a, &b);
		cp[0] = 1;
		for(int i=0;i<a;i++)
		{
			scanf("%lf", p+i);
			cp[i+1] = cp[i] * p[i];
		}
		double k = 2+b;
		for(int i=a;i>=0;i--)
			k = min(k, (a-i)*2+(b-a)+1+(1-cp[i])*(b+1));
		printf("Case #%d: %lf\n",test_case,k);
	
	}
	return 0;
}
