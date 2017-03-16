#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>
#include<iostream>

using namespace std;

int T, A, B;
int a[2000010];

long long calc()
{
	long long ret = 0;
	int n = 0;
	int base = 1;

	for (int i=A; i<=B; i++)
		if (a[i]==0)
		{
			long long c = 1;
			a[i] = 1;
			while (i/base>=10) {
				base*=10;
				n+=1;
			}
			int cur = i;
			for (int t=0; t<n; t++)
			{
				cur = (cur % 10) * base +cur / 10;
				if (A<=cur && cur<=B && a[cur]==0) {
					c++;
					a[cur] = 1;
				}
			}
			ret = ret + c*(c-1)/2;
		}
	return ret;
}

int main()
{
	freopen("C:/Users/yaoyao/Downloads/C-small-attempt0.in", "r", stdin);
	freopen("C:/Users/yaoyao/Downloads/out.txt", "w", stdout);
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		scanf("%d%d", &A, &B);
		memset(a,0,sizeof(a));
		printf("Case #%d: ", i);
		cout << calc() << endl;
	}
	return 0;
}