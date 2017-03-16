#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;
vector<long long int> v;
bool is_palindrome(unsigned  long long orig)
{
  unsigned long long reversed = 0, n = orig;

  while (n > 0)
  {
    reversed = reversed * 10 + n % 10;
    n /= 10;
  }

  return orig == reversed;
}

int T;
long long int A,B;
int a;

int main()
{
	fstream out;
	fstream in;
	in.open("input.in",ios::in);
	out.open("output.txt",ios::out);
	long long int maxi = 200010003;
	long long int u;
	for(long long int i = 1; i < 200010002; ++i )
	{
		u = i*i;
		if(is_palindrome(u) && is_palindrome(i))
							v.push_back(u);
	}
	in >> T;
	for(int i = 0; i < T; ++i)
	{
		in >> A >> B;
		a = upper_bound(v.begin(), v.end(), B) - lower_bound(v.begin(), v.end(), A);
		out << "Case #" << i+1 << ": " << a << endl;
	}
		
}
