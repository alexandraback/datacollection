#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

LL compute();

int main()
{
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i)
        cout << "Case #" << i + 1 << ": " << compute() << "\n";
    return 0;
}

struct Tribe {
    int nr;
    LL day, attacks, w, e, stren, d_day, d_pos, d_stren;
    Tribe(int _nr, LL _day, LL _attacks, LL _w, LL _e, LL _stren, LL _d_day, LL _d_pos, LL _d_stren):
        nr(_nr), day(_day), attacks(_attacks), w(_w), e(_e), stren(_stren), d_day(_d_day), d_pos(_d_pos), d_stren(_d_stren)
    {}
    Tribe()
    {}
};

ostream& operator <<(ostream& os, const Tribe& t)
{
    return os << "[" << t.nr << "] " << t.day << ", " << t.attacks << ", " << t.w << ", " << t.e << ", " << t.stren << ", " << t.d_day << ", " << t.d_pos << ", " << t.d_stren;
}

bool operator < (const Tribe& t1, const Tribe& t2)
{
    if (t1.day != t2.day)
        return t1.day < t2.day;
    return t1.nr < t2.nr;
}

LL magic(LL x)
{
    return x & -x;
}

LL get_step(LL x, LL bound)
{
    LL step = magic(x);
    while (x > bound)
        step >>= 1;
    return step;
}

int log2(LL x)
{
    int res = 0;
    while (x) {
        x >>= 1;
        ++res;
    }
    return res - 1;
}

// i-th map covers 2^i consecutive tiles [p * 2^i, (p+1) * 2^i)
const int MAX_ORDER = 50;
map<LL, LL> min_maps[MAX_ORDER], max_maps[MAX_ORDER];

LL get_val(LL pos, map<LL, LL>* mps, int mps_pos)
{
    auto it = mps[mps_pos].find(pos);
    while (it == mps[mps_pos].end()) {
        ++pos;
        it = mps[mps_pos].find(pos);
    }
    if (it == mps[mps_pos].end())
        return 0;
    return it->second;
}

LL _wall[10000000];

const int OFFSET = 5000000;
LL* wall = _wall + OFFSET;

bool successfull_attack(LL w, LL e, LL s)
{
//     cout << "attack(" << w << ", " << e << ", " << s << ")\n";
//     LL step;
//     int log_step;
//     // traverse wall
//     while (w < e) {
//         step = get_step(w, e);
//         log_step = log2(step);
// 
//         if (get_val(w, min_maps, log_step) < s)
//             return false;
// 
//         w += step;
//     }
//     return true;
    while (w < e) {
//         cout << "wall[" << w << "]:" << wall[w] << ", s:" << s << "\n";
        if (wall[w] < s)
            return true;
        ++w;
    }
    return false;
}

void upgrade(LL w, LL e, LL s)
{
//     cout << "upgrade(" << w << ", " << e << ", " << s << ")\n";
//     LL step;
//     int log_step;
//     while (w < e) {
//         step = get_step(w, e);
//         log_step = log2(step);
//         while (get_val(w, max_maps[log_step]) > s
//     }

    while (w < e) {
        wall[w] = max(wall[w], s);
        ++w;
    }
}

LL compute()
{
    fill(_wall, _wall + sizeof(_wall)/sizeof(*_wall), 0);
    LL res = 0;

    set<Tribe> tribes_set;

    int tribes_num;

    cin >> tribes_num;
    for (int i = 0; i < tribes_num; ++i) {
        LL day, attacks, w, e, stren, d_day, d_pos, d_stren;
        cin >> day >> attacks >> w >> e >> stren >> d_day >> d_pos >> d_stren;
        tribes_set.insert(Tribe(i, day, attacks, w, e, stren, d_day, d_pos, d_stren));
    }

//     for (auto it = tribes_set.begin(); it != tribes_set.end(); ++it) {
//         cout << *it << "\n";
//     }

    while (!tribes_set.empty()) {
        LL curr_day = tribes_set.begin()->day;
        auto it = tribes_set.begin();
        // attack
        while (it != tribes_set.end() && it->day == curr_day) {
            if (successfull_attack(it->w, it->e, it->stren))
                ++res;
            ++it;
        }

        it = tribes_set.begin();
        // improve defence
        while (it != tribes_set.end() && it->day == curr_day) {
            upgrade(it->w, it->e, it->stren);
            ++it;
        }

        while (!tribes_set.empty() && tribes_set.begin()->day == curr_day) {
            Tribe t = *(tribes_set.begin());
            tribes_set.erase(tribes_set.begin());
            if (--t.attacks) {
                t.day += t.d_day;
                t.stren += t.d_stren;
                t.w += t.d_pos;
                t.e += t.d_pos;
                tribes_set.insert(t);
            }
        }

//         cout << "res: " << res << "\n";
//         for (int i = -10; i < 10; ++i) {
//             cout << "wall[" << i << "] = " << wall[i] << "\n";
//         }
        
    }

    return res;
}
