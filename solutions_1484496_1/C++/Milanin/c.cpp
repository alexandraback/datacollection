#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#define N 501
#define K 30100000
using namespace std;
long long a[N];
struct T
{
	long long s;
	int h;
	T(long long s=0, int h=0): s(s), h(h) {}
};
bool operator <(T a, T b) { return a.s<b.s; }
T q[K];
int main()
{
	int t, ts, i, j, k, n, l;
	for(scanf("%d", &ts), t=1; t<=ts; t++)
	{
		for(scanf("%d", &n), i=0; i<n; scanf("%lld", &a[i]), i++);
		for(l=0, i=0; i<n; q[l++]=T(a[i], (n*N+n)*N+i), i++)
			for(j=i+1; j<n; q[l++]=T(a[i]+a[j], (n*N+j)*N+i), j++)
				for(k=j+1; k<n; q[l++]=T(a[i]+a[j]+a[k], (k*N+j)*N+i), k++);
		sort(q, q+l);
		for(i=0; i<l-1 && q[i].s<q[i+1].s; i++);
		printf("Case #%d:\n", t);
		if(i<l-1)
		{
			printf("%lld", a[q[i].h%N]);
			q[i].h/=N;
			if(q[i].h%N<n)
				printf(" %lld", a[q[i].h%N]);
			q[i].h/=N;
			if(q[i].h%N<n)
				printf(" %lld", a[q[i].h%N]);
			printf("\n");
			i++;
			printf("%lld", a[q[i].h%N]);
			q[i].h/=N;
			if(q[i].h%N<n)
				printf(" %lld", a[q[i].h%N]);
			q[i].h/=N;
			if(q[i].h%N<n)
				printf(" %lld", a[q[i].h%N]);
			printf("\n");
		}
		else printf("Impossible\n");
	}
	return 0;
}