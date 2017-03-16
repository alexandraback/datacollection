#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, ret1, ret2;
int f[2000], lnk[2000];
bool b[2000];

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("small.out","w",stdout);
	
	int task; scanf("%d", &task);
	for (int cs=1; cs<=task; cs++){
		scanf("%d", &n);
		for (int i=1; i<=n; i++){
			scanf("%d", f+i);
		}

		memset(lnk, 0 , sizeof(lnk));

		ret1 = 0; ret2 = 0;
		for (int i=1; i<=n; i++){
			memset(b, 0, sizeof(b));
			int len = 0;
			int x = i;
			for (; !b[x]; x=f[x] ){
				b[x] = true;
				len++;
			}

			if (x==i){
				ret1 = max(ret1, len);
			}

			if (x==f[f[x]]){
				lnk[x] = max(lnk[x], len-2);
			}
		}

		for (int i=1; i<=n; i++)
		if (i==f[f[i]] && i<f[i]){
			ret2 += 2 + lnk[i] + lnk[f[i]];
		}
		
		printf("Case #%d: %d\n", cs, max(ret1, ret2));
	}	
	return 0;
}
