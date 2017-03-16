
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


struct Tribe
{
    int firstDay;
    int attacks;
    int west, east;
    int firstStrength;
    int deltaDay;
    int deltaPosition;
    int deltaStrength;
};

struct Attack
{
    int day;
    int west, east, strength;

    bool operator < (const Attack &other) const
    {
        return day < other.day;
    }
};

#define N 2000
#define HALF_N N / 2

void solve()
{
    int t;
    scanf("%d", &t);
    
    vector<Attack> attacks;

    for (int i = 0; i < t; i++)
    {
        Tribe tribe;
        scanf("%d%d%d%d%d%d%d%d",
            &tribe.firstDay, &tribe.attacks,
            &tribe.west, &tribe.east,
            &tribe.firstStrength,
            &tribe.deltaDay, &tribe.deltaPosition,
            &tribe.deltaStrength);

        for (int i = 0; i < tribe.attacks; i++)
        {
            Attack attack;
            attack.day = tribe.firstDay + i * tribe.deltaDay;
            attack.west = tribe.west + i * tribe.deltaPosition;
            attack.east = tribe.east + i * tribe.deltaPosition;
            attack.strength = tribe.firstStrength + i * tribe.deltaStrength;

            attacks.push_back(attack);
        }
    }

    sort(attacks.begin(), attacks.end());
    
    int day = INT_MIN;

    vector<int> height(N, 0);
    vector<int> damaged(N, 0);

    int answer = 0;

    for (auto it = attacks.cbegin(); it != attacks.cend(); ++it)
    {
        if (day != it->day)
        {
            for (int i = 0; i < N; i++)
            {
                height[i] = damaged[i];
            }
        }

        int east = it->east;
        int str = it->strength;

        bool bad = false;
        for (int i = it->west + HALF_N; i < east + HALF_N; i++)
        {
            if (height[i] < str)
            {
                damaged[i] = max(damaged[i], str);
                bad = true;
            }
        }

        if (bad)
        {
            answer++;
        }

        day = it->day;
    }

    printf("%d", answer);
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int n;
    scanf("%d", &n);

    for (int t = 1; t <= n; t++)
    {
        printf("Case #%d: ", t);
        solve();
        printf("\n");
    }
}