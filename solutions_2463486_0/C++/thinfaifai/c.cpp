#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long

int tot[10000005];

bool isp(LL a) {
	char s[105];
	sprintf(s,"%lld",a);
	int len = strlen(s);
	for (int i=0; i<=len/2; i++)
		if (s[i] != s[len-1-i]) return false;
	return true;
}

int main() {
	tot[0] = 0;
	for (int i=1; i<=10000000; i++) {
		tot[i] = 0;
		if (isp(i) && isp(i*1LL*i)) {
			tot[i]++;
		}
		tot[i] += tot[i-1];
	}

	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
		LL a,b;
		scanf("%lld%lld",&a,&b);
		LL ta = (LL)sqrt(a);
		ta--;
		while (ta*ta < a) ta++;
		LL tb = (LL)sqrt(b);
		tb++;
		while (tb*tb > b) tb--;
		if (ta > tb) printf("Case #%d: 0\n",t);
		else printf("Case #%d: %d\n",t,tot[tb]-tot[ta-1]);
	}

	return 0;
}
