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

const int MAXN = 1000+1;

bool t[MAXN][2];
int a[MAXN],b[MAXN],n;

bool check() {
	for (int i = 0; i<n; ++i)
		if (!t[i][1]) return 0;
	return 1;
}

bool get(int &cur) {
	int mmin = INT_MAX,k = -1;
	for (int i = 0; i<n; ++i)
		if (mmin>b[i] && b[i]<=cur && !t[i][1]) {
			mmin = b[i];
			k = i;
		}
	if (k!=-1) {
		if (t[k][0]) ++cur;
		else cur += 2;
		t[k][0] = t[k][1] = 1;
		//cout<<"   -   "<<k<<' '<<2<<endl;
		return 1;
	}
	int mmax = INT_MIN;
	for (int i = 0; i<n; ++i)
		if (a[i]<=cur && !t[i][0] && mmax<b[i]) {
			mmax = b[i];
			k = i;
		}
	if (k==-1) return 0;
	t[k][0] = 1;
	++cur;
	//cout<<"   -   "<<k<<' '<<1<<endl;
	return 1;
}

int main() {
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for (int loop = 1; loop<=ntest; ++loop) {
		printf("Case #%d: ",loop);
		scanf("%d",&n);
		for (int i = 0; i<n; ++i) {
			scanf("%d%d",&a[i],&b[i]);
		}
		memset(t,0,sizeof(t));
		int cur = 0,ans = 0;
		while (get(cur)) ++ans;
		if (!check()) printf("Too Bad\n");
		else printf("%d\n",ans);
	}
	return 0;
}
