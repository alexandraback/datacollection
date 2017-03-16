#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  const int MAX = 100000;
  ifstream myfile ("C-small-2-attempt0.in");
  ofstream answer ("C2.out");
  
  int cases, r, n, m, k, current, limit, multi;
  vector<int> array;
  vector<int> * rands;
  vector<string> randoms;
  string rs;
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
	  for(int a=0; a < n; ++a)
	  {
	    rands->push_back((rand()%(m-1) + 2));
	  }
	  rs = "";
	  for(int a=0; a < n; ++a)
	    rs+=(rands->at(a)+'0');
	  randoms.push_back(rs);
	  for(int b=0; b < k; ++b)
	  {
	    limit = rand()%(n+1);
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