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


int main()
{
	std::ifstream ifile("infile");
	std::ofstream ofile("outfile");


	int T = 0;
	ifile >> T;

	for (int icase = 1; icase <= T; ++icase) {
        int N = 0;
        ifile >> N;

        int p1 = 0, p2 = 0;
        long long m1 = 0, m2 = 0;

        if (N == 2) {
           int h = 0;
           ifile >> p1 >> h >> m1 >> p2 >> h >> m2;
           if (m1 > m2) {
              std::swap(p1, p2);
              std::swap(m1, m2);
           }
        }
        else {
           int h = 0;
           ifile >> p1 >> h >> m1;
           p2 = p1;
           m2 = m1 + 1;

        }

        int ans = 0;
        if (m1 != m2) {
           long long t1 = (360 - p1) * m1;
           long long t2 = (360 - p2) * m2;
           if (t2 > t1) {

              long long d = 360 - p1 + p2;
              if (d * m1  <= (m2 - m1) * (360 -p2)) {
                 ans = 1;
              }
           }
        }

		ofile << "Case #" << icase << ": " << ans << std::endl;
	}
}
