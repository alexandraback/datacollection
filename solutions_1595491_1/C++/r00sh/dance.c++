#include <iostream>
#include <fstream>

using namespace std;

/*
5
16 655
15 555
14 554
13 544
--
12 543
11 533
--
10 ng
9 ng
*/

int main(void)
{
  ifstream fin;
  ofstream fout;

  fin.open("dance4.in");
  fout.open("dance4.out");
  
  int t, n, s, p, temp, count;
  fin >> t;

  for (int i = 0; i < t; i++)
    {
      fout << "Case #" << (i + 1) << ": ";
      fin >> n >> s >> p;
      count = 0;
      for (int j = 0; j < n; j++)
	{
	  fin >> temp;
	  if (temp + 2 >= p * 3)
	    count++;
	  else if (s > 0 && temp >= p)
	    {
	      if (temp % 3 == 0 && temp + 3 >= p * 3)
		{
		  s--;
		  count++;
		}
	      else if (temp % 3 == 2 && temp + 4 >= p * 3)
		{
		  s--;
		  count++;
		}
	    }
	}
      fout << count << endl;
    }

  fin.close();
  fout.close();

  return 0;
}
