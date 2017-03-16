#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int cas, len, ans1, ans2;
   double num;

   scanf("%d",&cas);
   for (int k=1; k<=cas; ++k) {
      vector<double> arr1, arr2, arr3, arr4;
      scanf("%d",&len);
      for (int i=0; i<len; ++i) {scanf("%lf",&num); arr1.push_back(num); arr3.push_back(num);}
      for (int i=0; i<len; ++i) {scanf("%lf",&num); arr2.push_back(num); arr4.push_back(num);}
      sort(arr1.begin(), arr1.end()); sort(arr2.begin(), arr2.end());
      sort(arr3.begin(), arr3.end()); sort(arr4.begin(), arr4.end());
      ans1 = ans2 = 0;
      while (arr1.size()>0) {
         num = arr1[arr1.size()-1];
         arr1.pop_back();
         while (arr2.size() && arr2[arr2.size()-1] > num)
            arr2.pop_back();
         if (arr2.size()==0) break;
         else { ++ans1; arr2.pop_back(); }
      }
      while (arr4.size()>0) {
         num = arr4[arr4.size()-1];
         arr4.pop_back();
         while (arr3.size() && arr3[arr3.size()-1] > num)
            arr3.pop_back();
         if (arr3.size()==0) break;
         else { ++ans2; arr3.pop_back(); }
      }
      printf("Case #%d: %d %d\n", k, ans1, len-ans2);
   }
   return 0;
}
