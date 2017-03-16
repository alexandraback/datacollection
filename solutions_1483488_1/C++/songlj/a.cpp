#include <iostream>
#include <stdio.h>
#include <string.h>
//#include <time.h>
//#include <stdlib.h>
//#include <math.h>
//#include <queue>
//#include <vector>
//#include <stack>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <sstream>
using namespace std;

const int maxn=2000005;

int a,b;
int ans;
int c[10];

void solve() {
	ans=0;
	int n=0,now=a/10,ten=1;
	while (now) now/=10,ten*=10,n++;
//	cout<<ten<<" "<<n<<endl;
	for (int i=a;i<b;i++) {
		now=i;
		for (int j=0;j<n;j++) {
			now=(now%10)*ten+now/10;
			bool flag=true;
			for (int k=0;k<j;k++)
				if (c[k]==now) {
					flag=false;
					break;
				}
			if (now>i&&now<=b&&flag) ans++;
			c[j]=now;
		}
	}
}

int main() {
	int T,kase=0;
	cin>>T;
	while (T--) {
		cin>>a>>b;
		solve();
		printf("Case #%d: %d\n",++kase,ans);
	}
        return 0;
}

