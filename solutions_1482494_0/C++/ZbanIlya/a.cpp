#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

#pragma comment(linker,"/STACK:256000000")

const int maxn=1010, mod=1000000007;
const double eps=1e-6;



int n,ans;
int a[maxn],b[maxn];
bool fa[maxn],fb[maxn];



int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int tests;
	scanf("%d",&tests);
	for (int test=0; test<tests; test++) {

		scanf("%d",&n);
		for (int i=0; i<n; i++)
			scanf("%d%d",&a[i],&b[i]);
		for (int i=0; i<n; i++)
			fa[i]=fb[i]=false;
		
		ans=0;
		int cur=0;
		while (1) {
			bool f=true, g=false;
			int cans=0, ci=-1;
			for (int i=0; i<n; i++) {
				if (!fb[i] && !fa[i] && a[i]<=cur && b[i]<=cur) {
					cans=2;
					ci=i;
					f=false;
					break;				
				}
				if ((cans==0 || g && b[i]>b[ci]) && a[i]<=cur && !fa[i]) {
					cans=1;
					ci=i;
					f=false;
					g=true;
				}
				if (b[i]<=cur && !fb[i]) {
					cans=1;
					ci=i;
					f=false;
					g=false;
				}
			}
			if (ci==-1) break;
			ans++;
			fb[ci]=b[ci]<=cur;
			cur+=cans;
			fa[ci]=true;
			if (cur==2*n) break;
		}

		
		
		cout << "Case #" << test+1 << ": ";
		if (cur!=2*n) cout << "Too Bad";
		else cout << ans;
		cout << endl;
	}

	return 0;
}