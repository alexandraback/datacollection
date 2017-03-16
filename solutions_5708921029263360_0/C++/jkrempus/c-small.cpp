#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
using std::cout;
using std::cin;
using std::endl;
typedef int64_t Int;

struct Combination { Int j, p, s; };

int main()
{
  Int ncases;
  cin >> ncases;
  for(Int case_ = 1; case_ <= ncases; case_++)
  {
    Int j, p, s, k;
    cin >> j;
    cin >> p;
    cin >> s;
    cin >> k;
 
    std::vector<Combination> combinations;

    for(Int ij = 0; ij < j; ij++)
      for(Int ip = 0; ip < p; ip++)
        for(Int is = 0; is < s; is++)
          combinations.push_back({ij, ip, is});
         
    std::vector<Combination> chosen;

    std::vector<Int> jp_counts;
    std::vector<Int> js_counts;
    std::vector<Int> ps_counts;

    for(Int bits = 0; bits < (1 << combinations.size()); bits++)
    {
      jp_counts.assign(j * p, 0);
      js_counts.assign(j * s, 0);
      ps_counts.assign(p * s, 0);
    
      Int nc = 0; 
      bool ok = true;
      for(Int i = 0; i < combinations.size(); i++)
        if(((bits >> i) & 1) != 0) 
        {
          jp_counts[combinations[i].j * p + combinations[i].p]++;
          js_counts[combinations[i].j * s + combinations[i].s]++;
          ps_counts[combinations[i].p * s + combinations[i].s]++;

          if(
            jp_counts[combinations[i].j * p + combinations[i].p] > k ||
            js_counts[combinations[i].j * s + combinations[i].s] > k ||
            ps_counts[combinations[i].p * s + combinations[i].s] > k)
          {
            ok = false;
            break;
          }

          nc++;
        }
       
      if(ok && nc > chosen.size())
      {
        chosen.clear();
        for(Int i = 0; i < combinations.size(); i++)
          if(((bits >> i) & 1) != 0) 
            chosen.push_back(combinations[i]);
      }
    }

    cout << "Case #" << case_ << ": " << chosen.size() << endl;
    for(auto e : chosen) cout << e.j + 1 << " " << e.p + 1 << " " << e.s + 1 << endl;
  }

  return 0;
}
