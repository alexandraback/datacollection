//
// Created by e5430 on 2016/5/1.
//

#include <vector>
#include <iostream>
#include <string>
#include <c++/cstring>
#include <math.h>
#include <stdlib.h>
#include <map>
using namespace std;
void solve() {
    int j, p, s;
    vector<int> poss;
    vector<int> used;
    map<int, int> jp;
    map<int, int> js;
    map<int, int> ps;
    int k;
    cin >> j >> p >> s >> k;
    for(int a1 = 0; a1 < j; ++a1)
    {
        for(int a2 =0; a2 < p ; ++a2)
        {
            for(int a3 = 0; a3 < s;++a3)
            {
                int t = a1 * 100 + a2 * 10 + (a3 + a1 + a2) % s;
                poss.push_back(t);
            }
        }
    }
    for(int i =0; i < poss.size(); ++i)
    {
        int t = poss[i];
        int j = t /100;
        int p = (t - (j * 100)) /10;
        int s = t %10;
        if(jp[j * 10 + p] < k && js[j* 10 + s] < k && ps[p*10 + s] < k)
        {
            used.push_back(t);
            jp[j * 10 + p] +=1;
            js[j* 10 + s] +=1;
            ps[p*10 + s]  +=1;
        }
    }
    std::cout << used.size() << "\n";
    for(int i =0; i < used.size(); ++i) {
        int t = used[i];
        std::cout << (t / 100) + 1 << " " << ((t%100)/10) +1 << " " << (t%10) +1 << "\n";
    }
}

int main() {
    int c;
    cin >> c;
    for(int i =0; i < c;++i)
    {
        std::cout << "Case #" << i +1 << ": ";
        solve();
    }
    return 0;
}