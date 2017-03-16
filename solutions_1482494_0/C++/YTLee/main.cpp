#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define TESTING

using namespace std;



struct Candidate
{
    Candidate(int s, int r, int l, int w)
    {
        stars = s;
        req = r;
        level = l;
        weight = w;
    }

    Candidate(const Candidate& rhs)
    {
        stars = rhs.stars;
        req = rhs.req;
        level = rhs.level;
        weight = rhs.weight;
    }

    bool operator<(const Candidate& rhs)
    {
        if (req < rhs.req)
        {
            return true;
        }
        else if (req > rhs.req)
        {
            return false;
        }
        else
        {
            if (stars > rhs.stars)
            {
                return true;
            }
            else if(stars < rhs.stars)
            {
                return false;
            }
            else
            {
                if (weight > rhs.weight)
                {
                    return true;
                }
                else if (weight < rhs.weight)
                {
                    return false;
                }
                else
                {
                    if (level < rhs.level)
                    {
                        return true;
                    }
                    else if (level > rhs.level)
                    {
                        return false;
                    }
                }
            }
        }

        return false;
    }

    int stars;
    int req;
    int level;
    int weight;
};

bool cmp(const Candidate& lhs, const Candidate& rhs)
{
    if (lhs.req < rhs.req)
    {
        return true;
    }
    else if (lhs.stars > rhs.stars)
    {
        return true;
    }
    else if (lhs.level < rhs.level)
    {
        return true;
    }

    return false;
}

#define MIN(x, y) ((x) < (y)) ? (x) : (y)

int main()
{
#ifdef TESTING
    FILE *f = freopen("sample.in", "r", stdin);
    FILE *fout = freopen("result.out", "w", stdout);
#endif

    int num_case;
    scanf("%d", &num_case);

    int num_level;
    int level_state[2000];
    vector<Candidate> cs;
    for (int i = 0 ; i < num_case ; ++i)
    {
        scanf("%d", &num_level);
        memset(level_state, 0, sizeof(level_state));
        cs.clear();

        int reqA, reqB;
        for (int j = 0 ; j < num_level ; ++j)
        {
            scanf("%d %d", &reqA, &reqB);

            cs.push_back(Candidate(1, reqA, j, reqB));
            cs.push_back(Candidate(2, reqB, j, reqB));
        }

        sort(cs.begin(), cs.end());
        int level_sov = 0;
        int size = cs.size();
        int cur_stars = 0;
        bool is_bad = false;
        int steps = 0;
        int req_star = num_level * 2;

        int choose_able[2000];
        for (int j = 0 ; j < size ; ++j)
        {
            bool found = false;
            Candidate&c = cs[j];
            if (level_state[c.level] == 2) continue;

            // find 2 starts
            vector <int> cds;
            for (int k = j ; k < size ; ++k)
            {
                Candidate& cc = cs[k];
                if (level_state[cc.level] == 2) continue;
                if (cc.req > cur_stars) break;
                if (cc.stars == 2) cds.push_back(k);
            }

            int k_size = cds.size();
            if (k_size == 0)
            {
                if (cur_stars >= c.req)
                {
                    cur_stars += (c.stars - level_state[c.level]);

                    level_state[c.level] = c.stars;

                    ++level_sov;
                    ++steps; 
                    found = true;
                }
            }
            else
            {
                for (int k = 0 ; k < k_size ; ++k)
                {
                    Candidate&ck = cs[cds[k]];
                    cur_stars += (ck.stars - level_state[ck.level]);

                    level_state[ck.level] = ck.stars;

                    ++level_sov;
                    ++steps; 
                }
                found = true;
                --j;
            }

            if (cur_stars == req_star)
            {
                break;
            }

            if (!found)
            {
                is_bad = true;
                break;
            }
        }

        if (is_bad)
        {
            printf("Case #%d: Too Bad\n", (i+1), steps);
        }
        else
        {
            printf("Case #%d: %d\n", (i+1), steps);
        }
    }

#ifdef TESTING
    fclose(f);
    fclose(fout);
#endif

    return 0;
}