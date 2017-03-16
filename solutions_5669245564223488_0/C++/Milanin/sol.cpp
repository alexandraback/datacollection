#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 110
#define mod 1000000007
int a[N];
char m[N][N], s[N*N], u[26];
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		int i, j, l, n, r;
		scanf("%d", &n);
		for(i=0; i<n; a[i]=i, scanf("%s", m[i]), i++);
		r=0;
		for(; ; )
		{
			l=0;
			for(i=0; i<n; i++)
				for(j=0; m[a[i]][j]; s[l++]=m[a[i]][j], j++);
			for(i=0; i<26; u[i]=0, i++);
			for(i=0; i<l; u[s[i]-'a']=1, i++)
				if(i && s[i]!=s[i-1] && u[s[i]-'a']) break;
			r+=i==l;
			if(!next_permutation(a, a+n)) break;
		}
		printf("Case #%d: %d\n", t, r);
	}
	return 0;
}
