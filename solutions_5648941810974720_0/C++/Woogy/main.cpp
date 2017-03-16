#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#pragma warning(disable:4996)

using namespace std;
typedef long long ll;

int countOfLetters[128];

void addDigits(string dS, char c, int digit, vector<int>& res)
{
   int count = countOfLetters[c];
   if (count <= 0)
      return;
   for (char cS : dS)
      countOfLetters[cS]-= count;
   
   for (int i = 0; i < count; i++)
      res.push_back(digit);
}

int main()
{
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int nTests;
   scanf("%d", &nTests);
   for (int test = 1; test <= nTests; test++)
   {
      string s;
      cin >> s;
      memset(countOfLetters, 0, 128 * 4);
      for (char c : s)
         countOfLetters[c]++;

      vector<int> result;
      result.reserve(s.length() / 2);

      addDigits("ZERO", 'Z', 0, result);
      addDigits("TWO", 'W', 2, result);
      addDigits("FOUR", 'U', 4, result);
      addDigits("EIGHT", 'G', 8, result);
      addDigits("FIVE", 'F', 5, result);
      addDigits("ONE", 'O', 1, result);
      addDigits("SEVEN", 'V', 7, result);
      addDigits("THREE", 'T', 3, result);
      addDigits("SIX", 'S', 6, result);
      addDigits("NINE", 'I', 9, result);

      sort(result.begin(), result.end());

      printf("Case #%d: ", test);
      for (int i : result)
         printf("%d", i);
      puts("");
   }

   return 0;
}