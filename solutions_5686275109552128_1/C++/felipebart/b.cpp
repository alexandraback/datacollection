#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int calc(const vector<int>& mapping)
{
    int resp = mapping.size() - 1;
    for(int maxsize=1;maxsize<mapping.size();++maxsize)
    {
        int nspecial = 0;
        for(int i=maxsize+1;i<mapping.size();++i)
        {
            nspecial += ((i-1)/maxsize) * mapping[i];
        }
        
        resp = min(resp, nspecial + maxsize);
    }    
    
    return resp;
    /*
    int nspecial = 0;
    for(int i=mapping.size()-1;i>0;--i)
    {
        if (mapping[i] > 0)
        {
            int f = i/2;
            int c = (i+1)/2;
            resp = min(resp, nspecial + i);
            nspecial += mapping[i];
            mapping[f] += mapping[i];
            mapping[c] += mapping[i];
        }
    }
    
    return resp;
    */
}

vector<int> mappingfromlist(const vector<int>& pancakes)
{
    auto n = *max_element(pancakes.begin(), pancakes.end());
    vector<int> mapping(n+1, 0);
    for(auto&& p : pancakes)
    {
        mapping[p]++;
    }
    
    return mapping;
}

int main()
{
    int t;
    cin >> t;
    for(int lp=1;lp<=t;++lp)
    {
        int n;
        cin >> n;
        vector<int> pancakes(n);
        for(auto& p : pancakes)
        {
            cin >> p;
        }
        
        auto mapping = mappingfromlist(pancakes);
        cout << "Case #" << lp << ": " << calc(mapping) << "\n";      
    }
    
    return 0;
}