#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long lli;
#define LIM 113
inline int gcd (int a, int b)
{
	return b==0?a:gcd(b,a%b);
}
int n, m;
vector<lli> a(LIM), b(LIM), A(LIM), B(LIM);
lli fun(vector<lli> a, vector<lli> b, int p, int q)
{
	if (p>=n) return 0;
	if (q>=m) return 0;
	lli ans = 0;
	if (A[p]==B[q])
	{
		lli v=min(a[p], b[q]);
		a[p]-=v;
		b[q]-=v;
		if (a[p]==0) p++;
		if (b[q]==0) q++;
		ans=v;
		ans+=fun(a, b, p , q);
	}
	else 
	{
		ans += max (fun(a, b, p+1 , q), max(fun(a, b, p , q+1), fun(a, b, p+1 , q+1)));
	}
	return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) 
    {
        scanf("%d%d", &n, &m);
        for (int i=0; i<n; i++)
        scanf("%lld%lld",&a[i],&A[i]);
        for (int i=0; i<m; i++)
        scanf("%lld%lld",&b[i],&B[i]);
        printf("Case #%d: %lld\n",tc,fun(a, b, 0, 0));
    }
    return 0;
}
