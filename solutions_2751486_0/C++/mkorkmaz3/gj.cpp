#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

bool isCons(char c)
{
	if(c == 97 ||
		c == 101 ||
		c == 105 ||
		c == 111 ||
		c == 117 )
	{
		return true;
	}
	else
	{
		return false;
	}
		
}

int main()
{

	assert(freopen("A-small-attempt2.in", "r", stdin));
	assert(freopen("output.out", "w", stdout));

	int nCase;

	scanf("%d",&nCase);

	int n;
	char cName[105];
	int count;
	vector<int> indices;
	for(int i = 0 ; i < nCase ; i++)
	{
		scanf("%s",cName);
		scanf("%d",&n);

		string name(cName);

		count = 0;
		bool isInd = true;
		count = 0;
		for(int j = 0 ; j < name.size() - n + 1 ; j++)
		{
			isInd = true;
			if(j+n <= name.size())
			{
				for(int k = j ; k < j+n ; k++)
				{
					if(isCons(name[k]))
					{
						isInd = false;
					}
				}
			}
			if(isInd)
			{
				indices.push_back(j);
			}
		}

		for (int j = 0 ; j < indices.size() ; j++)
		{
			int firstHalf;
			if(j > 0)
			{
				firstHalf = indices[j] - indices[j -1 ];
			}
			else
			{
				 firstHalf = indices[j] + 1 ;
			}
			
			int secondHalf = name.size() - (indices[j] + n)   + 1 ;
			count+= firstHalf * secondHalf;
		}
		indices.clear();
		printf("Case #%d: %d\n",i+1,count);
	}
		

		

	
}