#include <stdio.h>
#include <vector>
#include <algorithm>
using std::vector;

bool is_palindrome(unsigned long long v)
{
	static const unsigned int count = 20;
	unsigned int digits[count] = { 0 };
	unsigned int p = 0;
	for(;v != 0 && p < count;v /= 10,++p)
	{
		digits[p] = (unsigned int)(v%10);
	}
	if(0 != p) --p;						// v = 0时才有可能p = 0
	for(unsigned int i = 0;i < p;++i,--p)
	{
		if(digits[i] != digits[p]) return false;
	}
	return true;
}

void fair_square(unsigned int first,unsigned int last,vector<unsigned long long>& out)
{
	out.clear();out.reserve(100);
	for(unsigned int i = first;i <= last;++i)
	{
		if(!is_palindrome(i)) continue;
		unsigned long long x = i;x *= i;
		if(!is_palindrome(x)) continue;
		out.push_back(x);
		//printf("%u %I64u\n",i,x);
	}
}

int main()
{
	typedef unsigned long long uint64_t;
#if 1
	static const unsigned int maxv = 10000000;
	vector<uint64_t> data;
	fair_square(1,maxv,data);
	//printf("size = %u\n",data.size());
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		uint64_t a = 0,b = 0;scanf("%I64d%I64d",&a,&b);
		vector<uint64_t>::const_iterator itFirst = std::lower_bound(data.begin(),data.end(),a);
		vector<uint64_t>::const_iterator itLast = std::upper_bound(data.begin(),data.end(),b);

		unsigned int ans = 0;
		if(itFirst == data.end()) ans = 0;
		else ans = (unsigned int)(itLast - itFirst);
		printf("Case #%u: %I64u\n",iCases,ans);
	}

#else
	static const size_t buff_size = 1000;
	char abuff[buff_size] = { 0 },bbuff[buff_size] = { 0 };
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		scanf("%s%s",abuff,bbuff);
		unsigned long long bret = get_count(bbuff);
		unsigned long long aret = get_count();
		unsigned long long ans = bret - aret;
		printf("Case #%u: %I64u\n",iCases,ans);
	}
#endif
	return 0;
}

