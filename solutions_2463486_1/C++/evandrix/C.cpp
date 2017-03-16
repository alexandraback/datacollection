#include <cstdio>
#include <iterator>
#include <algorithm>

using namespace std;

#define FOR(i,a,b)   for(int(i)=int(a);(i)<int(b);(i)++)
#define FOREQ(i,a,b) for(int(i)=int(a);(i)<=int(b);(i)++)

typedef unsigned long long ULL;

static int T;

inline bool is_palindrome(ULL num)
{
	if (num < 10) return true;
	int dig = 0;
	ULL n = num, rev = 0ULL;
	while (num > 0)
	{
		dig = num % 10;
		rev = rev * 10 + dig;
		num /= 10;
	}
//	printf("%llu==%llu\n", n,rev);
	return n == rev;
}

int main()
{
	scanf("%d", &T);
	// SMALL
/*
	FOREQ(i,1,1000)
	{
		if (i*i > 1000) break;
		if (is_palindrome(i) && is_palindrome(i*i))
			printf("%llu ", i*i);
	}
	printf("\n");
	int palindromes[5] = {1,4,9,121,484};
*/
	// LARGE-1
/*
	int count = 0;
	ULL i = 1ULL;
	while(i<=1E14)
	{
		if (i*i > 1E14) break;
		if (is_palindrome(i) && is_palindrome(i*i))
		{
			printf("%llu ", i*i);
			count++;
		}
		i++;
	}
	printf("\n");
	printf("total: %d answers\n", count);
*/
	ULL palindromes[39] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};
	
	FOREQ(t,1,T)
	{
		// SMALL
/*
		int A=0,B=0;
		scanf("%d%d", &A,&B);
		printf("Case #%d: %d\n", t,distance(
			lower_bound(palindromes,palindromes+5,A),
			upper_bound(palindromes,palindromes+5,B)));
*/
		// SMALL
		ULL A=0ULL, B=0ULL;
		scanf("%llu%llu", &A,&B);
		printf("Case #%d: %d\n", t,distance(
			lower_bound(palindromes,palindromes+39,A),
			upper_bound(palindromes,palindromes+39,B)));
/*
		if (distance(
			lower_bound(palindromes,palindromes+39,A),
			upper_bound(palindromes,palindromes+39,B))!=0)
		{
			printf("\tA:%llu - B:%llu [%llu-%llu)\n", A,B,*lower_bound(palindromes,palindromes+39,A),*upper_bound(palindromes,palindromes+39,B));
		}
*/
	}

	return 0;
}
