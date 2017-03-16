#include <string>
#include <cmath>
#include <cstdio>
#include <set>

using namespace std;

int recycledpairs(int A, int B)
{
     int num = 0;
     for (int n = A; n < B; n++)
     {
	  int digit = 0, m, tmp = n;
	  while (tmp)
	  {
	       digit++;
	       tmp /= 10;
	  }
	  set<int> store;
	  for (int j = 1; j < digit; j++)
	  {
	       tmp = pow(10,j);
	       m = (n % tmp) * pow(10, digit-j) + n / tmp;
	       if (m <= B && n < m)
	       {
		    if (store.find(m) == store.end())
		    {
			 num++;
			 store.insert(m);
		    }
	       }
	  }
     }
     return num;
}
int main()
{
     int T, A, B;
     scanf("%d", &T);
     for (int iCase = 1; iCase <= T; iCase++)
     {
	  scanf("%d %d", &A, &B);
	  printf("Case #%d: %d\n", iCase, recycledpairs(A, B));
     }
     return 0;
}
