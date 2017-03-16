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

// circle
unsigned int slove(const vector<unsigned int>& bff)
{
	size_t size = bff.size();
	vector<bool> bpair(size,false);
	for(size_t i = 0;i < size;++i)
	{
		if(bff[bff[i]] == i) { bpair[i] = true;bpair[bff[i]] = true; }
	}

	unsigned int ret = 1;
	vector<size_t> maxchain(size,0);
	for(size_t i = 0;i < size;++i)
	{
		bool correct = true;
		vector<bool> used(size,false);
		unsigned int v = i;
		for(;!bpair[v];v = bff[v])
		{
			if(used[v])
			{
				if(v == i) correct = true;
				else correct = false;
				break;
			}
			used[v] = true;
		}
		if(!correct) continue;
		size_t count = 0;
		for(size_t i = 0;i < size;++i) count += used[i];
		if(count > ret) ret = count;
		if(!bpair[v]) continue;
		if(count > maxchain[v]) maxchain[v] = count;
	}
	vector<unsigned int> chainsize;
	unsigned int total = 0,singlemax = 0,singlesec = 0,pairmax = 0;
	unsigned int temp = 0;
	for(size_t i = 0;i < size;++i)
	{
		if(!bpair[i]) continue;
		size_t u = bff[i];
		if(u < i) continue;
		unsigned int len = maxchain[i] + maxchain[u] + 2;
		temp += len;
		
		if(0 == maxchain[i] && 0 == maxchain[u]) total += 2;
		else if(0 == maxchain[i] || 0 == maxchain[u])
		{
			if(len > singlemax) { singlesec = singlemax;singlemax = len; }
			else if(len > singlesec) { singlesec = len; }
		}
		else if(len > pairmax) pairmax = len;
	}
	//if(singlemax + singlesec > ret) ret = singlemax + singlesec;
	//if(total + pairmax > ret) ret = total + pairmax;
	//if(total + singlemax > ret) ret = total + singlemax;
	if(temp > ret) ret = temp;
	return ret;
}

int main()
{
	freopen("F:\\GCJ2016\\R1A3\\C-large.in","r",stdin);
	freopen("F:\\GCJ2016\\R1A3\\C-large.ans","w+",stdout);
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0,v = 0;scanf("%d",&n);
		vector<unsigned int> bff(n,0);
		for(unsigned int i = 0;i < n;++i)
		{
			scanf("%d",&bff[i]);--bff[i];
		}
		unsigned int ans = slove(bff);
		printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}