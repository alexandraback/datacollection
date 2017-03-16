#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <assert.h>
#include <algorithm>

using std::vector;
using std::queue;
using std::string;

bool isvalid(const string& s)
{
	vector<size_t> occurrences(0x100,(size_t)(-1));
	for(size_t i = 0,len = s.size();i < len;++i)
	{
		char c = s[i];
		if(occurrences[c] == (size_t)(-1)) occurrences[c] = i;
		else if(occurrences[c] + 1 == i) occurrences[c] = i;
		else return false;
	}
	return true;
}

bool reduct_data(vector<string>& data)
{
	vector<size_t> occurrences(0x100,(size_t)(-1));					// 在第几个字符串的中间出现
	for(size_t i = 0;i < data.size();++i)
	{
		size_t len = data[i].size();
		if(1 == len) continue;
		string s = "";
		s.push_back(data[i][0]);
		s.push_back(data[i][len-1]);

		for(size_t k = 1;k + 1 < len;++k)
		{
			char c = data[i][k];
			if(c == data[i][0]) continue;
			if(c == data[i][len-1]) continue;
			if(occurrences[c] == (size_t)(-1)) occurrences[c] = i;
			else if(occurrences[c] != i) return false; 
		}
		data[i] = s;
	}
	for(size_t i = 0;i < data.size();++i)
	{
		size_t len = data[i].size();
		char c = data[i][0],ch = data[i][len-1];
		if(occurrences[c] != (size_t)(-1)) return false;
		if(occurrences[ch] != (size_t)(-1)) return false;
	}
	return true;
}

unsigned int slove_small(vector<string>& data)
{
	static const unsigned int module =  1000000007;

	for(size_t i = 0;i < data.size();++i)
	{
		if(!isvalid(data[i])) return 0;
	}

	if(!reduct_data(data)) return 0;

	size_t size = data.size();
	vector< vector<bool> > g(size,vector<bool>(size,false));
	for(size_t i = 0;i < size;++i)
	{
		size_t len = data[i].size();
		char c = data[i][len-1];
		for(size_t k = 0;k < size;++k)
		{
			if(data[k][0] == c) continue;
			g[i][k] = true;
		}
		g[i][i] = false;
	}

	vector<unsigned int> pos(size);
	for(unsigned int i = 0;i < size;++i) pos[i] = i;
	unsigned int ret = 0;
	do 
	{
		string s = "";
		for(size_t i = 0;i < size;++i)
		{
			s += data[pos[i]];
		}

		if(isvalid(s)) { ++ret;ret %= module; }
	} while (std::next_permutation(pos.begin(),pos.end()));
	return ret;
}

unsigned int slove_large(const vector<string>& data)
{
	static const unsigned int module =  1000000007;
	for(size_t i = 0;i < data.size();++i)
	{
		if(!isvalid(data[i])) return 0;
	}

	unsigned int dps[26] = { 0 };
	for(size_t i = 0; i < data[i].size();++i)
	{

	}
	return 0;
}

int main()
{
	static const unsigned int module =  1000000007;

	static const size_t buff_size = 0x100;
	char buff[buff_size] = { 0 };

	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0;scanf("%d",&n);
		vector<string> data(n);
		for(unsigned int i = 0;i < n;++i)
		{
			scanf("%s",buff);
			data[i] = buff;
		}

		unsigned int ans = slove_small(data);
		printf("Case #%d: %d\n",iCases,ans);
	}
	return 0;
}