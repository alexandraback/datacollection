/* Vipul Jain */

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FB(i,a,n) for(int i=(a);i>=(n);--i)
#define FI(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define Sf(x) scanf("%f",&x)
#define Sd(x) scanf("%lf",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
#define fi first
#define se second

int main()
{
	int t;
	S(t);
	int cases = 0;
	while (t--) {
		cases++;
		int a[35];
		M(a, 0);
		int c, d ,v;
		S(c);S(d);S(v);
		F(i, 0, d) {
			int x;
			S(x);
			a[x] = 1;
		}
		int sum = 0;
		int count = 0;
		F(i, 1, v + 1) {
			if (a[i]) {
				sum += i;
				continue;
			}
			if (i > sum) {
				count++;
				sum += i;
			}
		}
		cout << "Case #" << cases << ": " << count << endl;
	}
    return 0;
}