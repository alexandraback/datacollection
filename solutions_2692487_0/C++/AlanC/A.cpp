#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#define LL long long int

#define FOR(i, s, e) for (int i=(s); i<(e); i++)
#define FOE(i, s, e) for (int i=(s); i<=(e); i++)
#define FOD(i, s, e) for (int i=(s)-1; i>=(e); i--)
#define CLR(x, a) memset(x, a, sizeof(x))

using namespace std;

int test, cur, n, a[105], h, ret, eat;

int main(){

	scanf("%d", &test);
	FOR(TC, 0, test){
		scanf("%d%d", &cur, &n);
		
		FOR(i, 0, n) scanf("%d", &a[i]);
		sort(a, a + n);
		
		if (cur == 1){
			printf("Case #%d: %d\n", TC + 1, n);
			continue;
		}
		
		
		ret = n + 1;
		
		h = 0;
		eat = 0;
		while (h < n){
			while (h < n && cur > a[h]){
				cur += a[h];
				h++;
			}
			ret = min(ret, n - h + eat);
			eat++;
			cur = cur + cur - 1;
		}
		
		printf("Case #%d: %d\n", TC + 1, ret);
		
	}
	return 0;
}
