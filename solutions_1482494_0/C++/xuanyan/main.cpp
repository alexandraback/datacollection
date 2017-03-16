#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    ifstream cin("E:/input.txt");
    ofstream cout("E:/output.txt");
    int T;
    cin >> T;

    for (int cases = 1; cases <= T; ++cases)
    {
        int N;
        cin >> N;
        vector<pair<int, int>> star;
        int star_count = 0;
        vector<bool> one_star(N);
        int sum = 0;
        bool fail = false;

        for (int i = 0; i < N; ++i)
        {
            int s1, s2;
            cin >> s1 >> s2;
            star.push_back(make_pair(s2, s1));
        }

        sort(star.begin(), star.end());

        for (int i = 0; i < N; ++i)
        {
            bool changed = true;

            while (changed && star_count < star[i].first)
            {
                changed = false;

                for (int j = N - 1; star_count < star[i].first && j >= i; --j)
                {
                    if (!one_star[j] && star_count >= star[j].second)
                    {
                        changed = true;
                        one_star[j] = true;
                        ++star_count;
                        ++sum;
                    }
                }
            }

            if (star_count < star[i].first)
            {
                fail = true;
                break;
            }

            star_count += one_star[i] ? 1 : 2;
            ++sum;
        }

        if (fail)
            cout << "Case #" << cases << ": Too Bad" << endl;
        else
            cout << "Case #" << cases << ": " << sum << endl;
    }

    cin.close();
    cout.close();
    return 0;
}
