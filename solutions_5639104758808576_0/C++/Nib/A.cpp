#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int t, n;
	scanf("%d", &t);
	for(int rep = 1;rep <= t;rep++)
	{
		scanf("%d", &n);
		char A[n+5];
		scanf("%s", A);
		int standing = A[0]-'0', ans = 0;
		for(int i = 1;i < n+1;i++)
		{
			int tmp = A[i]-'0';
			if(standing < i)
			{
				ans += i-standing;
				standing = i;
			}
			standing += tmp;
		}
		printf("Case #%d: %d\n", rep, ans);
	}
}