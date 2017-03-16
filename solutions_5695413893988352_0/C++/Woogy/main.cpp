#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;
typedef long long ll;

ll resDiff = 9223372036854775807;
string resA = "";
string resB = "";
ll resAN = 0;
ll resBN = 0;


void solve(ll curA, ll curB, string aS, string bS, int mult, int i)
{
   if (i == aS.length())
   {
      ll curDiff = abs(curA - curB);
      if (curDiff < resDiff)
      {
         resDiff = curDiff;
         resA = aS; resB = bS;
         resAN = curA; resBN = curB;
      }
      else if (curDiff == resDiff)
      {
         if ((resAN == curA && resBN > curB) || resAN > curA)
         {
            resDiff = curDiff;
            resA = aS; resB = bS;
            resAN = curA; resBN = curB;
         }
      }
      return;
   }
   char a = aS[i], b = bS[i];

   vector<char> aF;
   vector<char> bF;

   if (a == '?')
   {
      aF.push_back('0');
      aF.push_back('1');
      aF.push_back('2');
      aF.push_back('3');
      aF.push_back('4');
      aF.push_back('5');
      aF.push_back('6');
      aF.push_back('7');
      aF.push_back('8');
      aF.push_back('9');
   }
   else
   {
      aF.push_back(aS[i]);
   }
   if (b == '?')
   {
      bF.push_back('0');
      bF.push_back('1');
      bF.push_back('2');
      bF.push_back('3');
      bF.push_back('4');
      bF.push_back('5');
      bF.push_back('6');
      bF.push_back('7');
      bF.push_back('8');
      bF.push_back('9');
   }
   else
   {
      bF.push_back(bS[i]);
   }
   for (int k = 0; k < aF.size(); k++)
      for (int j = 0; j < bF.size(); j++)
      {
         aS[i] = aF[k];
         bS[i] = bF[j];
         solve(curA + (aS[i] - '0')*mult, curB + (bS[i] - '0')*mult, aS, bS, mult / 10, i + 1);
      }
}


int main()
{
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   int nTests;
   scanf("%d", &nTests);
   for (int test = 1; test <= nTests; test++)
   {
      resDiff = 9223372036854775807;
      string aS, bS;
      cin >> aS >> bS;
      ll curA = 0, curB = 0;
      ll mult = ll(pow(10.0, aS.length() - 1));
      solve(curA, curB, aS, bS, mult, 0);
      
      printf("Case #%d: ", test);
      cout << resA << " " << resB << endl;
   }

   return 0;
}