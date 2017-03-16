#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int reverse(int x)
{
     string x_ = to_string(x);
     reverse(x_.begin(),x_.end());
     return stoi(x_);
}

unordered_map<int,int> memo;

int min_counting(int target)
{
     if(memo.count(target))
          return memo[target];
     else if(target==1)
          return 1;
     else
     {
          int to_return = min_counting(target-1)+1;
          string scurrent = to_string(target);
          if(scurrent[scurrent.length()-1]!='0' && reverse(target) < target)
               to_return = min(to_return,min_counting(reverse(target))+1);
          memo[target] = to_return;
          return to_return;
     }
}

int main()
{
     int test_cases;
     cin >> test_cases;
     for(int z=1; z<=test_cases; z++)
     {
          int target;
          cin >> target;

          for(int i=1; i<target; i++)
               min_counting(i);
          cout << "Case #" << z << ": " << min_counting(target) << endl;
     }

     return 0;
}
