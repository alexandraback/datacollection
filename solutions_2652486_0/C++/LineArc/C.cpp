#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
  const int MAX = 100000;
  ifstream myfile ("C-small-1-attempt0.in");
  ofstream answer ("C.out");
  
  int cases, r, n, m, k, current, limit, multi;
  vector<int> array;
  vector<int> * rands;
  vector<int> randoms;
  myfile >> cases;
  
  for(int c=0; c < cases; ++c)
  {
    myfile >> r >> n >> m >> k;
    answer << "Case #" << c+1 << ": " << endl;
	for(int i=0; i < MAX; ++i)
	    array.push_back(1);
	for(int i=0; i < MAX; ++i)
	{
	  rands = new vector<int>();
	  for(int a=0; a < 3; ++a)
	  {
	    rands->push_back((rand()%4 + 2));
	  }
	  randoms.push_back(rands->at(0)*100+rands->at(1)*10+rands->at(2));
	  for(int b=0; b < k; ++b)
	  {
	    limit = rand()%4;
	    for(int c=0; c < limit; ++c)
	      array[i]*=rands->at(c);
	  }
    }
	for(int a=0; a < r; ++a)
	{
	  multi = 1;
	  for(int b = 0; b < k; ++b)
	  {
	    myfile >> current;
		multi*=current;
	  }
	  for(int i=0; i < MAX; ++i)
	    if(multi == array[i])
		{
		  answer << randoms[i] << endl;
		  break;
		}
	}

  }
  
  return 0;
}