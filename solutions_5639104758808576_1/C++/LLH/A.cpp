#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;
const int maxn=1100;

int n;
char s[maxn];
void solve(int icase) {
	scanf("%d %s",&n,s);

	int stand=0, ans=0;
	for(int i=0;i<=n;i++) {
		int num=s[i]-'0';
		if(num>0) {
			if(stand<i)
				ans+=i-stand, stand+=i-stand;
			stand+=num;
		}
	}
	printf("Case #%d: %d\n",icase,ans);
}
int main() {
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
		solve(i);
	scanf("%*s");
	return 0;
}
/*
2
3
1 3 -5
-2 4 1
5
1 2 3 4 5
1 0 1 0 1
*/
