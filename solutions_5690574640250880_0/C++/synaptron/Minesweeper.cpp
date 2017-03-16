

#include <cstdlib>
#include <cstdio>
#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;


int main(int argc, char ** argv)
{
    // read the tests count
    int T = 0;
    cin >> T;
    // run the test cases
    int t = 0;
    while (t < T)
    {
        ++t;
        // load the values
        int R, C, M;
        cin >> R;
        cin >> C;
        cin >> M;
        // solve
        cout << "Case #" << t << ": " << endl;
        int free = R * C - M;
        bool impossible = !free;
        string tmp;
        int last = 0;
        const bool single = (free == 1);
        for (int r = 0; !impossible && (r < R); ++r)
        {
            int run = 0;
            if (!r)
            {
                // first line
                if (single || (R <= 1))
                {
                    // single row
                    run = free;
                }
                else
                {
                    run = free / 2;
                    if ((run > 0) && ((free % run) == 1))
                    {
                        // cannot leave a single free field on over-next line
                        --run;
                    }
                }
            }
            else
            {
                // other lines
                run = last;
                if ((run > 0) && (r > 1) && (C > 1) && ((free - last) == 1))
                {
                    // cannot leave a single free field on next line
                    --run;
                }
                if (run > free)
                {
                    run = free;
                }
            }
            if (run > C)
            {
                run = C;
            }
            else if ((C > 1) && (run == 1) && !single)
            {
                impossible = true;
                break;
            }
            int c;
            for (c = 0; c < run; ++c)
            {
                if (!r && !c)
                    tmp += 'c';
                else
                    tmp += '.';
            }
            for (c = run; c < C; ++c)
            {
                tmp += '*';
            }
            tmp += '\n';
            free -= run;
            last = run;
        }
        if (impossible || free)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << tmp;
        }
    }
    return EXIT_SUCCESS;
}
