#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
using std::cout;
using std::cin;
using std::endl;
typedef int64_t Int;

bool is_better(Int a0, Int b0, Int a1, Int b1)
{
  Int diff = std::abs(a0 - b0) - std::abs(a1 - b1);
  if(diff < 0)
    return true;
  else if (diff > 0)
    return false;

  if(a0 < a1)
    return true;
  else if(a0 > a1)
    return false;

  else if(b0 < b1)
    return true;
  else
    return false;
}

std::string format(Int val, Int n)
{
  std::string s;
  for(Int i = 0; i < n; i++)
  {
    s.push_back((val % 10) + '0');
    val /= 10;
  }

  std::reverse(s.begin(), s.end());
  return s;
}

int main()
{
  Int ncases;
  cin >> ncases;
  std::string(throwaway);
  std::getline(cin, throwaway);
  for(Int case_ = 1; case_ <= ncases; case_++)
  {
    std::string line;
    std::getline(cin, line);
    auto it = std::find(line.begin(), line.end(), ' ');
    Int nc = std::distance(line.begin(), it);
    std::string s(line.begin(), it);
    ++it; 
    s.insert(s.end(), it, line.end());

    Int nq = std::count(s.begin(), s.end(), '?');
    
    std::string s2 = s;
   
    Int limit = 1; 
    for(Int i = 0; i < nq; i++) limit *= 10;
   
    Int best_c;
    Int best_j;
    bool initialized = false;

    for(Int i = 0; i < limit; i++)
    {
      Int c = 0;
      Int rem = i;
      for(Int i1 = 0; i1 < nc; i1++)
        if(s[i1] == '?')
        {
          c = c * 10 + (rem % 10); 
          rem /= 10;
        }
        else
          c = c * 10 + s[i1] - '0';
          
      Int j = 0;
      for(Int i1 = nc; i1 < s.size(); i1++)
        if(s[i1] == '?')
        {
          j = j * 10 + (rem % 10); 
          rem /= 10;
        }
        else
          j = j * 10 + s[i1] - '0';

      if(!initialized || is_better(c, j, best_c, best_j))
      {
        initialized = true;
        best_c = c;
        best_j = j;
      }
    }

    cout << "Case #" << case_ << ": " <<
      format(best_c, nc) << " " << format(best_j, s.size() - nc) << endl;
  }

  return 0;
}
