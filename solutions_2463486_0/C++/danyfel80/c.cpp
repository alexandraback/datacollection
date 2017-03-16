#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <climits>
#include <cstring>
#include <string>
#include <cmath>
#include <iterator>
#include <cstdio>
#include <sstream>

using namespace std;
int squarePal[1001];

int main()
{
  squarePal[0] = 0;
  squarePal[1] = 1;
  for (int i = 2; i < 1001; i++)
  {
    squarePal[i] = squarePal[i-1];
    int num = sqrt(i);

    if(num*num == i)
    {
      string Result;          // string which will contain the result
      ostringstream convert;   // stream used for the conversion
      convert << i;      // insert the textual representation of 'Number' in the characters in the stream
      Result = convert.str();
      bool palin = true;
      int length = Result.size();
      int lengthm = length / 2;
      for(int j = 0; palin && j < lengthm; j++)
      {
        if(Result[j] != Result[length-1-j])
          palin = false;
      }

      string Result1;          // string which will contain the result
      ostringstream convert1;   // stream used for the conversion
      convert1 << num;      // insert the textual representation of 'Number' in the characters in the stream
      Result1 = convert1.str();
      int length1 = Result1.size();
      int lengthm1 = length1 / 2;
      for(int j = 0; palin && j < lengthm1; j++)
      {
        if(Result1[j] != Result1[length1-1-j])
          palin = false;
      }

      if(palin)
      {
        squarePal[i]++;
        //cout << i << endl;
      }
    }
  }

  int t, a, b, caseno = 1;
  cin >> t;
  while(t--)
  {
    cin >> a >> b;
    cout << "Case #"<< caseno++ << ": " << squarePal[b] - squarePal[a-1] << endl;
  }
  return 0;
}
