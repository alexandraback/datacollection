#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

int T;
int N;

vector<int> pos;
vector<double> speed;

int solve(double pos0, double spd0, double pos1, double spd1)
{
    if (spd0 < spd1)
    {
        double dist0 = 360 - pos0;
        double time0 = dist0 / spd0;

        double dist1 = spd1 * time0;

        if (dist1 >= 360 + 360 - pos1 - 1e-9)
            return 1;
        else
            return 0;
    }
    else
    {
        double diffSpeed = spd0 - spd1;
        double diffDist = pos1 - pos0;
        double time0 = diffDist / diffSpeed;

        double dist0 = spd0 * time0;
        double dist1 = spd1 * time0;

        if (pos0 + dist0 >= 360 - 1e-9)
            return 0;
        else
            return solve(pos1 + dist1, spd1, pos0 + dist0, spd0);
    }
}

int main()
{
    scanf("%d", &T);
    REP(tc, T)
    {
        pos.clear();
        speed.clear();
        scanf("%d", &N);
        REP(i, N)
        {
            int d, h, m;
            scanf("%d %d %d", &d, &h, &m);
            REP(j, h)
            {
                pos.push_back(d);
                speed.push_back(360.0/(m+j));
            }
        }

        printf("Case #%d: ", tc+1);

        if (pos.size() == 1 || speed[0] == speed[1])
        {
            printf("0\n");
            continue;
        }

        if (pos[0] > pos[1])
        {
            swap(pos[0], pos[1]);
            swap(speed[0], speed[1]);
        }
        else if (pos[0] == pos[1] && speed[0] > speed[1])
        {
            swap(speed[0], speed[1]);
        }

        printf("%d\n", solve(pos[0], speed[0], pos[1], speed[1]));
    }
}
