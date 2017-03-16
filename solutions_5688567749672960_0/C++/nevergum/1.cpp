#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <deque>

using namespace std;

template<class T>
void unset(T* p, int n)
{
    for (int i = 0; i < n; ++i) {
        *p = 0;
        ++p;
    }
}

int a[1000001];

int
reverse(int n)
{
   int m = 0;
   while (n > 0) {
      int d = n % 10;
      m = m * 10 + d;
      n /= 10;
   }

   return m;
}

int
work(int n)
{
   if (n < 20) {
      a[n] = n;
      return n;
   }

   if (a[n] != 0)
      return a[n];

   int alt = 0;
   if (n % 10 != 0) {
      int m = reverse(n);
      if (m < n) {
         a[m] = work(m);
         alt = a[m];
      }
   }

   int m2 = n - 1;
   if (a[m2] == 0) {
      a[m2] = work(m2);
   }

   a[n] = alt == 0? a[m2] + 1: std::min(alt, a[m2]) + 1;
   return a[n];
}

int main()
{
	std::ifstream ifile("infile");
	std::ofstream ofile("outfile");


	int T = 0;
	ifile >> T;

	for (int icase = 1; icase <= T; ++icase) {

        unset(a, 1000001);
        int n = 0;
        ifile >> n;

        int ans = work(n);

		ofile << "Case #" << icase << ": " << ans << std::endl;
	}
}
