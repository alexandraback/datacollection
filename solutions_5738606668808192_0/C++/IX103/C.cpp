
#include <iostream>
#include <cassert>
#include <gmpxx.h> //-lgmpxx -lgmp


using namespace std;

pair<bool,mpz_class> isprime(mpz_class num)
{
  //only support numbers >= 3
  mpz_class div_max;
  mpz_sqrt(div_max.get_mpz_t(), num.get_mpz_t());
  
  for (mpz_class div = 2; div <= div_max ; div++)
  {
    if (num % div == 0)
    {
      return pair<bool,mpz_class>(false,div);
    }
  }
  return pair<bool,mpz_class>(true,mpz_class(0));

}

void processCase(int c)
{
  unsigned int N, J;
  cin >> N >> J;
  
  unsigned int nJ = 0;
  mpz_class idx(0);

  cout << "Case #" << c << ":" << endl;
  vector<mpz_class> div;
  while (nJ < J)
  {
    div.clear();
  
    string idxstring = idx.get_str(2);
    string mystring = "1";
    while (mystring.length() + 1 + idxstring.length() < N)
      mystring += "0";
    mystring += idxstring;
    mystring += "1";
    assert(mystring.length() == N);
    
    bool prime = false;
    for (int base = 2; base <= 10; base++)
    {
      mpz_class num(mystring,base);
      pair<bool,mpz_class> result = isprime(num);
      if (result.first)
      {
        prime = true;
        break;
      }
      else
      {
        div.push_back(result.second);
      }
    }
    
    if (!prime)
    {
      cout << mystring;
      for (auto it = div.begin(); it != div.end(); it++)
        cout << " " << it->get_str(10);
      cout << endl;
      nJ += 1;
    }
    
    idx += 1;
  }
}


int main()
{
  int numcases;
  cin >> numcases;
  
  for (int c = 0; c < numcases; c++)
    processCase(c+1);
}

