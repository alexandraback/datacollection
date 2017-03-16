#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
//#include <time.h>
//#include <stdlib.h>
//#include <math.h>
//#include <queue>
#include <vector>
//#include <stack>
//#include <set>
#include <map>
#include <algorithm>
//#include <sstream>
using namespace std;

const int maxn=100005;

int a,b;
double p[maxn];
double ans;

void solve() {
	p[0]=1;
	ans=1+b+1;
	double nowp=1,now;
	for (int i=0;i<=a;i++) {
		nowp*=p[i];
		now=nowp*((a-i)+b-i+1)+(1-nowp)*((a-i)+b-i+1+b+1);
		ans=min(ans,now);
//		cout<<i<<" "<<now<<endl;
	}
}

int main() {
	int T,kase=0;
	cin>>T;
	while (T--) {
		cin>>a>>b;
		for (int i=1;i<=a;i++)
			scanf("%lf",&p[i]);
		solve();
		printf("Case #%d: %.6lf\n",++kase,ans);
	}
	return 0;
}

