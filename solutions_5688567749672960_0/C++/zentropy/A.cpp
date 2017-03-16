#include <stdio.h>
#include <assert.h>
#include <vector>
#include <deque>

using std::vector;
using std::deque;

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

int main()
{
	//unsigned int nCases = 0;scanf("%d",&nCases);
	//for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	//{
	//	unsigned long long n = 0;scanf("%I64d",&n);
	//	unsigned long long ans = 1;
	//	for(unsigned int i = 1;;++ans)
	//	{
	//		if(i == n) break;
	//		unsigned long long r = reverse(i);
	//		//printf("%u %I64u\n",i,r);
	//		if(r <= i) { ++i;continue; }
	//		if(r > n) { ++i;continue; }
	//		i = r;
	//	}
	//	assert(ans <= n);
	//	printf("Case #%u: %I64u\n",iCases,ans);
	//}

	static const unsigned int maxn = 1000000;
	vector<unsigned int> ans(maxn+1,maxn+10);ans[1] = 1;
	deque<unsigned int> que;que.push_back(1);
	for(;!que.empty();que.pop_front())
	{
		unsigned int u = que.front();
		if(u + 1 <= maxn)
		{
			if(ans[u]+1 < ans[u+1])
			{
				assert(ans[u+1] == maxn+10);
				ans[u+1] = ans[u]+1;
				que.push_back(u+1);
			}
		}
		unsigned int r = (unsigned int)(reverse(u));
		if(r <= maxn)
		{
			if(ans[u]+1 < ans[r])
			{
				assert(ans[r] == maxn+10);
				ans[r] = ans[u]+1;
				que.push_back(r);
			}
		}

	}

	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned long long n = 0;scanf("%I64d",&n);
		printf("Case #%u: %I64u\n",iCases,(unsigned long long)(ans[n]));
	}
	return 0;
}