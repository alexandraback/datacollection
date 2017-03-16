#include <cassert>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class Numbers
{
public:
    
    vector<int> items;
    
    Numbers(int a, int b, int c)
    {
        items.push_back(a);
        items.push_back(b);
        items.push_back(c);
        sort(items.begin(), items.end());
    }
    
    bool operator<(const Numbers& n) const
    {
        return lexicographical_compare(items.begin(), items.end(),
                                       n.items.begin(), n.items.end());
    }
    
    vector<int> products()
    {
        assert(items.size() == 3);
        
        int a = items[0];
        int b = items[1];
        int c = items[2];
        
        vector<int> result;
        result.push_back(1); /// 000
        result.push_back(c); /// 001
        result.push_back(b); /// 010
        result.push_back(b*c); /// 011
        result.push_back(a); /// 100
        result.push_back(a*c); /// 101
        result.push_back(a*b); /// 110
        result.push_back(a*b*c); /// 111
        return result;
    }
    
    void print() const
    {
        printf("%d%d%d\n", items[0], items[1], items[2]);
    }
};



int main(int argc, char** argv)
{
    vector<Numbers> all;
    
    map<int, set<Numbers> > productToNumbers;
    
    int T = 1;
    scanf("%d", &T);
    
    int R = 100;
    int N = 3;
    int M = 5;
    int K = 7;
    
    scanf("%d %d %d %d", &R, &N, &M, &K);
    
    for(int a = 2; a <= M; ++a)
        for(int b = 2; b <= M; ++b)
            for(int c = 2; c <= M; ++c)
            {
                all.push_back(Numbers(a, b, c));
                vector<int> prod = all.back().products();
                
                for(int i = 0; i < int(prod.size()); ++i)
                    productToNumbers[prod[i]].insert(all.back());
            }
    
    printf("Case #1: \n");
    
    for(int r = 0; r < R; ++r)
    {
        map<Numbers, int> occurences;
        set<Numbers> universe;
        universe.insert(all.begin(), all.end());
        
        for(int k = 0; k < K; ++k)
        {
            int product;
            scanf("%d", &product);
            
            set<Numbers>& intersectee = productToNumbers[product];
            
            set<Numbers> newUniverse;
            for(set<Numbers>::iterator it = universe.begin(); it != universe.end(); ++it)
                if(intersectee.count(*it))
                {
                    occurences[*it] += 1;
                    newUniverse.insert(*it);
                }
            universe = newUniverse;
        }
        
        assert(!universe.empty());
        map<int, int> digitToOccurence;
        int s = 0;
        for(set<Numbers>::iterator it = universe.begin(); it != universe.end(); ++it)
        {
            for(int i = 0; i < int(it->items.size()); ++i)
            {
                digitToOccurence[it->items[i]]++;
                ++s;
            }
        }
        
        Numbers best = *universe.begin();
        double bprob = 0.0;
        
//         for(set<Numbers>::iterator it = universe.begin(); it != universe.end(); ++it)
//         {
//             double tprob = 0.0;
//             
//             for(int i = 0; i < it->items.size(); ++i)
//                 tprob += digitToOccurence[it->items[i]];
//             
//             tprob /= s;
//             
//             if(tprob > bprob)
//             {
//                 bprob = tprob;
//                 best = *it;
//             }
//         }
        
        best.print();
    }
    
 
    
    
    return 0;
}