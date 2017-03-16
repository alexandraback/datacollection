#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin ("blah.in");
ofstream fout ("blah.out");

int main()
{
    int ntest; fin >> ntest;
    for (int test = 0; test < ntest; test++)
    {
        int n;
        pair <int, int> level[1100];
        bool used[1100], used2[1100];
        for (int i = 0; i < 1100; i++)
            used[i] = used2[i] = false;
        fin >> n;
        for (int i = 0; i < n; i++)
            fin >> level[i].first >> level[i].second;
        int num = 0, count = 0;
        fout << "Case #" << test + 1 << ": ";
        bool done = false;
        while (num < 2 * n)
        {
            bool good = false;
            int best = -1, loc = 0;
            for (int i = 0; i < n; i++)
            {
                if (!used[i] && num >= level[i].first)
                {
                    if (num >= level[i].second)
                    {
                        used[i] = used2[i] = true;
                        good = true;
                        num += 2;
                        break;
                    }
                    if (level[i].second > best)
                    {
                        best = level[i].second;
                        loc = i;
                    }
                }
                else if (!used2[i] && num >= level[i].second)
                {
                    best = 1000000;
                    loc = i;
                }
            }
            count++;
            if (good) continue;
            if (best == -1)
            {
                fout << "Too Bad\n";
                done = true;
                break;
            }
            if (used[loc])
                used2[loc] = true;
            else
                used[loc] = true;
            num++;
        }
        if (!done)
            fout << count << "\n";
    }
    //system ("Pause");
    return 0;
}
