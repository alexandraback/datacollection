#include <iostream>
#include <vector>
#include <algorithm>

struct pair
{
	int one;
	int two;
};

struct myCompareOne {
  bool operator() (pair* i,pair* j)
  {
	  if (i->one == j->one)
		  return (i->two < j->two);
	  return (i->one < j->one);
  }
} compareOne;

struct myCompareTwo {
  bool operator() (pair* i,pair* j)
  {
	  if (i->two == j->two)
		  return (i->one < j->one);
	  return (i->two < j->two);
  }
} compareTwo;

int main(int argc, char* argv[])
{
	int numCases;
	std::cin >> numCases;
	for (int i=0; i<numCases; i++)
	{
		int levels;
		std::cin >> levels;
		std::vector<pair*> onerate;
		onerate.reserve(levels);
		std::vector<pair*> tworate;
		tworate.reserve(levels);
		for (int j=0; j<levels; j++)
		{
			pair* p = new pair();
			std::cin >> p->one >> p->two;
			onerate.push_back(p);
			tworate.push_back(p);
		}
		sort(onerate.begin(), onerate.end(), compareOne);
		sort(tworate.begin(), tworate.end(), compareTwo);
		int stars = 0;
		int plays = 0;
		bool possible = true;
		std::vector<pair*>::iterator two;
		std::vector<pair*>::iterator one = onerate.begin();
		for (two = tworate.begin(); two != tworate.end();)
		{
			if (!possible)
				break;
			if (stars >= (*two)->two)
			{
				plays++;
				if ((*two)->one == -1)
					stars += 1;
				else
				{
					(*two)->one = -1;
					stars += 2;
				}
				++two;
			}
			else
			{
				while (stars < (*two)->two && one != onerate.end())
				{
					if ((*one)->one == -1)
					{
						++one;
						continue;
					}
					if (stars >= (*one)->one)
					{
						plays++;
						stars += 1;
						(*one)->one = -1;
						++one;
					}
					else
					{
						possible = false;
						break;
					}
				}
				if (stars >= (*two)->two)
				{
					plays++;
					if ((*two)->one == -1)
						stars += 1;
					else
					{
						(*two)->one = -1;
						stars += 2;
					}
					++two;
					continue;
				}
				if (one == onerate.end())
				{
					possible = false;
					break;	
				}				
			}
		}
		if (possible)
			std::cout << "Case #" << (i+1) << ": " << plays << std::endl;
		else
			std::cout << "Case #" << (i+1) << ": " << "Too Bad" << std::endl;
	}
	return 0;
}

