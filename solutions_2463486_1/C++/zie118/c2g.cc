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

vector <LL> ans;

bool pa(LL x)
{
	int a[20], n=0;
	while(x > 0) { a[n++] = x % 10; x /= 10; }
	for (int i =0;i<n/2;i++) if (a[i] != a[n-i-1]) return false;
	return true;
}

int main()
{
	ans.clear();
	for (LL i = 1; i <= 10000001; i++) if (pa(i))
	{
		LL sq = i*i;
		if (pa(sq)) ans.PB(sq);
	}

	int T; scanf("%d", &T);
	for(int cc=1;cc<=T;cc++)
	{
		int ret = 0;
		LL A, B;
		scanf("%lld %lld", &A, &B);
		for (int i = 0; i < ans.size(); i++)
			if (ans[i] >= A && ans[i] <= B) ret++;
		printf("Case #%d: %d\n", cc, ret);
	}
	return 0;
}
