#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

int T, A, B;

int reverseNumber(int num)
{
	int result = 0;
	while(num)
	{
		result *= 10;
		result += num%10;
		num/=10;
	}
	return result;
}

bool isPalindrome(int num)
{
	return num == reverseNumber(num);
}

int solve()
{
	int result = 0;
	for(int i = 1; i*i <= B; i++)
	{
		if(i*i < A) continue;
		if(isPalindrome (i) && isPalindrome(i*i)){
			result++;
		}
	}
	return result;
}

int main()
{
	scanf("%d", &T);

	for(int c = 1; c <= T; c++)
	{
		scanf("%d %d", &A, &B);
		
		printf("Case #%d: %d\n", c, solve());
	}


	return 0;
}
