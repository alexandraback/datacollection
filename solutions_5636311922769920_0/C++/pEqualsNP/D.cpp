#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <cmath> 

using namespace std;
typedef long long LL;

typedef unsigned long long int ULL;

main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
      ULL K, C, S;
      std::cin >> K >> C >> S;
      if (K != S)
      {
         std::cout << "IMPOSSIBLE" << std::endl;
         continue;
      }
      for (int i = 1; i <= K; i++)
      {
         ULL pos = i;
         for (int j = 1; j < C; j++)
            pos = K*(pos - 1) + i;
         std::cout << pos << " ";
      }
      std::cout << std::endl;
   }
	exit(0);
}

