#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <assert.h>     /* assert */
#include <limits>

using namespace std;


template <typename T>
T read()
{
  std::string line;
  getline(std::cin, line);
  std::istringstream iss(line);
  T i;
  iss >> i;
  return i;
}

template <typename T>
vector<T> readv()
{
  std::string line;
  getline(std::cin, line);
  std::istringstream iss(line);
  T tmp;
  vector<T> v;
  while (iss >> tmp)
  {
    v.push_back(tmp);
  }
  return v;
}

template <typename T>
void printv(const vector<T>& v)
{
  for (auto i : v)
    cout << i << " ";
  cout << endl;
}


void solve(unsigned long a, unsigned long b, unsigned long k)
{
  unsigned long count = 0;
  for ( unsigned long u = 0; u < a; u++)
    for ( unsigned long w = 0; w < b; w++)
    {
      unsigned long r = u & w;
      if ( r < k)
      {
	//cout << r << " " << k << endl;
	count++;
      }
    }
    cout << count << endl;
}


void proc_case()
{
 int a, b, k; 
 scanf("%d %d %d\n", &a, &b, &k);
 //cout << a << " " << b << " " << k << endl;
 solve(a , b , k);
}


int main()
{
  int t = read<int>();
  for (int i=0; i < t; i++)
  {
    cout << "Case #" << i+1 << ": " ;
    proc_case();
  }
}