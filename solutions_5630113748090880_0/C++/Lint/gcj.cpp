#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
#define rep(i,s,t) for(int i=int(s); i<int(t); i++)
#define mst(A,k) memset(A,k,sizeof(A))

int n;
int a[2550];
int ans[55];

int main() {
	freopen("B-small-attempt0.in","r",stdin); 
	freopen("ans.txt","w",stdout); 

	int T;
	scanf("%d", &T);
	rep(cas, 0, T)
	{
		scanf("%d", &n);
		int aa;
		mst(a, 0);
		rep(i, 0, 2 * n - 1)
		{
			rep(j, 0, n)
			{
				scanf("%d", &aa);
				a[aa]++;
			}
		}
		int _ans = 0;
		rep(i, 1, 2501) if(a[i] && a[i] % 2 == 1)
		{
			ans[_ans++] = i;
		}
		printf("Case #%d:", cas + 1);
		rep(i, 0, n) printf(" %d", ans[i]);
		printf("\n");
	}
	return 0;
}

