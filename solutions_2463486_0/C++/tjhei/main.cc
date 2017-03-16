#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

char dig[20];

bool is_pal(long n)
{
  int l;
  for (l=0;l<20;++l)
    {
      dig[l]=n%10;
      n/=10;
      if (n==0)
	break;
    }
  ++l;
  for (int i=0;i<l/2;++i)
    {
    if (dig[i]!=dig[l-i-1])
      return false;
    }
  
  return true;
  
  
}


int main()
{
  std::ifstream in("in");
  int cases;
  std::string casess;
  getline(in,casess);
  sscanf(casess.c_str(),"%d",&cases);

  //  std::cout << is_pal(121) << is_pal(1231) << is_pal(6) << is_pal(1234554321);
  
  
  
  for (int i=0;i<cases;++i)
    {
      long A,B;
      in >> A >> B;

      long count=0;

      for (long n=1;n<=B;++n)
	{
	  if (n*n<A)
	    continue;
	  if (n*n>B)
	    break;
	  if (!is_pal(n))
	    continue;
	  if (is_pal(n*n))
	    {
	      count++;
	      //std::cout << n << " " << n*n << std::endl;
	      
	    }
	  
	  

	}
      
      
      
      std::cout << "Case #" << i+1 << ": ";
      std::cout << count;
      
      // int off=pow(2,N)-1;

      // if (K>0 && K%(off+1)==off)
      // 	std::cout << "ON";
      // else
      // 	std::cout << "OFF";

      std::cout << std::endl;

    }
  return 0;
}
