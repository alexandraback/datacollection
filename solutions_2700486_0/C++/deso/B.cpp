#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

//ifstream fin (".in");
ifstream fin ("B-small.in");
//ifstream fin ("B-large.in");
ofstream fout (".out");

vector<int> pyr;
double one = 1.0, zero = 0.0;

void solve() {
   int n, x, y;
   fin >> n >> x >> y;
   x = abs(x);
   y = abs(y);
   int lat = 0;
   while( n >= pyr[lat] ) {
      n -= pyr[lat];
      lat++;
   }
   lat++;

   if( x+y<2*(lat-1) )     fout << one << endl;
   else if(x+y>2*(lat-1) ) fout << zero << endl;
   else if( x==0 || n==0 )         fout << zero << endl;
   else {
      // x+y == 2*(lat-1)
      lat = 2*(lat-1);

      if( n>lat ) {
         int s = n - lat;
         n -= 2*s;
         lat -= s;
      }
      x = lat - abs(x) + 1;
      int pos = (1 << n);
      int good_pos = 0;

      for(int i=0; i<pos; i++) {
         int ones = 0;
         int xi = i;
         while(xi) {
            if( xi%2 ) ones++;
            xi /= 2;
         }
         
         if( ones>=x ) good_pos++;
      }
      fout << double(good_pos) / double(pos) << endl;
   }
}

int main() {
   pyr.push_back(1);
   int x = 1;
   for(int i=2; x<=1000000; i++) {
      pyr.push_back(4 * i - 3 );
      x += 4 * i - 3;
   }
   int N, N2 = 1;
	fin >> N;
   fout << fixed << setprecision(6);
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}