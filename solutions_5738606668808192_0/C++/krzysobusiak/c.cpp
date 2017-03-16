#include <iostream>
#include <bitset>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;

vector<int> primes = {      
      2,      3,      5,      7,     11,     13,     17,     19,     23,     29, 
     31,     37,     41,     43,     47,     53,     59,     61,     67,     71, 
     73,     79,     83,     89,     97,    101,    103,    107,    109,    113, 
    127,    131,    137,    139,    149,    151,    157,    163,    167,    173, 
    179,    181,    191,    193,    197,    199,    211,    223,    227,    229, 
    233,    239,    241,    251,    257,    263,    269,    271,    277,    281, 
    283,    293,    307,    311,    313,    317,    331,    337,    347,    349, 
    353,    359,    367,    373,    379,    383,    389,    397,    401,    409, 
    419,    421,    431,    433,    439,    443,    449,    457,    461,    463, 
    467,    479,    487,    491,    499,    503,    509,    521,    523,    541 
};
                                                 
int get_divisor(ull num)
{
  for (int p: primes)
  {
    if ((num % p) == 0)
      return p;
  }
  return 0;
}

vector<int> get_divisors(string s)
{
  vector<int> divs;
  
  for (int base = 2; base <= 10; base++)
  {
    ull num = strtoull(s.c_str(), NULL, base);
    int div = get_divisor(num);
    if (!div)
      return vector<int>();
//    divs.push_back(base);
//    divs.push_back(num);
    divs.push_back(div);
  }
  
  return divs;
}

int main()
{
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    int n, j;
    cin >> n >> j;

    cout << "Case #" << i << ":" << endl;
    
    unsigned bin = (1 << (n - 1)) + 1;
    while (j > 0)
    {
      string s = bitset<16>(bin).to_string();
      vector<int> divs = get_divisors(s);
      if (!divs.empty())
      {
        cout << s;
        for (int d: divs)
          cout << " " << d;
        cout << endl;
        j--;
      }
      bin += 2;
    }
  }
  
  return 0;
}
