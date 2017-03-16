#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int T;
long long A, B;

vector<long long> fairAndSquare;

long long reverseNumber(long long num)
{
	long long result = 0;
	while(num)
	{
		result *= 10;
		result += num%10;
		num/=10;
	}
	return result;
}

bool isPalindrome(long long num)
{
	return num == reverseNumber(num);
}

int pre()
{
	int result = 0;
	for(long long i = 1; i <= 10000000; i++)
	{
		if(isPalindrome (i) && isPalindrome(i*i)){
			fairAndSquare.push_back(i*i);
		}
	}
	return result;
}

int solve()
{
	int idx = 0;
	for(idx = 0; idx < fairAndSquare.size(); idx++)
	{
		if(fairAndSquare[idx] >= A) break;
	}

	int result = 0;
	for(; idx < fairAndSquare.size(); idx++)
	{
		if(fairAndSquare[idx] <= B) result++;
		else break;
	}
	return result;
}

int main()
{
	scanf("%d", &T);

	pre();

	for(int c = 1; c <= T; c++)
	{
		scanf("%lld %lld", &A, &B);
		
		printf("Case #%d: %d\n", c, solve());
	}

	return 0;
}
