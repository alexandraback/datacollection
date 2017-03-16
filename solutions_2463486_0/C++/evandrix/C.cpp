#include <cstdio>
#include <iterator>
#include <algorithm>

using namespace std;

#define FOR(i,a,b)   for(int(i)=int(a);(i)<int(b);(i)++)
#define FOREQ(i,a,b) for(int(i)=int(a);(i)<=int(b);(i)++)

typedef unsigned long long ULL;

static int T,A,B;

inline bool is_palindrome(ULL num)
{
	if (num < 10) return true;
	ULL original = num;
	int digit;
	ULL rev = 0ULL;
	do
	{
		digit = num%10;
		rev = (10*rev) + digit;
		num /= 10;
	} while (num!=0ULL);
//	printf("%llu==%llu\n", original,rev);
	return original == rev;
}

int main()
{
	scanf("%d", &T);
	
	// precompute small
/*
	FOREQ(i,1,1000)
	{
		if (i*i > 1000) break;
		if (is_palindrome(i) && is_palindrome(i*i))
			printf("%llu\n", i*i);
	}
*/
	int palindromes[5] = { 1,4,9,121,484 };

	FOREQ(t,1,T)
	{
		scanf("%d%d", &A,&B);
		printf("Case #%d: %d\n", t,distance(
			lower_bound(palindromes,palindromes+5,A),
			upper_bound(palindromes,palindromes+5,B)));
	}

	return 0;
}
