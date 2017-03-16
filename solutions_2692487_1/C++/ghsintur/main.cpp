
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <limits>
#include <iomanip>

using namespace std;
ifstream fin("b.in");
ofstream fout("b.out");



typedef struct __mot 
{
	unsigned long long val;
	unsigned int index;
}mot;

mot arr[101];
unsigned long long best[101];

bool func(mot b, mot a)
{
	if (a.val > b.val)
	{
		return true;
	}
	else if (b.val > a.val)
	{
		return false;
	}
	else
	{
		return(a.index > b.index);
	}
}

unsigned long long solve(unsigned long long a, unsigned int n)
{
	unsigned long long res;
	unsigned int i;
	unsigned int j;
	unsigned int counter = 0;
	unsigned int bsetIndex = 0;
	vector<mot> v(arr, arr+n);
	vector<mot>::iterator it;

	sort(v.begin(),v.end(), func);
	for (i=0,it=v.begin();it!=v.end();it++,i++)
	{
		if (it->val >= a)
		{
			best[bsetIndex] = counter+n-i;
			bsetIndex++;
			for (j=0;j<n;j++)
			{
				if (it->val >= a)
				{
					a= 2*a-1;
					counter++;
				}
			}
			if (it->val > a)
			{
				break;
			}

		}
			a+=it->val;
	}

	res = counter;
	for (j=0;j<bsetIndex;j++)
	{
		if (res > best[j])
		{
			res = best[j];
		}
	}

	return res;
}

void main2(unsigned int testNum)
{
	unsigned int		i;
	unsigned int		j;
	unsigned long long		a;
	unsigned int		n;
	unsigned long long		res;
   
	fin>>a>>n;
	for (i=0;i<n;i++)
	{
		fin>>arr[i].val;
		arr[i].index = i;
	}
	res = solve(a,n);

	fout<<"Case #"<<testNum<<": "<<res<<endl;
}

int main(void)
{
	unsigned int numOfTests;
	unsigned int i;

	fin>>numOfTests;
	for(i=0;i<numOfTests;i++)
	{
		main2(i+1);
	}
	return 0;
}
