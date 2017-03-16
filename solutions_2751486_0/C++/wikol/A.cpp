#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char T[1000005];
int n,k;

bool isVowel(char a)
{
	return (a == 'a') || (a == 'o') || (a == 'i') || (a == 'e') || (a == 'u');
}
void read()
{
	scanf("%s%d", T+1,&k);
	n = strlen(T+1);
}
void solve(int tc)
{
	int cons = 0;
	int l = -1;
	long long result = 0;
	for(int i = 1;i<=n;i++)
	{
		cons++;
		if(isVowel(T[i]))
			cons = 0;
		if(cons >= k)
			l = i-k+1;
		if(l != -1)
			result += l;
	}
	printf("Case #%d: %lld\n", tc, result);
}
int main()
{
	int Z;
	scanf("%d", &Z);
	for(int i = 1;i<=Z;i++)
	{
		read();
		solve(i);
	}
}
