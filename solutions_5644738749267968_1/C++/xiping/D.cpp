#include <iostream>

#include <vector>

#include <algorithm>

#include <iterator>

using namespace std;

void solve_case();

int main()
{
   int T = 0;
   cin >> T;
   for (int i = 0; i < T; ++ i)
   {
      cout << "Case #" << i + 1 << ": ";
      solve_case();
      cout << '\n';
   }

   return 0;
}

void solve_case()
{
   int N = 0;
   cin >> N;

   vector<double> naomi(N);
   vector<double> ken(N);

   for(int i = 0; i < N; ++ i) cin >> naomi[i];
   for(int i = 0; i < N; ++ i) cin >> ken[i];

   sort(naomi.begin(), naomi.end());
   sort(ken.begin(), ken.end());

#if 0
cout << '\n' << "Naomi: ";
copy(naomi.begin(), naomi.end(), ostream_iterator<double>(cout, ","));
cout << '\n' << "Ken: ";
copy(ken.begin(), ken.end(), ostream_iterator<double>(cout, ","));
cout << '\n';
#endif


   /** cheating algorithm */

   vector<double>::iterator iter = naomi.begin();
   vector<double>::iterator iter2 = ken.begin();
   vector<double>::reverse_iterator riter = ken.rbegin();

   while (iter != naomi.end())
   {
if (*iter < *iter2)
{
++riter;
}
else
{
++ iter2;
}
++ iter;
   }

   int score_cheat = ken.rend() - riter;

   /** now regular score */
   iter = naomi.begin();
   iter2 = ken.begin();

   while(iter != naomi.end() && iter2 != ken.end())
   {
      if (*iter < *iter2)
         ++ iter;
      ++ iter2;
   }
   int score_regular = naomi.end() - iter;

   cout << score_cheat << ' ' << score_regular;


}
