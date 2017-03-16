#include <fstream>
#include <iostream>

using namespace std;

bool isNormal(int sum, int max)
{
  int small = max > 0 ? max-1 : 0;
  return (sum >= max + 2 * small);
}

bool isSurprise(int sum, int max)
{
  int small;
  if(max > 1)
    {small = max - 2;}
  else
    {
      small = 0;
    }
  return (sum >= max + 2 * small);
}

int main(int argc, char* argv[])
{
  if(argc != 3)
    {
      cout << "Error" << endl;
      return -1;
    }
  ifstream input(argv[1]);
  ofstream output(argv[2]);
  int totalCase;
  input >> totalCase;
  for(int i = 0; i < totalCase; ++i)
    {
      int solution = 0;
      int number;
      int sur;
      int currSur = 0;
      int max;
      output << "Case #" << (i+1) << ": ";
      input >> number >> sur >> max;
      for(int j = 0; j < number; ++j)
	{
	  int sum;
	  input >> sum;
	  if(isNormal(sum, max))
	    {++solution;}
	  else
	    {
	      if(currSur < sur && isSurprise(sum, max))
		{++currSur, ++solution;}
	    }
	}
      output << solution << endl;
    }
}
