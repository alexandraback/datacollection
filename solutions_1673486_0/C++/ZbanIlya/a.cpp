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

const int maxn=101000, mod=1000000007;
const double eps=1e-9;



int n,ans;
int a,b;
long double p[maxn],q[maxn];
long double d[maxn];

int main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	cout.precision(20);
	int tests;
	scanf("%d",&tests);
	for (int test=0; test<tests; test++) {
		scanf("%d%d",&a,&b);
		for (int i=0; i<a; i++) 
			scanf("%lf",&p[i]), q[i]=1-p[i];
		long double ans=b+2;

		d[0]=1;
		for (int i=1; i<=a; i++)
			d[i]=d[i-1]*p[i-1];

		for (int i=0; i<=a; i++) {
			long double sum=0;
			sum+=d[i]*((a-i)*2+b-a+1);
			sum+=(1-d[i])*((a-i)*2+b-a+2+b);
			if (ans-sum>eps) 
				ans=sum;
			/*for (int j=0; j<=i; j++) {
				sum+=d[j]*(
			}*/
		}


		cout << "Case #" << test+1 << ": ";
		cout << ans;
		cout << endl;
	}

	return 0;
}