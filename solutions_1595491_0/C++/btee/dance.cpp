#include <cstdlib>
#include <cstdio>

#include <algorithm>
#include <map>
#include <sstream>
#include <vector>

#include <iostream>

using namespace std;

struct tri {
    int res[3];
    int canMod;
    int total;
    bool taken;
};

class TriSolutionSorter {
public:
    bool operator() (const tri& lhs, const tri& rhs) {
        return ! (
            lhs.res[0] < rhs.res[0] ||
            (lhs.res[0] == rhs.res[0] && lhs.canMod < rhs.canMod)
        );
    }
};

int solve(int aSuprises, int aP,const vector<int> &aTotals) {
    vector<tri> rev(aTotals.size());
    
    vector<tri>::iterator rIt = rev.begin();
    for(vector<int>::const_iterator it = aTotals.begin(); it!=aTotals.end(); ++it, ++rIt) {
        int div = *it / 3;
        int res = *it % 3;
        
        tri& t(*rIt);
        t.total = *it;
        t.taken = false;
        t.res[0] = t.res[1] = t.res[2] = div;
        switch(res) {
            case 0:
                // x x x
                // x+1 x x-1
                if(t.res[2] > 0)
                    t.canMod = 1;
                else 
                    t.canMod = 0;
                break;
            case 1:
                // x+1 x x
                // x+2 x x-1
                ++t.res[0];
                t.canMod = 0;
                break;
            case 2:
                // x+1 x+1 x
                // x+2 x x
                ++t.res[0];
                ++t.res[1];
                t.canMod = 1;
                break;
        }
    }
    
    int ret = 0;
    sort(rev.begin(), rev.end(), TriSolutionSorter());
    
    rIt = rev.begin();
    for(;rIt != rev.end() && (rIt->res[0] >= aP); ++rIt) {
        if(rIt->res[0] >= aP){
            rIt->taken = true;
            ++ret;
        }
    }
    
    for(;rIt != rev.end() && aSuprises > 0; ++rIt) {
        int needed = aP - rIt->res[0];

        // thanks to the sort, we handle tris that can be modified by 1 first
        if(needed <= rIt->canMod) {
            rIt->res[0] += needed;
            rIt->res[1] -= needed;
            aSuprises -= needed;
            ++ret;
            rIt->taken = true;
        }
    }
    
    return ret;
}

int main(){
    int cases;
    cin >> cases;
    
    for(int i=0; i<cases; ++i) {
        int n;
        cin >> n;
        int suprises;
        cin >> suprises;
        int p;
        cin >> p;
        
        vector<int> totals;
        totals.reserve(n);
        for(int _j=0; _j<n; ++_j) {
            int tmp;
            cin >> tmp;
            totals.push_back(tmp);
        }
        
        int ret = solve(suprises, p, totals);

        printf("Case #%d: %d\n", 
            (i+1), ret
        );
    }
    
    return 0;
}
