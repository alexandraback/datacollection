#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h> 
#include <limits.h>
#include <locale.h> 
#include <math.h> 
#include <setjmp.h>
#include <signal.h> 
#include <stdarg.h> 
#include <stddef.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>

void calculateInDegreeAndOutDegree(const std::vector<std::vector<int> >& g, std::vector<int>& s, std::vector<int>& t)
{
	std::vector<int> inDegree(g.size(), 0);
	std::vector<int> outDegree(g.size(), 0);
	for (unsigned int i=0; i<g.size(); ++i)
		for (unsigned int j=0; j<g[i].size(); ++j)
		{
			if (g[i][j]!=INT_MAX)
			{
				++outDegree[i];
				++inDegree[j];
			}
		}

	for (unsigned int i=0; i<g.size(); ++i)
	{
		if (inDegree[i]==0)
			s.push_back(i);
		else if (outDegree[i]==0)
			t.push_back(i);
	}
}

int numberOfPathsHelper(std::vector<int>& memo, const std::vector<std::vector<int> >& g, int curr, int t)
{
	if (curr==t)
		return memo[curr] = 1;

	if (memo[curr]!=-1)
		return memo[curr];

	int cnt = 0;
	for (int i=0; i<g.size(); i++)
	{
		if (g[curr][i]!=INT_MAX)
			cnt+=numberOfPathsHelper(memo, g, i, t);
	}

	return memo[curr] = cnt;
}

int numberOfPaths(const std::vector<std::vector<int> >& g, int s, int t)
{
	std::vector<int> memo(g.size(), -1);
	return numberOfPathsHelper(memo, g, s, t);
}


std::string diamondInheritanceHelper(const std::vector<std::vector<int> >& g)
{
	std::vector<int> s;
	std::vector<int> t;
	calculateInDegreeAndOutDegree(g, s, t);

	for (unsigned int i=0; i<s.size(); ++i)
		for (unsigned int j=0; j<t.size(); ++j)
		{
			if (numberOfPaths(g, s[i], t[j])>1)
				return "Yes";
		}

	return "No";
}


void diamondInheritance(const char* filename)
{
	std::ifstream fin;
	fin.open(filename);
	std::ofstream fout;
	std::string str = filename;
	str = str.substr(0, str.size()-3)+".out";
	fout.open(str.c_str());
	int T, N, M, S;
	fin>>T;

	for (int i=1; i<=T; ++i)
	{
		fin>>N;
		std::vector<std::vector<int> > g(N, std::vector<int>(N, INT_MAX));
		for (int j=1; j<=N; ++j)
		{
			fin>>M;
			for (int k=1; k<=M; ++k)
			{
				fin>>S;
				g[j-1][S-1] = 1;
			}
		}

		fout<<"Case #"<<i<<": "<<diamondInheritanceHelper(g)<<std::endl;
	}

	fin.close();
	fout.close();
}



int main()
{
	diamondInheritance("A-large.in");
	return 0;
}
