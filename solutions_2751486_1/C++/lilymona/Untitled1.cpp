#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char s[1000010];
int n;

inline bool IsCons(char c)
{
	return !(c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

long long work()
{
	int len = strlen(s);
	static int a[1000010];
	a[0] = IsCons(s[0]);
	for(int i=1;i<len;i++)
	{
		if(IsCons(s[i])) a[i] = a[i-1] + 1;
		else a[i] = 0;
	}
	long long ans = 0;
	for(int cur=len,i=len-1;i>=n-1;i--)
	{
		if(a[i]>=n) cur = i;
		ans += len-cur;
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s %d", s, &n);
		printf("Case #%d: %lld\n",i+1,work());
	}
	return 0;
}
