#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int J, P, S, k, T;
    scanf("%d", &T);
    for(int t=1; t <= T; ++t)
    {
        scanf("%d%d%d%d", &J, &P, &S, &k);

        int jp[4][4], js[4][4], ps[4][4];
        bool worn[4][4][4];
        vector< pair<int, pair<int, int> > > outfits;
        vector< pair<int, pair<int, int> > > maxOutfits;

        for(int i=1; i <= 3; ++i)
            for(int j=1; j <= 3; ++j)
                for(int t=1; t <= 3; ++t)
                    worn[i][j][t] = false;
        for(int i=1; i <= 3; ++i)
            for(int j=1; j <= 3; ++j)
                jp[i][j] = js[i][j] = ps[i][j] = false;

        int day = 0, maxDay = 0;

        outfits.push_back(make_pair(1, make_pair(1, 1)));
        while(!outfits.empty())
        {
            pair<int, pair<int, int> > top = outfits.back();
            int j = top.first, p = top.second.first, s = top.second.second;

            if(worn[j][p][s] ||
               jp[j][p] == k || js[j][s] == k || ps[p][s] == k)
            {
                s++;
                if(s > S)
                {
                    s = 1;
                    if(++p > P)
                    {
                        p = 1;
                        if(++j > J)
                        {
                            outfits.pop_back();
                            --day;
                            continue;
                        }
                    }
                }
                outfits.pop_back();
                outfits.push_back(make_pair(j, make_pair(p, s)));
            }
            else
            {
                jp[j][p]++;
                js[j][s]++;
                ps[p][s]++;
                worn[j][p][s] = true;
                outfits.push_back(make_pair(1, make_pair(1, 1)));
                if(++day > maxDay)
                {
                    maxDay = day;
                    maxOutfits.resize(day);
                    for(int i=0; i < day; ++i)
                        maxOutfits[i] = outfits[i];
                }
            }
        }

        printf("Case #%d: %d\n", t, maxDay);
        for(int i=0; i < maxDay; ++i)
        {
            printf("%d %d %d\n", maxOutfits[i].first,
                                 maxOutfits[i].second.first,
                                 maxOutfits[i].second.second);
        }
    }

    return 0;
}
