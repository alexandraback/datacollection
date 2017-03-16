#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>
#include <utility>
#include <queue>
#include <map>
#include <set>
using namespace std;

const double EPS = 1e-10;
const double PI = acos(-1.0);

typedef long long LL;

const int MAXN = 100000+1;

double p[MAXN];
int n,m;

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int testn;
	scanf("%d",&testn);
	for (int loop = 1; loop<=testn; ++loop) {
		printf("Case #%d: ",loop);
		scanf("%d%d",&n,&m);
		for (int i = 0; i<n; ++i)
			scanf("%lf",&p[i]);
		//keep typing
		double correct = 1;
		for (int i = 0; i<n; ++i)
			correct *= p[i];
		double ans1 = correct*(m-n+1)+(1-correct)*(m-n+1+m+1);
		//cout<<"  -  "<<ans1<<endl;
		//press enter right away
		double ans2 = 1+m+1;
		double ans3 = n+m+1;
		correct = 1;
		for (int i = 0; i<n-1; ++i) {
			correct *= p[i];
			double tmp = n-i-1+correct*(m-i-1+1)+(1-correct)*(m-i-1+1+m+1);
			//cout<<"  -  "<<tmp<<' '<<i<<endl;
			if (tmp<ans3) ans3 = tmp;
		}
		printf("%.6f\n",min(ans3,min(ans2,ans1)));
	}
	return 0;
}
