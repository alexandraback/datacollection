#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>

using namespace std;

int dp[32][2];
int a,b,k;

int count(int razr, bool isrestr) {
	if (razr<0)
		return 1;
	if (!isrestr) {
		int cur=k&((1<<razr)-1);
		int cnt=razr;
		for (int i=0;i<razr;i++) {
			if (cur&(1<<i))
				cnt--;
		}
		return (1<<cnt);
	}
	int abit=((a>>(1<<razr))&1);
	int bbit=((b>>(1<<razr))&1);
	int kbit=((k>>(1<<razr))&1);
	if (kbit==1) {
		if (abit==1&&bbit==1)
			return count(razr-1,true);
		else
			return 0;
	}	
	if (abit==0&&bbit==0) {
		return count(razr-1,true);
	} else {
		int res=0;
		if (abit==0&&bbit==1) {
			res+=count(razr-1,false);
			res+=count(razr-1,true);
			return res;
		}
	}
}

void solve(int t) {
	cin>>a>>b>>k;
	int cnt=0;
	for (int i=0;i<a;i++) {
		for (int j=0;j<b;j++) {
			if ((i&j)<k) {
				cnt++;
			}
		}
	}
	printf("Case #%d: %d\n",t,cnt);
}

int main() {

	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
		solve(i+1);
	}
	return 0;
}