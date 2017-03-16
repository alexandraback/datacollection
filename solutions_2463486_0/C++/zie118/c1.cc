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

int a[6] = {1, 4, 9, 121, 484};

int main()
{
	int T; scanf("%d", &T);
	for(int cc=1;cc<=T;cc++)
	{
		int A, B, ans=0;
		scanf("%d %d", &A, &B);
		for (int i = 0; i < 5; i++)
			if (a[i] >= A && a[i] <= B) ans++;
		printf("Case #%d: %d\n", cc, ans);
	}
	return 0;
}
