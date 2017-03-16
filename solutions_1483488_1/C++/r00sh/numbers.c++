#include <iostream>
#include <fstream>

#define BIG 2000001

using namespace std;

int memo[BIG];

int main(void)
{
  ifstream fin;
  ofstream fout;

  fin.open("numbers2.in");
  fout.open("numbers2.out");

  int a, b, n, tens, t, r, temp, count, s;

  fin >> n;

  for (int i = 0; i < n; i++)
    {
      fout << "Case #" << (i + 1) << ": "; 
      count = 0;
      fin >> a >> b;
      tens = 1;
      while (tens * 10 <= b)
	tens *= 10;
      for (int j = b; j >= a; j--)
	memo[j] = 0;      
      for (int j = b; j >= a; j--)
	{
	  s = 1;
	  memo[j] = 1;
	  if (tens > j)
	    tens /= 10;
	  t = tens;
	  while(t > 1)
	    {
	      temp = (j % t) * (tens * 10 / t) + j / t;
	      if (temp >= a && temp <= b && !memo[temp])
		{
		  memo[temp] = 1;
		  s++;
		}
	      t /= 10;
	    }
	  count += ((s * (s - 1)) / 2);
	  
	}
      fout << count << endl;
    }
  

  fin.close();
  fout.close();

  return 0;
}
