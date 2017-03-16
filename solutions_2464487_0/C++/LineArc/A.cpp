#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream myfile ("A-small-attempt0.in");
  ofstream answer ("A.out");
  
  int cases, r, t, bRings, counter, inner, outer;
  int pi = 3.14159;
  myfile >> cases;

  
  for(int c=0; c < cases; ++c)
  {
    myfile >> r >> t;
	bRings = 0;
	counter = 0;
	while(t > 0)
	{
	  inner = r+counter;
	  outer = r+counter+1;
	  t-=outer*outer-inner*inner;
	  ++bRings;
	  if(t < 0)
	    --bRings;
	  counter+=2;
	}
	answer << "Case #" << c+1 << ": " << bRings << endl;
  }
  
  return 0;
}