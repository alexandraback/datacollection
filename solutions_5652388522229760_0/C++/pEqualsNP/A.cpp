#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("A-small.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("A-small.out", "w", stdout);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		long long int n;
		cin >> n;
      bool seen[10];
      for (int i = 0; i < 10; i++)
         seen[i] = false;
      if (n == 0)
      {
         cout << "INSOMNIA" << endl;
         continue;
      }
      long long int num = n;
      while (1)
      {
         long long int tmp = num;
         while (tmp != 0)
         {
            seen[tmp % 10] = true;
            tmp = tmp / 10;
         }
         bool done = true;
         for (int i = 0; i < 10; i++)
            if (!seen[i])
            {
               done = false;
               break;
            }
         if (done)
         {
            cout << num << endl;
            break;
         }
         num += n;
      }
   }
	exit(0);
}
