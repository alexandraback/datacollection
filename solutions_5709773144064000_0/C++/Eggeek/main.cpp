#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;
#define eps 1e-7
struct node {
	double v,need;
};

void work() {
	double c,f,x;
	scanf("%lf%lf%lf",&c,&f,&x);
	vector<node> s;
	double need = 0.0 , v = 2.0;
	for (int i=0 ; i<=1000000; i++ ) {
		s.push_back((node){v,need});
		double use = c/v;
		need += use;
		v += f;
	}
	double ans = x/2.0;
	for (int i=0 ; i<(int)s.size() ; i++ ) {
		double use = s[i].need + x/s[i].v;
		ans = min(use,ans);
	}
	printf("%.7lf\n",ans);
}
// Case #1: 1.0000000
// Case #2: 39.1666667
// Case #3: 63.9680013
// Case #4: 526.1904762
int main() {
	int cas;
	freopen("test.txt", "r", stdin);
	freopen("ans.txt", "w", stdout);
	scanf("%d",&cas);
	for (int t=1 ; t<=cas ; t++ ) {
		printf("Case #%d: ",t);
		work();
	}
	return 0;
}