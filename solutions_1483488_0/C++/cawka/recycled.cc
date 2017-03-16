/* -*- Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil -*- */

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int pow10 [] = {1,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000};

int
main ()
{
  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase ++)
    {
      int A, B;
      cin >> A >> B;

      int num_digits = 0;
      int tmp = A;
      while (tmp > 0)
	{
	  num_digits ++;
	  tmp /= 10;
	}
      // cout << num_digits << endl;

      int count = 0;
      
      for (int n = A; n <= B; n++) // just a linear search. should be enough for small and large data sets ~ O(n)
	{
	  // trying to find number of combinations for m

	  set<int> found;
	  
	  for (int group = 1; group <= num_digits; group++)
	    {
	      int grp = n % pow10[group];
	      int left = n / pow10[group];

	      // for (int pos = num_digits; pos > group; pos--)
	      int pos = num_digits;
		{
		  // cout << "left: " << left << ", grp: " << grp << ", pos: " << pos << ", x: " << (left / pow10[pos-group]) << ", " << (left % pow10[pos-group]) << endl;
		  int m =  
		    (left / pow10[pos-group]) * pow10[ pos ] + // like  (left & 1000000) but with decimal

		    grp * pow10[pos-group] +
		    
		    (left % pow10[pos-group]);
		  ;

		  if (n != m && n < m && A <= m && m <= B && found.find (m)==found.end ())
		    {
		      count ++;
		      found.insert (m);

		      // cout << "count: " << count << ", n: " << n << ", m: " << m << endl;
		    }
		}
	      
	    }
	}
      cout << "Case #" << testCase << ": " << count << endl;
    }

  return 0;
}
