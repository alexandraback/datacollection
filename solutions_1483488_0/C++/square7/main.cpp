#include <fstream>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

int numOfDigit(int num)
{
  int d = 0;
  while(num != 0)
    {
      num = num / 10;
      ++d;
    }
  return d;
}

int move(int num, int digit)
{
  return (num % 10) * pow(10, digit-1) + num / 10;
}

int cycledNum(int num, int min, int max)
{
  int digit = numOfDigit(num);
  set<int> find;
  find.insert(num);
  int totalNum = 0;
  //cout << num << " ";
  for(int i = 1; i < digit; ++i)
    {
      bool isZero = ((num%10) == 0 ? 1 : 0);
      num = move(num, digit);
      if(num >= min && num <= max && (isZero==0) && find.count(num) == 0)
	{
	  ++totalNum;
	  find.insert(num);
	  // cout << num << " ";
	}
    }
  return totalNum;
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
      int min, max;
      input >> min >> max;
      output << "Case #" << (i+1) << ": ";
      int totalNum = 0;
      for(int j = min; j <= max; ++j)
	{
	  totalNum += cycledNum(j, min, max);
	  //cout << endl;
	}
      output << totalNum / 2 << endl;
    }
}
