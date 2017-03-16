//
// Qualification round 2014  problem D
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

unsigned int score_dec( vector<double> v1, vector<double> v2)
{
     reverse(v1.begin(), v1.end());
     reverse(v2.begin(), v2.end());

     unsigned int s=0;
     unsigned int j=0;
     for (unsigned int i=0; i<v1.size(); i++)
     {
	  if (v1.at(i) < v2.at(j))
	  {
	  }
	  else
	  {
	       s++;
	       j++;
	  }
     }

     if (0)
     {
	  for (unsigned int i=0; i<v1.size(); i++)
	  {
	       cout << setw(8) << v1.at(i) << " ";
	       cout << setw(8) << v2.at(i) << endl;
	  }
     }

     return s;
}
unsigned int score_war(vector<double> v1,vector<double> v2 )
{
     unsigned int s=0;
     unsigned int i,j;

     j=0;
     for(i=0; i<v1.size(); i++)
     {
	  if (v1.at(i) > v2.at(j))
	  {
	       s++;
	  }
	  else
	  {
	       j++;
	  }
     }
     return s;
}

int main( int argc, char ** argv )
{
     cout << setprecision(8);

     unsigned int n;
     unsigned int i;

     cin >> n;

     for (i=1; i<=n; i++) {

	  unsigned int nb;
	  cin >> nb;

	  vector<double> n(nb);
	  vector<double> k(nb);
	  for (auto &x : n) cin >> x;
	  for (auto &x : k) cin >> x;

	  sort(n.begin(), n.end());
	  sort(k.begin(), k.end());
	  reverse(n.begin(), n.end());
	  reverse(k.begin(), k.end());

	  unsigned int s1 = score_dec(n, k);
	  unsigned int s2 = score_war(n, k);

	  cout << "Case #" << i << ": ";
	  cout << setw(7) << s1 << "  " << setw(7) << s2 << endl;
     }

     return 0;
}

