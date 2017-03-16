#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

#define inf (1<<29)
#define eps (1e-9)

#define flt(x,y) ((x)<(y)-eps)
#define fgt(x,y) flt(y,x)
#define fle(x,y) !fgt(x,y)
#define fge(x,y) !flt(x,y)
#define feq(x,y) (fabs((x)-(y))<eps)

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


int main()
{
	int T, cc=0; scanf("%d", &T);
	int A, N, m[105];
	while (T--)
	{
		cc++;
		scanf("%d %d", &A, &N);
		for (int i = 0; i < N; i++)
			scanf("%d",m+i);
		sort(m,m+N);
		if (A == 1) {
			printf ("Case #%d: %d\n", cc, N);
			continue;
		}
		int ans = N, cur = 0;
		for (int i = 0; i < N; i++)
		{
			if (A > m[i]) A += m[i];
			else {
				ans = min(ans, cur + N-i);
				while (A <= m[i]) 
				{
					cur++;
					A += A-1;
				}
				A += m[i];
			}
		}
		ans = min(ans, cur);
		printf("Case #%d: %d\n",cc,ans);
	}

	return 0;
}
