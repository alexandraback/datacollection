/* -*- Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil -*- */

#include <iostream>
#include <algorithm>

using namespace std;

int
main ()
{
  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase ++)
    {
      int N;
      cin >> N;

      int S;
      cin >> S;

      int p;
      cin >> p;

      int countNonSurprisingPossible = 0;
      int countSurprisingPossible = 0;

      int minNonSurprising = std::max (0, p + (p-1) + (p-1));
      int minSurprising = std::max (0, p + (p-2) + (p-2));
      
      for (int googler = 0; googler < N; googler++)
	{
	  int score;
	  cin >> score;

	  if (score >= p)
	    {
	      if (score >= minNonSurprising)
		countNonSurprisingPossible ++;
	      else if (score >= minSurprising)
		countSurprisingPossible ++;
	    }
	}

      cout << "Case #" << testCase << ": ";
      cout << countNonSurprisingPossible + std::min (countSurprisingPossible, S);
      cout << endl;
    }
  
  return 0;
}
