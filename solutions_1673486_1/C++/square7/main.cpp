#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int totCase;
  cin >> totCase;
  for(int i = 0; i < totCase; ++i)
    {
      cout << "Case #" << (i+1) << ": ";
      int a, b;
      cin >> a >> b;
      // vector<double> p;
      vector<long double> possible;
      possible.push_back(1);
      for(int j = 0; j < a; ++j)
	{
	  long double temp;
	  cin >> temp;
	  //cerr << temp << endl;
	  //  p.push_back(temp);
	  possible.push_back(possible[j] * temp);
	}
      cerr << possible[a-1] << endl;
      long double entry = b+2;
      //double cont = 2 * b - a + 2 - (b+1) * possible[a-1];
      long double m = entry;
      for(int k = 0;  k <= a; ++k)
	{
	  long double poss = 2 * b - a + 2 + 2 * k - (b+1) * possible[a-k];
	  if(m > poss)
	    {m = poss;}
	}
      //cerr << endl;
      cout.precision(6);
      cout << fixed << m << endl;
    }
}
