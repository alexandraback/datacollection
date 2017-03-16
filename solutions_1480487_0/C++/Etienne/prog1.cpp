#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <iomanip>

using namespace std;

void doCase();

int main()
{
  int cases;
  cin >> cases;
  cin.ignore();

  for(int c=0; c<cases; c++)
    {
      cout << "Case #" << c+1 << ": ";
      doCase();
    }
}

void doCase()
{
  int contestants;
  cin >> contestants;
  vector<int> scores;
  vector<bool> included;
  int sum=0;
  for(int i=0; i<contestants; i++)
    {
      int score;
      cin >> score;
      scores.push_back(score);
      included.push_back(true);
      sum += score;
    }
  bool done = false;
  int target = 0;
  int numincluded = contestants;
  while(!done)
    {
      done = true;
      int suminc = 0;
      for(int i=0; i<contestants; i++)
	if(included[i])
	  suminc += scores[i];
      target = suminc+sum;
      for(int i=0; i<contestants; i++)
	{
	  if(included[i])
	    {
	      if(target < numincluded*scores[i])
		{
		  included[i] = false;
		  done = false;
		  numincluded--;
		}
	    }
	}
    }

  for(int i=0; i<contestants; i++)
    {
      if(i != 0)
	cout << " ";
      if(included[i])
	{
	  double alpha = double(target)/double(numincluded)-scores[i];
	  alpha *= 100.0/double(sum);
	  cout << setprecision(10) << alpha;
	}
      else
	cout << "0.0";
    }
  cout << endl;
}
