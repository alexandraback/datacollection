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


std::vector<double> safetyInNumbersHelper(const std::vector<int>& v)
{
	std::vector<double> ret;
	int sum = std::accumulate(v.begin(), v.end(), 0);
	double minScore = (double)(sum*2)/(double)v.size();
	for (unsigned int i=0; i<v.size(); ++i)
	{
		double tmp = (double)(100*(minScore-v[i]))/(double)sum;
		if (tmp<=0)
			ret.push_back(0);
		else
			ret.push_back(tmp);
	}

	return ret;
}

void safetyInNumbers(const char* filename)
{
	std::ifstream fin;
	fin.open(filename);
	std::ofstream fout;
	std::string str = filename;
	str = str.substr(0, str.size()-3)+".out";
	fout.open(str.c_str());
	int T, N, S;
	fin>>T;

	for (int i=1; i<=T; ++i)
	{
		fin>>N;
		std::vector<int> v;
		for (int j=1; j<=N; ++j)
		{
			fin>>S;
			v.push_back(S);
		}

		std::vector<double> ret = safetyInNumbersHelper(v);

		fout<<"Case #"<<i<<": ";
		for (unsigned int k=0; k<ret.size(); ++k)
			fout<<ret[k]<<" ";
		fout<<std::endl;
	}

	fin.close();
	fout.close();
}



int main()
{
	safetyInNumbers("A-small-attempt1.in");
	return 0;
}
