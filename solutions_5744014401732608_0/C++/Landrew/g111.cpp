#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <string>

#include <math.h>

using namespace std;

ofstream fout("OUT111.txt");
ifstream fin ("INP111.txt");

bool po2 (long long int x)
{
 while (((x % 2) == 0) && x > 1) 
   x /= 2;
 return (x == 1);
}

int main() {

  int TT;
  fin >> TT;

  for (int tt=0;tt<TT; tt++)
  {
    int b;
	long long m;
	fin >> b;
	fin >> m;
	int mm = m;

    if (m==1)
	{
       fout << "Case #" << tt+1 << ": " << "POSSIBLE" <<  endl;
	   for (int i=0; i<b-1; i++)
		   fout << 0;
	   fout << 1 << endl;
	   for (int j=1; j<b; j++)
	   {
          for (int i=0; i<b; i++)
			  fout << 0;
		  fout << endl;
	   }
	   continue;
	}

	string s = "";
	bool poTwo = po2(m);
	if (poTwo)
		m=m-1;

	while (m>0)
	{
      long long rem = m%2;
	  char c = '0' + rem;
	  s = s + c;
	  m = (m-rem)/2;
	}

	reverse(s.begin(), s.end());

    

    if ((s.size() + 2) > b)
	{
       fout << "Case #" << tt+1 << ": " << "IMPOSSIBLE" <<  endl;
	   continue;
	}

    int ma[52][52];
	for (int i=0; i<52; i++)
	{
      for (int j=0; j<52; j++)
		  ma[i][j] = 0;
	}

    int n = s.size();
	for (int i=0; i<n; i++)
	{
       if (s[i] == '1')
	   {
          ma[0][i+b-n-1] = 1;
	   }
	}

	for (int i=1; i<b-1; i++)
	{
      for (int j=i+1; j<b; j++)
		  ma[i][j] = 1;
	}

	if (poTwo)
		ma[0][b-1] = 1;

    fout << "Case #" << tt+1 << ": " << "POSSIBLE" <<  endl;
	for (int i=0; i<b; i++)
	{
       for (int j=0; j<b; j++)
	   {
		   fout << ma[i][j];
	   }
	   fout << endl;
	}
  }

   return 0;
}
