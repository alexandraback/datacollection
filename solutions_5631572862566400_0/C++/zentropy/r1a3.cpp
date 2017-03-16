#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <assert.h>

using std::vector;
using std::map;
using std::string;
using std::set;

#include <stdlib.h>

bool isCorrect(const vector<unsigned int>& bff,const vector<unsigned int>& data)
{			
	for(unsigned int i = 0;i < data.size();++i)
	{
		unsigned int u = data[i];
		unsigned int prev = (i+data.size()-1)%data.size();
		unsigned int next = (i+1)%data.size();
		if(data[prev] != bff[u] && data[next] != bff[u]) return false;
	}
	return true;
}

unsigned int slove_small(const vector<unsigned int>& bff)
{
	unsigned int ret = 1,size = bff.size();
	for(unsigned int imask = (1<<size)-1;imask > 1;--imask)
	{
		vector<unsigned int> data;data.reserve(size);
		for(unsigned int ibit = 0;ibit < size;++ibit)
		{
			if(0 == (imask&(1<<ibit))) continue;
			data.push_back(ibit);
		}
		if(data.size() <= ret) continue;
		std::sort(data.begin(),data.end());
		bool correct = false;
		do
		{
			if(isCorrect(bff,data)) correct = true;
			if(correct) break;
		}while(std::next_permutation(data.begin(),data.end()));
		if(correct) ret = data.size();
	}
	return ret;
}


int main()
{
	freopen("F:\\GCJ2016\\R1A3\\C-small-attempt0.in","r",stdin);
	freopen("F:\\GCJ2016\\R1A3\\C-small-attempt0.out","w+",stdout);
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0,v = 0;scanf("%d",&n);
		vector<unsigned int> bff(n,0);
		for(unsigned int i = 0;i < n;++i)
		{
			scanf("%d",&bff[i]);--bff[i];
		}
		unsigned int ans = slove_small(bff);
		printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}