#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<string>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int>::iterator iv;
typedef map<string,int>::iterator im;
#define rep(i, n) for(i=0; i<n; i++)

double p[100000];

int main()
{
	int t, c, a, b, i, j;
	cin >> t;
	rep(c, t)
	{
		cin >> a >> b;
		rep(i, a)
			cin >> p[i];
		double ans = 10000000, pp=1;
		for(i=0; i<a; pp*=p[i++])
		{
			ans = min(ans, (a-i+b-i+1)*pp + (a-i+b-i+b+2)*(1-pp));
		}
		ans = min(ans, pp*(b-a+1)+(1-pp)*(b-a+1+b+1));
		ans = min(ans, b+2.0);
		printf("Case #%d: %.6lf\n", c+1, ans);
	}
}
