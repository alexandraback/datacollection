#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

long long powerOfTens[15];

long long getLastHalfNum(long long N)
{
	ostringstream sout;
	sout << N;

	string str = sout.str();
	int len = str.length();
	
	return atoi(str.substr(len/2).c_str());
}

long long solve(long long N)
{
	if (N<=20)
		return N;

	long long added = 0;
	if (getLastHalfNum(N) == 0)
	{
		++added;
		--N;
	}
	
	ostringstream sout;
	sout << N;

	string str = sout.str();
	int len = str.length();
	
	string firstHalf = str.substr(0, len / 2);
	string lastHalf = str.substr(len/2);

	reverse(firstHalf.begin(), firstHalf.end());

	long long base = powerOfTens[len - 1];
	
	long long ans = base;
	ans += atoi(firstHalf.c_str());
	++ans;
	ans += atoi(lastHalf.c_str()) - 1;
	
	return min(ans, base + N - (long long)pow(10, len-1)) + added;
}

int main()
{
	powerOfTens[0] = 1;
	powerOfTens[1] = 10;
	for (int i=2; i<15; ++i)
	{
		powerOfTens[i] = powerOfTens[i-1] + (pow(10, i/2) - 1) + 1 + (pow(10, (i+1)/2) - 1);
	}
	
	int t;
	scanf("%d", &t);
	for (int tc=1; tc<=t; ++tc)
	{
		long long N;
		scanf("%lld", &N);
		printf("Case #%d: %lld\n", tc, solve(N));
	}
	
	return 0;
}