#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main()
{
  std::ifstream in("in");
  int cases;
  in >> cases;

  for (int i=0;i<cases;++i)
    {
      long N,S,p;
      in >> N >> S >> p;

      long poss_surp = 0;
      long arein = 0;
      for (long j=0;j<N;++j)
	{
	  long v;
	  in >> v;
	  if (v<p)
	    continue;
	  v-=p;
	  if ( v>=(p-1)+(p-1))
	    {
	      arein++;
	      continue;
	    }

	  if (v>=(p-2)+(p-2) && S>0)
	    {
	      --S;
	      arein++;
	    }
	}
      

      

      std::cout << "Case #" << i+1 << ": ";
      std::cout << arein;

      std::cout << std::endl;

    }
  return 0;
}
