#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

typedef long long int Long;


int solve(const vector< pair<int, int> >& starsNeeded, vector<int>& done,
          int stars, map<Long, int>& cache)
{
    int numLevels = starsNeeded.size();
    bool finished = true;
    for (int i = 0; i < numLevels; i++)
    {
        if (done[i] < 2)
        {
            finished = false;
            break;
        }
    }

    if (finished)
    {
        return 0;
    }

    Long sig = 0;
    for (int i = 0; i < numLevels; i++)
    {
        sig *= 4;
        sig += done[i];
    }

    if (cache.find(sig) != cache.end())
    {
        return cache[sig];
    }

    for (int i = 0; i < numLevels; i++)
    {
        if (done[i] == 0 && starsNeeded[i].second <= stars)
        {
            done[i] = 2;
            int ans = solve(starsNeeded, done, stars+2, cache);
            done[i] = 0;
            cache[sig] = ans + 1;
            return ans + 1;
        }
    }

    int minAnswer = 300000;
    for (int i = 0; i < numLevels; i++)
    {
        if (done[i] < 2 && starsNeeded[i].second <= stars)
        {
            int prevDone = done[i];
            int numStarsNow = stars+2-done[i];
            done[i] += 2;
            int ans = solve(starsNeeded, done, numStarsNow, cache);
            minAnswer = min(minAnswer, ans);
            done[i] = prevDone;
        }
        else if (done[i] < 1 && starsNeeded[i].first <= stars)
        {
            int prevDone = done[i];
            done[i] = 1;
            int ans = solve(starsNeeded, done, stars+1, cache);
            minAnswer = min(minAnswer, ans);
            done[i] = prevDone;
        }
    }
    if (minAnswer < 300000)
    {
        cache[sig] = minAnswer + 1;
        return minAnswer + 1;
    }
    else
    {
        cache[sig] = 300000;
        return 300000;
    }
}


int main()
{
    int T;
    cin >> T;

    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        int levels;
        cin >> levels;
        vector< pair<int, int> > starsNeeded(levels, make_pair(0, 0));
        for (int i = 0; i < levels; i++)
        {
            cin >> starsNeeded[i].first >> starsNeeded[i].second;
        }

        sort(starsNeeded.begin(), starsNeeded.end());

        for (int i = 0; i < levels; i++)
        {
        }

        vector<int> done(levels, 0);
        map<Long, int> cache;
        int answer = solve(starsNeeded, done, 0, cache);

        if (answer < 300000)
            cout << "Case #" << caseNum << ": " << answer << endl;
        else
            cout << "Case #" << caseNum << ": Too Bad" << endl;
    }

    return 0;
}
