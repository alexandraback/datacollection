#include <cstdio>
#include <cstring>
#include <iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
#define Max 1000005
#define LL long long
char st[Max];
int len;
int f[Max];
char yuan[] = "aeiou";
int n;
bool jud(char a)
{
	for (int i = 0; i < 5; i++)
		if (a == yuan[i])
			return false;
	return true;
}
LL fun()
{
	len = strlen(st);
	if (n > len) return 0;
	int temp = -1;
	if (jud(st[0])) f[0] = 1;
	else f[0] = 0;
	int i = 1;
	while (i < len && f[i - 1] < n)
	{
		if (jud(st[i]))  f[i] = f[i - 1] + 1;
		else f[i] = 0;
		i++;
	}
	if (f[i - 1] < n) return 0;
	temp = i - n;
	LL ans = temp + 1;
	while(i<len)
	{
		if (jud(st[i])) f[i] = f[i - 1] + 1;
		else f[i] = 0;
		if (f[i] >= n)
			temp = i - n + 1;
		ans += temp + 1;
		i++;
	}
	return ans;
}
int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		scanf("%s", st);
		scanf("%d", &n);
		printf("%I64d\n", fun());
	}
	return 0;
}
