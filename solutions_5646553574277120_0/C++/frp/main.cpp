/* 
 * File:   main.cpp
 * Author: roman
 *
 * Created on 10 травня 2015, 11:45
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <cassert>
#include <set>
#include <algorithm>
using namespace std;

void test(int ti)
{
    int c, d, v;
    cin >> c >> d >> v;
    
    assert(c == 1);
    
    vector<int> denominations(d);
    set<int> ds;
    for (int i = 0; i < d; i++)
    {
        cin >> denominations[i];
        ds.insert(denominations[i]);
    }
    
    vector<bool> possible(v + 1);
    
    for (int i = 0; i < (1 << d); i++)
    {
        int sum = 0;
        for (int bit = 0; bit < d; bit++)
            if (i & (1 << bit))
                sum += denominations[bit];
        
        if (sum <= v)
            possible[sum] = true;
    }
    
    int added = 0;
    while(true)
    {
        vector<int> needed_sums(v + 1);
        bool need_more = false;
        for (int i = 1; i <= v; i++)
        {
            if (!possible[i])
            {
                need_more = true;
                for (int j = 0; j < d; j++)
                    if (i - denominations[j] > 0 && ds.count(i - denominations[j]) == 0)
                        needed_sums[i - denominations[j]]++;
                if (ds.count(i) == 0)
                    needed_sums[i]++;
            }
        }
        
        if (!need_more) break;
        
        int sum_to_add = max_element(needed_sums.begin(), needed_sums.end()) - needed_sums.begin();
        denominations.push_back(sum_to_add);
        d++;
        ds.insert(sum_to_add);

        for (int i = 0; i < (1 << d); i++) {
            int sum = 0;
            for (int bit = 0; bit < d; bit++)
                if (i & (1 << bit))
                    sum += denominations[bit];

            if (sum <= v)
                possible[sum] = true;
        }
        
        added++;
    }
    
    cout << "Case #" << ti << ": " << added << endl;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        test(i+1);
}

