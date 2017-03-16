#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <cctype>

#define SZ 200005
#define INF (1<<29)
using namespace std;

typedef long long Long;

int Sum[SZ];
char str1[SZ];
int n;

int main()
{
	freopen("Stand.in.txt","rt",stdin);
	freopen("Stand.out","wt",stdout);
	int tst,cas;
	scanf("%d",&tst);
	for(cas=1;cas<=tst;cas++) {
		scanf("%d%s",&n,str1);
		for(int ans=0;ans<=n;ans++) {
			int sum = ans;
			bool pl = true;
			for(int i=0;i<=n;i++) {
				if(sum<i) {
					pl = false;
					break;
				}
				sum += str1[i] - '0';
			}
			if(pl) {
				printf("Case #%d: %d\n",cas,ans);
				break;
			}
		}
	}

	return 0;
}