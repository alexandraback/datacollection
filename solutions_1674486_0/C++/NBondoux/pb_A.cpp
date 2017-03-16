#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Num {
        int _v;
        int _t;
        list <Num *> _c;
        Num():_t(-1){};
};

bool f(Num &n, int tag)
{
    if(n._t == tag)
    {
        return false;
    }
    n._t = tag;
    for (auto cp : n._c)
    {
        if (!f(*cp,tag))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    unsigned int pb_total;
    cin >> pb_total;
    for (unsigned int pb_idx = 1;pb_idx <= pb_total;++pb_idx)
    {
        cerr << "Case #" << pb_idx << endl;

        unsigned int N;
        cin >> N;

        map<int,Num> num_m;
        list<Num *> parents;

        for (unsigned int n = 1;n <= N;n++)
        {
            int parent_tot;
            cin >> parent_tot;
            auto &num = num_m[n];
            num._v = n;
            
            for (unsigned int p = 1; p <= parent_tot; p++)
            {
                unsigned int n_p;
                cin >> n_p;
                auto &num_p = num_m[n_p];
                num_p._v = n_p;
                num_p._c.push_back(&num);
            }
            if(parent_tot == 0)
            {
                parents.push_back(&num);
            }
        }
        bool isOk = true;
        int tag = 0;
        for (auto  pp : parents)
        {
            ++tag;
            auto &p = *pp;
            if (!f(p,tag))
            {
                isOk = false;
                break;
            }
        }

        if (isOk)
        {
            cout << "Case #" << pb_idx <<  ": No" << endl;
        }
        else
        {
            cout << "Case #" << pb_idx <<  ": Yes" << endl;
        }
    }

    return 0;
}
