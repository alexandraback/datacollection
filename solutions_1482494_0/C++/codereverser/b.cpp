#include <iostream>
#include <queue>
#include <iomanip>
#include <vector>
#include <fstream>
#include <set>
#include <climits>
using namespace std;

struct Level { 
    int level;
    int l1, l2;
    
    Level(int a, int b, int c) { 
        level = a;
        l1 = b; 
        l2 = c;
    }
};

class L1compare
{
public:
  bool operator() (const Level& lhs, const Level&rhs) const
  {
    return (lhs.l1 > rhs.l1);
  }
};

class L2compare
{
public:
  bool operator() (const Level& lhs, const Level&rhs) const
  {
    return (lhs.l2 > rhs.l2);
  }
};


int main(int argc, char** argv) {
    
    int cases, i, l1, l2;
    int levels, stars, tries;
    set<int> list;
    priority_queue< Level, vector<Level>, L1compare > l1q; 
    priority_queue< Level, vector<Level>, L2compare > l2q;
    
    cin >> cases;
    for (int c = 1; c<=cases; c++) { 
        list.clear();
        stars = 0;
        tries = 0;
        cin >> levels;
        
        l1q = priority_queue< Level, vector<Level>, L1compare > (); 
        l2q = priority_queue< Level, vector<Level>, L2compare > ();
        for (int i=0; i<levels; i++) { 
            cin >> l1 >> l2;
            Level L1(i+1, l1, l2);
            l1q.push(L1);
            Level L2(i+1, l1, l2);
            l2q.push(L2);
        }

        while(!l2q.empty()) { 
            int min_star_l1 = l1q.empty() ? INT_MAX : l1q.top().l1;
            int min_star_l2 = l2q.empty() ? INT_MAX : l2q.top().l2;
            if (stars >= min_star_l2) { 
                if ( list.count(l2q.top().level) ) stars += 1;
                else stars += 2;
                list.insert(l2q.top().level);
                l2q.pop();
                tries++;
            } else if (stars >= min_star_l1) { 
                l1q.pop();
                stars += 1;
                tries++;
            } else break;
        }
        if ( list.size() == levels )  { 
            cout << "Case #" << c << ": " << tries << endl;
        } else if ( list.size() < levels )  { 
            cout << "Case #" << c << ": Too Bad" << endl;
        } else cout << "Case #" << c << ": Error" << endl; /// Should not happen.
    }
    return 0;
}
