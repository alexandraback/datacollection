#include <algorithm>
#include <functional>
#include <iostream>
#include <set>

using namespace std;

#define MAXBLOCKS 1000

int blocks;
int blocks_naomi[MAXBLOCKS];
int blocks_ken[MAXBLOCKS];

int war_result()
{
    sort(blocks_naomi, blocks_naomi + blocks, std::greater<int>());
    set<int> ken_set(blocks_ken, blocks_ken + blocks);
    int points = 0;
    for (int i = 0; i < blocks; ++i)
    {
        int val = blocks_naomi[i];
        set<int>::iterator ken_iter = ken_set.upper_bound(val);
        if (ken_iter == ken_set.end())
        {
            ++points;
            ken_set.erase(ken_set.begin());
        }
        else
        {
            ken_set.erase(ken_iter);
        }
    }
    return points;
}

int deceitful_result()
{
    int points = 0;
    set<int> set_naomi(blocks_naomi, blocks_naomi + blocks);
    sort(blocks_ken, blocks_ken + blocks);
    int ken_start = 0;
    int ken_end = blocks - 1;
    for (int i = 0; i < blocks; ++i)
    {
        int smallest_ken = blocks_ken[ken_start];
        set<int>::iterator iter = set_naomi.upper_bound(smallest_ken);
        if (iter == set_naomi.end())
        {
            --ken_end;
            set_naomi.erase(set_naomi.begin());
        }
        else
        {
            ++points;
            ++ken_start;
            set_naomi.erase(iter);
        }
    }
    return points;
}

void process()
{
    double d;
    cin >> blocks;
    for (int i = 0; i < blocks; ++i)
    {
        cin >> d;
        blocks_naomi[i] = (int)floor(d*100000.0 + 0.5);
    }
    for (int i = 0; i < blocks; ++i)
    {
        cin >> d;
        blocks_ken[i] = (int)floor(d*100000.0 + 0.5);
    }
    cout << deceitful_result() << " " << war_result() << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        process();
    }
    return 0;
}