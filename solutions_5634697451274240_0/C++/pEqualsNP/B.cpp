#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long LL;

void reverse(std::vector<char>&, int);

main() {
	int T;
	cin >> T;
   std::string dummy;
   std::getline(std::cin, dummy);
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
      std::string inputS;
      std::getline(std::cin, inputS);
      std::vector<char> S;
      for (int i = 0; i < inputS.size(); i++)
         if ((inputS[i] == '-') || (inputS[i] == '+'))
            S.push_back(inputS[i]);

      int result = 0;
      int endIndex = S.size() - 1;
      while (1)
      {
         while ((endIndex >= 0) && (S[endIndex] == '+'))
            endIndex--;
         if (endIndex < 0)
            break;
         if (S[0] == '-')
         {
            result++;
            reverse(S, endIndex);
         }
         else 
         {
            int maxFound = 0;
            int pos = 0;
            for (int i = endIndex; i >= 0; i--)
            {
               int j = i;
               int count = 0;
               while ((j >= 0) && (S[j] == '+'))
               {
                  ++count;
                  j--;
               }
               if (maxFound < count)
               { 
                  maxFound = count;
                  pos = i;
               }
            }
            reverse(S, pos);
            reverse(S, endIndex);
            result += 2;
         }
      }
      std::cout << result << std::endl;
   }
	exit(0);
}

void reverse(std::vector<char>& S, int pos)
{
   for (int i = 0; i <= pos / 2; i++)
   {
      if (2 * i == pos)
      {
         if (S[i] == '-')
            S[i] = '+';
         else 
            S[i] = '-';
         continue;
      }
      char c = S[i];
      if (S[pos - i] == '-')
         S[i] = '+';
      else
         S[i] = '-';
      if (c == '-')
         S[pos - i] = '+';
      else
         S[pos - i] = '-';
   }

}

