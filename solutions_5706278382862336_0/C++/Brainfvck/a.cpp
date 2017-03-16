#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;


long long gcd(long long a,long long b)
{
      if (!b) return a;
      else return gcd(b,a%b);
}

int main()
{
      long long p,q;
      int tt;
      cin >> tt;
      string s;
      for (int ii = 0; ii < tt; ii++)
      {
	    cin >> s;
	    p = 0;
	    int i;
	    for (i = 0; s[i] != '/'; i++)
		  p = p * 10 + s[i] - '0';
	    q = 0;
	    for (i++;i < s.length(); i++)
		  q = q * 10 + s[i] - '0';
	    int gen = 0;
	    while (p * 2 < q)
	    {
		  p *= 2;
		  gen ++;
	    }
	    gen ++;
	    long long x = gcd(p,q);
	    q = q / x;
	    int flag = 0;
	    while (q > 1)
	    {
		  if (q % 2)
		  {
			flag = 1;
			break;
		  }
		  q /= 2;
	    }
	    if (flag == 0) cout << "Case #" << ii + 1 << ": " << gen << endl;
	    else cout << "Case #" << ii + 1 << ": " << "impossible" << endl;
      }
      return 0;
}
