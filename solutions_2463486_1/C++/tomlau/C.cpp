#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool pal(_int64 x)
{
  char ch[128];
  int index=0;
  while (x) {
    ch[index++] = x%10;
    x /= 10;
  }
  for (int i=0; i<index/2; i++)
    if (ch[i] != ch[index-i-1]) return false;
  return true;
}


int main()
{
  int T;
  cin >> T;
  vector <_int64> v;

  for (_int64 i=1; i<10000000; i++)
    if (pal(i))
      if (pal(i*i))
        v.push_back(i*i);

  for (int t=1; t<=T; t++)	{
    _int64 A, B;
	  cin >> A >> B;

    int result=0;
    for (int i=0; i<v.size(); i++)
      if (A <= v[i] && B >= v[i])
        result++;

    cout << "Case #" << t << ": " << result << endl;
	}
  
	return 0;
}
