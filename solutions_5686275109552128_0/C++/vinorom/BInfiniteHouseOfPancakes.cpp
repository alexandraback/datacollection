#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;

    struct PancakeCount
    {
        int pancakes; // number of pancakes
        int count; // number of dinners having given number of pancakes
        PancakeCount(): pancakes(), count() {}
    };

    for (int t = 1; t <= T; ++t)
    {
        int D;
        cin >> D;

        // greedy algorithm:
        // 1. sort dinners by number of pancakes
        // 2. find min breakfast time by checking cases when max number of pancakes at each plate is limited
        // O(n^2)

        vector<PancakeCount> counts(1001, PancakeCount()); // counting sort, max number of pancakes is 1000 by definition
        for (int i = 0; i < D; ++i)
        {
            int pancakes;
            cin >> pancakes;
            counts[pancakes].pancakes = pancakes;
            ++counts[pancakes].count;
        }
        // reduce size of counts array by deleting empty elements
        for (int i = 0; i < counts.size();)
        {
            if (counts[i].count == 0)
            {
                counts.erase(counts.begin() + i);
            }
            else
            {
                //cout << "out: p=" << counts[i].pancakes << " c=" << counts[i].count << endl;
                ++i;
            }
        }

        int max_pancakes = counts.back().pancakes;
        int min_time = max_pancakes; // max available breakfast time (from the happiest dinner, no special minutes)
        for (; max_pancakes >= 1; --max_pancakes)
        {
            int total_special_minutes = 0;
            // allow at most max_pancakes pancakes at each plate
            for (int j = counts.size() - 1; j >= 0 && counts[j].pancakes >= max_pancakes; --j)
            {
                int pancakes = counts[j].pancakes;
                int special_minutes = pancakes / max_pancakes - 1;
                if (pancakes % max_pancakes > 0) ++special_minutes;
                special_minutes *= counts[j].count;
                total_special_minutes += special_minutes;
            }

            int time = total_special_minutes + max_pancakes;
            min_time = min(min_time, time);

            //cout << "out: max_pancakes=" << max_pancakes << " total_special_minutes=" << total_special_minutes
            //<< " time=" << time << " min_time=" << min_time << endl;
        }

        cout << "Case #" << t << ": " << min_time << endl;
    }

    return 0;
}
