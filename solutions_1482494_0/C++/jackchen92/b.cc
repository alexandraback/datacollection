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

const int nmax = 1005;
int a[nmax], b[nmax];
pii aa[nmax];
pii bb[nmax];
int p[nmax];

int main(int argc,char* argv[])
{
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d", a+i, b+i);
			aa[i] = pii(a[i], i);
			bb[i] = pii(b[i], i);
		}
		sort(aa, aa+n);
		sort(bb, bb+n);
		priority_queue<pii> pq1;
		int ai = 0, bi = 0;
		int s = 0;
		int t = 0;
		memset(p, 0, sizeof(p));
		while(s < 2*n)
		{
			while(bi < n && bb[bi].first <= s)
			{
				int i = bb[bi++].second;
				t++;
				s+=2-p[i];
				p[i] = 2;
			}
			while(ai < n && aa[ai].first <= s)
			{
				int i = aa[ai++].second;
				pq1.push(pii(b[i], i));
			}

			while(!pq1.empty() && p[pq1.top().second] != 0)
				pq1.pop();
			if(!pq1.empty())
			{
				int i = pq1.top().second;
				pq1.pop();
				if(a[i] > s)
					break;
				assert(b[i] > s);
				assert(p[i] == 0);
				t++;
				s++;
				p[i]++;
			}
			else
				break;
		}
		
		printf("Case #%d: ",test_case);
		if(s < 2*n)
			printf("Too Bad\n");
		else
			printf("%d\n", t);
	}
	return 0;
}
