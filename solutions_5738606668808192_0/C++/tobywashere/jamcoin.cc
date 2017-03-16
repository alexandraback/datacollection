#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;

//true means prime
//false means composite
/*void sieve(unsigned long long n, bool primes[], unsigned long long divisors[])
{
    unsigned long long i, j;
    for (i=0;i<n;i++)
        primes[i]=1; // we initialize the sieve list to all 1's (True)
    primes[0]=0,primes[1]=0; // Set the first two numbers (0 and 1) to 0 (False)
    for (i=2;i<sqrt(n);i++) // loop through all the numbers up to the sqrt(n)
        for (j=i*i;j<n;j+=i) // mark off each factor of i by setting it to 0 (False)
	  {
            primes[j] = 0;
	    divisors[j] = i;
	  }
	  }*/

unsigned long long isPrime(unsigned long long n)
{
  if (n % 2 == 0)
    {
      return 2;
    }
  for (unsigned long long i = 3; i <= (unsigned long long)sqrt(n); i+=2)
    {
      if (n % i == 0)
	{
	  return i;
	}
    }
  return 0;
}

string convertTo2(unsigned long long num)
{
  string res = "";
  while (num > 0)
    {
      if (num % 2 == 1)
	{
	  res = '1' + res;
	}
      else
	{
	  res = '0' + res;
	}
      num /= 2;
    }
  return res;
}

unsigned long long baseConverter(string s, int base)
{
  unsigned long long pow = 1;
  unsigned long long sum = 0;
  for (int i = s.size()-1; i >= 0; i--)
    {
      if (s[i] == '1')
	{
	  sum += pow;
	}
      pow *= base;
    }
  return sum;
}

int main()
{
  int counter = 0;
  cout << "Case #1:" << endl;
  for (unsigned long long i = (1 << 15) + 1; i < (1 << 16); i += 2)
    {
      string rep = convertTo2(i);
      //cout << "rep: " << rep << endl;
      bool prime = false;
      vector<unsigned long long> this_divisors;
      for (int base = 2; base <= 10; base++)
	{
	  unsigned long long converted = baseConverter(rep, base);
	  unsigned long long res = isPrime(converted);
	  if (res == 0)
	    {
	      prime = true;
	      break;
	    }
	  this_divisors.push_back(res);
	}
      if (prime)
	{
	  continue;
	}
      cout << rep;
      assert(this_divisors.size() == 9);
      for (int i = 0; i < 9; i++)
	{
	  cout << " " << this_divisors[i];
	}
      cout << endl;
      /*for (int i = 2; i <= 10; i++)
	{
	  unsigned long long converted = baseConverter(rep, i);
	  cout << "Base " << i << ": " << converted << endl;
	  }*/
      counter++;
      if (counter == 50)
	{
	  break;
	}
    }
  //delete [] v;

  /*for (int i = 0; i < 50; i++)
    {
      unsigned long long res = isPrime(i);
      if (res == 0)
	{
	  cout << i << " is prime" << endl;
	}
      else
	{
	  cout << i << " is composite " << res << endl;
	}
	}*/
}
