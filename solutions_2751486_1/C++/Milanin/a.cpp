#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <string.h>
using namespace std;
#define N 1000100
int d[N];
char s[N];
bool vo(char c) { return c=='a' || c=='o' || c=='u' || c=='e' || c=='i'; }
int main()
{
	int ts, tst;
	int n, i, j, k;
	long long r;
	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
	{
		printf("Case #%d: ", ts);
		scanf("%s%d", s, &k);
		n=strlen(s);
		for(d[n]=n, j=0, i=n-1; i>=0; i--)
		{
			if(vo(s[i])) j=0;
			else j++;
			if(j>=k) d[i]=i;
			else d[i]=d[i+1];
		}
		for(r=0, i=0; i<n; i++)
			if(d[i]<n) r+=n-(d[i]+k)+1;
		printf("%lld\n", r);
	}
	return 0;
}