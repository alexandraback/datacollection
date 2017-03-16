#include <stdio.h>
#include <assert.h>
#include <vector>
#include <deque>
#include <map>

using std::vector;
using std::deque;
using std::map;

unsigned long long reverse(unsigned long long n)
{
	unsigned long long ret = 0;
	for(;n != 0;n /= 10)
	{
		ret *= 10;
		ret += n%10;
	}
	return ret;
}

unsigned long long get_count(unsigned long long n)
{
	if(n <= 10) return n;
	unsigned long long init = 0;
	if(0 == (n%10)) { --n;++init; }
	vector<unsigned int> digits;
	for(unsigned long long i = n;i != 0;i /= 10) digits.push_back(i%10);

	unsigned long long lv = 0,rv = 0;
	size_t left = 0,right = digits.size()-1;
	for(;left < right;++left,--right)
	{
		lv *= 10;lv += digits[left];
		rv *= 10;rv += digits[right];
	}
	lv = reverse(lv);
	rv = reverse(rv);

	unsigned long long x = 0;
	for(size_t i = 1;i < digits.size();++i) { x *= 10;x += 9; }
	unsigned long long ans = lv - 1 + rv - 1 + 2;
	if(1 != rv) ans += 1;
	if(left == right)
	{
		unsigned long long y = 1;
		for(size_t i = 0;i < left;++i) y *= 10;
		ans += digits[left]*y;
	}
	return get_count(x) + ans + init;

	//unsigned long long ans = 1;
	//for(;;++ans)
	//{
	//	for(;1 != (n%10);++ans,--n);
	//	if(n == 1) break;
	//	unsigned long long r = reverse(n);
	//	//printf("%u %I64u\n",i,r);
	//	if(r >= n) { --n;continue; }
	//	n = r;
	//}
	//return ans;
	return 0;
}

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned long long n = 0;scanf("%I64d",&n);
		unsigned long long ans = get_count(n);
		printf("Case #%u: %I64u\n",iCases,ans);
	}

	//static const unsigned int maxn = 10000000;
	//vector<unsigned int> values(maxn+1,maxn+10);
	//values[1] = 1;
	//deque<unsigned int> que;que.push_back(1);
	////unsigned int prev = 1;
	//for(;!que.empty();que.pop_front())
	//{
	//	unsigned int u = que.front();

	//	//if(values[u] != prev)
	//	//{
	//		//if(prev <= 370) printf("\n");
	//	//	prev = values[u];
	//	//}
	//	//if(prev <= 370) printf("%d ",u);

	//	if(u + 1 <= maxn)
	//	{
	//		if(values[u]+1 < values[u+1])
	//		{
	//			assert(values[u+1] == maxn+10);
	//			values[u+1] = values[u]+1;
	//			que.push_back(u+1);
	//		}
	//	}
	//	unsigned int r = (unsigned int)(reverse(u));
	//	if(r <= maxn)
	//	{
	//		if(values[u]+1 < values[r])
	//		{
	//			assert(values[r] == maxn+10);
	//			values[r] = values[u]+1;
	//			que.push_back(r);
	//		}
	//	}
	//}
	//printf("%d\n",values[123456]);
	//return 0;

	//unsigned int nCases = 0;scanf("%d",&nCases);
	//for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	//{
	//	unsigned long long n = 0;scanf("%I64d",&n);
	//	unsigned long long ans = 0;
	//	if(n <= maxn) ans = values[n];
	//	printf("Case #%u: %I64u\n",iCases,ans);
	//}
	return 0;
}