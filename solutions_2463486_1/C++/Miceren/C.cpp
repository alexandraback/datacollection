#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long ans[] = {0ll,1LL,4LL,9LL,121LL,484LL,10201LL,12321LL,14641LL,40804LL,44944LL,1002001LL,1234321LL,4008004LL,100020001LL,102030201LL,104060401LL,121242121LL,123454321LL,125686521LL,400080004LL,404090404LL,10000200001LL,10221412201LL,12102420121LL,12345654321LL,40000800004LL,1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL};
//vector<int > 
/*
int a[20];

int ok(long long x)
{
	int len = 0;
	while(x)
	{
		a[++len] = x % 10;
		x /= 10;
	}
	for(int i = 1; i <= len / 2; i++)
		if (a[i] != a[len - i + 1])
			return 0;
	return 1;
}
*/
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	/*
	int cnt = 0;
	
	for(int i = 1; i <= 10000000; i++)
	{
		long long tmp = i;
		tmp = tmp * tmp;
		if (ok(i) && ok(tmp))
		{
			printf(",%I64dLL", tmp);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	*/
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		long long L, R;
		scanf("%I64d %I64d", &L, &R);
		int l = 1, r = 39;
		while(l < r)
		{
			int mid = (l + r) / 2;
			if (L <= ans[mid])
				r = mid;
			else
				l = mid + 1;
		}
		L = l;
		l = 1, r = 39;
		while(l < r)
		{
			int mid = (l + r) / 2 + 1;
			if (ans[mid] <= R)
				l = mid;
			else
				r = mid - 1;
		}
		R = l;
		printf("%I64d\n", R - L + 1);
	}
	return 0;
}
