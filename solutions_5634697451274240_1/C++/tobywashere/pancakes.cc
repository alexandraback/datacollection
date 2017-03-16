#include <iostream>
#include <string>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int c = 0; c < T; c++)
    {
      string S;
      cin >> S;
      int count = 0;
      for (int i = 1; i < S.size(); i++)
	{
	  if (S[i] != S[i-1])
	    {
	      count++;
	    }
	}
      if (S[S.size()-1] == '-')
	{
	  count++;
	}
      cout << "Case #" << (c+1) << ": " << count << endl;
    }
}
