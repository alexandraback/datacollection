#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
typedef unsigned long long LL;


int result[30][30];

void compute(int start, LL SUM);
int B;

main() {
	int T;
   LL M;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
      cin >> B >> M;
      for (int i = 1; i <= B; i++)
         for (int j = 1 ; j <= B; j++)
            result[i][j] = 0;
      LL tmp = 1;
      tmp = (tmp << (B - 2));
      if (tmp < M)
      {
         cout << "IMPOSSIBLE" << std::endl;
         continue;
      }
      cout << "POSSIBLE" << std::endl;
      compute(1, M);
      for (int i = 1; i <= B; i++)
      {
         for (int j = 1; j <= B; j++)
            cout << result[i][j];
         cout << std::endl;
      }
   }
	exit(0);
}

void compute(int start, LL SUM)
{
   if (start == B)
      return;
   if (start == B-1)
   {
      if (SUM == 1)
         result[B-1][B] = 1;
      return;
   }
   LL tmp = 1;
   tmp = (tmp << (B - 1 - start));
   if (tmp == SUM)
   {
      result[start][B] = 1;
      tmp = tmp - 1;
   }
   else tmp = SUM;
   int i = 1;
   while (1) 
   {
      if (tmp == 0)
         break;
      if ((tmp & 1) == 1)
      {
         result[start][B-i] = 1;
         compute(B - i, (1 << (i - 1)));
      }
      tmp = (tmp >> 1);
      i++;
   }
}
