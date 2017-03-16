#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

int main()
{
  std::ifstream in("in");
  int cases;
  in >> cases;

  for (int i=0;i<cases;++i)
    {
      int A,B;
      in >> A >> B;
      std::vector<double> p(A);
      for (int a=0;a<A;++a)
	{
	  in >> p[a];
	}

//      double k_ret = 1+B+1;
      double k_best=2+B;

      double prob_c = 1;
      for (int j=A-1;j>=0;--j)
	{
	  double k=j+1; //backspace+enter
//	  for (int jj=0;jj<A-j;++jj)
	    prob_c = prob_c * p[A-1-j];

	  k+=(B-A+j) + (1+B)*(1-prob_c);
					   //std::cout << j << " " << k << std::endl;
	  
	  
	  if (k<k_best)
	    k_best=k;
	}
      

      

      /*      std::vector<bool> on;
      on.resize(N);
      for (int k=0;k<K;++k)
	{
	  for (int j=0;j<N;++j)
	    {
	    on[j]=!on[j];
	    if (on[j])
	      break;
	    }
	  //	  for (int j=0;j<=N;++j)
	  //	    std::cout << on[j];
	  //	  std::cout << std::endl;
	}
      
      bool ison=true;
      for (int j=0;j<N;++j)
	if (!on[j])
	  {ison=false;break;}
      */

      std::cout << "Case #" << i+1 << ": ";
      std::cout << std::setprecision(12) << k_best;

      std::cout << std::endl;

    }
  return 0;
}
