#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1000001;

int a[maxn];
int n, s;
long long bit[30];


int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	//freopen("a.in","r",stdin);
	freopen("b.out","w",stdout);
	int tt = 0, cs=0;
	scanf("%d", &tt);
	while ( tt-- ){
		scanf("%d%d", &s, &n);
		for (int i=0; i<n; i++)
			scanf("%d", a+i);
		sort( a, a+n );

		bit[0] = 1;
		for (int i=1; i<=20; i++)
			bit[i] = bit[i-1]*2;

		int ret = 0, RET=10000000;
		long long cur = s;
		for (int i=0; i<n; i++)
		if ( cur <= a[i] ){
				RET = std::min( RET, ret+n-i );
				ret ++;
				cur = cur+cur-1;
				i--;
				if ( cur==1 ){
					ret = 10000000;
					break;
				}
		}else cur += a[i];

		RET = std::min( RET, ret );

		printf("Case #%d: %d\n", ++cs, RET);
	}
	return 0;
}
