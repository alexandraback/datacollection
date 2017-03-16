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

string slove_naive(const string& s)
{
	set<string> table;table.insert("");
	for(size_t i = 0;i < s.size();++i)
	{
		set<string> t = table;table.clear();
		for(set<string>::const_iterator it = t.begin();it != t.end();++it)
		{
			string v1 = *it,v2;
			v1.push_back(s[i]);
			v2.push_back(s[i]);v2 += *it;
			table.insert(v1);table.insert(v2);
		}
	}
	string ret = "";
	for(set<string>::const_iterator it = table.begin();it != table.end();++it)
	{
		if(*it > ret) ret = *it;
	}
	return ret;
}

string slove_greedy(const string& s)
{
	string ret;ret.push_back(s[0]);
	for(size_t i = 1;i < s.size();++i)
	{
		if(s[i] > ret[0])
		{
			string temp;temp.push_back(s[i]);
			ret = temp + ret;
		}
		else if(s[i] < ret[0])
		{
			ret.push_back(s[i]);
		}
		else
		{
			string temp;temp.push_back(s[i]);
			ret = temp + ret;
		}
	}
	return ret;
}

#include <stdlib.h>

int main()
{
	//for(unsigned int iCases = 1;iCases <= 1000;++iCases)
	//{
	//	unsigned int len = rand()%15 + 1;
	//	string s;
	//	for(unsigned int i = 0;i < len;++i) s.push_back(rand()%26+'A');
	//	string ans = slove_naive(s);
	//	string ret = slove_greedy(s);
	//	if(ans != ret)
	//	{
	//		printf("%s %s %s\n",s.c_str(),ret.c_str(),ans.c_str());
	//	}
	//	assert(ans == ret);
	//}
	//return 0;

	freopen("F:\\GCJ2016\\R1A1\\A-small-attempt0.in","r",stdin);
	freopen("F:\\GCJ2016\\R1A1\\A-small-attempt0.out","w+",stdout);
	static const size_t buff_size = 1200;
	char buff[buff_size] = { 0 };
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		scanf("%s",buff);
		printf("Case #%u: %s\n",iCases,slove_greedy(buff).c_str());
	}
	return 0;
}