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
#define N 110
char s[N];
bool vo(char c) { return c=='a' || c=='o' || c=='u' || c=='e' || c=='i'; }
int is(string s)
{
	int k, r, i;
	for(r=0, i=0; i<s.size(); r=max(r, k), i++)
		if(!vo(s[i])) k++;
		else k=0;
	return r;
}
int main()
{
	int ts, tst;
	int n, i, j, k, r;
	string t;
	for(scanf("%d", &tst), ts=1; ts<=tst; ts++)
	{
		printf("Case #%d: ", ts);
		scanf("%s%d", s, &k); t=s;
		n=t.size();
		for(r=0, i=k; i<=n; i++)
			for(j=0; j+i<=n; j++)
				if(is(t.substr(j, i))>=k) r++;
		printf("%d\n", r);
	}
	return 0;
}