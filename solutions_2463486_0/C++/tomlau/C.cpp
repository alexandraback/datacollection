#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int t=1; t<=T; t++)	{
    int A, B;
	  cin >> A >> B;

    int result=0;
    if (A <= 1 && B >= 1) result ++;
    if (A <= 4 && B >= 4) result ++;
    if (A <= 9 && B >= 9) result ++;
    if (A <= 121 && B >= 121) result ++;
    if (A <= 484 && B >= 484) result ++;

    cout << "Case #" << t << ": " << result << endl;
	}
  
	return 0;
}
