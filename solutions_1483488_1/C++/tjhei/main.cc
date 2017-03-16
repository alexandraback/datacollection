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
      long A,B;
      in >> A >> B;

      long answer = 0;
      
      for (long n=A;n<B;++n)
	{
	  long i=1;
	  long n_digits=0;
	  long nn=n;
	  long biggest=1;
	  while (nn)
	    {
	      nn/=10;
	      n_digits++;
	      biggest*=10;
	    }
	  biggest/=10;

//	  std::cout << n << " " << n_digits << " " << biggest << std::endl;
	  

	  long m=n;
	  for (long i=1;i<n_digits;++i)
	    {
	      long rest = m%10;
	      m=m/10+rest*biggest;
	      if (m<n)
		continue;
	      if (m>B)
		continue;
	      if (m==n)
		break;

	      answer++;
	      
//	      std::cout << "m=" << m << std::endl;
	      
	    }
	  

	  
	  


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

      std::cout << "Case #" << i+1 << ": " << answer;
//      int off=pow(2,N)-1;

      std::cout << std::endl;

    }
  return 0;
}
