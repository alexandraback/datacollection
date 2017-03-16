#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <climits>

struct Tribe
{
    uint64_t firstAttack;
    uint64_t attackCount;
    int64_t w;
    int64_t e;
    int64_t str;
    uint64_t wait;
    int64_t mov;
    int64_t strChange;
};

struct Attack
{
    unsigned int tribe;
    uint64_t day;

    bool operator<(Attack const& a2) const
    {
        return day > a2.day;
    }

    Attack(unsigned int _tribe, uint64_t _day)
    {
        day = _day;
        tribe = _tribe;
    }
};

std::unordered_map<int64_t, int64_t> wall;

int64_t minWall(int64_t w, int64_t e)
{
    int64_t m = INT64_MAX;

    for(int64_t i = w; i < e; i++)
    {
        m = std::min(m, wall[i]);
    }

    return m;
}

void buildWall(int64_t w, int64_t e, int64_t v)
{
    for(int64_t i = w; i < e; i++)
    {
        wall[i] = std::max(wall[i], v);
    }
}

struct Build
{
    int64_t e, w, str;

    Build(int64_t _w, int64_t _e, int64_t _str)
    {
        w = _w;
        e = _e;
        str = _str;
    }
};

uint64_t solve()
{
    wall.clear();

    unsigned int tribeCount;
    std::cin >> tribeCount;
    std::vector<Tribe> tribes(tribeCount);
    std::priority_queue<Attack> attacks;

    for(unsigned int i = 0; i < tribes.size(); i++)
    {
        Tribe& tribe = tribes[i];

        std::cin >> tribe.firstAttack >> tribe.attackCount >> tribe.w >> tribe.e >> tribe.str >> tribe.wait >> tribe.mov >> tribe.strChange;

        if(tribe.attackCount != 0)
        {
            tribe.attackCount--;
            attacks.push(Attack(i, tribe.firstAttack));
        }
    }

    uint64_t succesful = 0;

    std::vector<Build> builds;
    uint64_t lastDay = 0;

    while(!attacks.empty())
    {
        Attack attack = attacks.top();
        attacks.pop();

        if(attack.day != lastDay)
        {
            for(Build const& build : builds)
            {
                buildWall(build.w, build.e, build.str);
            }
            builds.clear();

            lastDay = attack.day;
        }

        Tribe& tribe = tribes[attack.tribe];

        //std::cout << attack.day << ": " << (attack.tribe + 1) << " (" << tribe.w << ", " << tribe.e << ") " << tribe.str;

        if(minWall(tribe.w, tribe.e) < tribe.str)
        {
            builds.push_back(Build(tribe.w, tribe.e, tribe.str));



            succesful++;

            //std::cout << " S";
        }
        //std::cout << std::endl;


        if(tribe.attackCount != 0)
        {
            attacks.push(Attack(attack.tribe, attack.day + tribe.wait));

            tribe.attackCount--;
            tribe.str += tribe.strChange;
            tribe.w += tribe.mov;
            tribe.e += tribe.mov;
        }
    }

    return succesful;
}

int main()
{
    uint64_t t;
    std::cin >> t;

    for(uint64_t i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": " << solve() << std::endl;
    }

    return 0;
}

