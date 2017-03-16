#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;



struct Attacker
{
    int d_i, n_i, w_i, e_i, s_i, delta_di, delta_pi, delta_si;
    Attacker()
    {
        cin >> d_i >> n_i >> w_i >> e_i >> s_i >> delta_di >> delta_pi >> delta_si;
    }
    bool operator<(const Attacker & rhs) const
    {
        return d_i < rhs.d_i;
    }
};

void testcase(int tst)
{
    int N;
    cin >> N;
    std::vector<Attacker> attackers;
    for(int n = 0; n < N; ++n)
    {
        Attacker a;
        attackers.push_back(a);
    }
    sort(attackers.begin(), attackers.end());
    
    map<int, int> wall;
    int t_succeeded = 0;
    while(!attackers.empty())
    {
        int day = attackers[0].d_i;
        int b;
        for(b = 1; b <= attackers.size(); ++b)
        {
            if(b >= attackers.size() || attackers[b].d_i != day) break;
        }
        map<int, int> daymaxattacks;
        for(int i = b - 1; i >= 0; --i)
        {
            Attacker a = attackers[i];
            bool succeeded = false;
            for(int c = a.w_i * 2; c <= a.e_i * 2; ++c)
            {
                pair<map<int,int>::iterator,bool> it = daymaxattacks.insert(make_pair(c, a.s_i));
                if(!it.second)
                {
                    it.first->second = max(it.first->second, a.s_i);
                }
                if(wall[c] < a.s_i)
                {
                    succeeded = true;
                }
            }
            if(succeeded)
            {
                ++t_succeeded;
            }
            a.d_i += a.delta_di;
            a.n_i--;
            a.w_i += a.delta_pi;
            a.e_i += a.delta_pi;
            a.s_i += a.delta_si;
            attackers.erase(attackers.begin() + i);
            if(a.n_i > 0)
            {
                attackers.insert(lower_bound(attackers.begin(), attackers.end(), a), a);
            }
        }
        for(map<int,int>::iterator it=daymaxattacks.begin();
            it != daymaxattacks.end();
            ++it)
        {
            pair<map<int,int>::iterator,bool> jt = wall.insert(make_pair(it->first, it->second));
            if(!jt.second)
            {
                jt.first->second = max(jt.first->second, it->second);
            }
        }
    }
    cout << "Case #" << tst << ": " << t_succeeded << endl;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        testcase(t);
    }
    return 0;
}
