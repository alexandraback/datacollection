// round1A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>

using namespace std;

bool all_true(std::vector<bool> const& vec)
{
    bool bAllTrue(true);
    for (unsigned i = 0; i < vec.size(); ++i)
    {
        bAllTrue = bAllTrue && vec[i];
    }
    return bAllTrue;
}

unsigned V(
    vector<bool> completed_1,
    vector<bool> completed_2, 
    vector<unsigned> const& a_i,
    vector<unsigned> const& b_i,
    unsigned nStars,
    unsigned nLevels
)
{
    unsigned nGames(0);
        foo:
            // First complete the 2-star ones if we can
            for (unsigned iLevel = 0; iLevel < nLevels; ++iLevel)
            {
                if (!completed_2[iLevel] && nStars >= b_i[iLevel])
                {
                    completed_1[iLevel] = true;
                    completed_2[iLevel] = true;
                    nStars += 2;
                    nGames += 1;
                    // start again
                    goto foo;
                }
            }

            if (all_true(completed_2))
                return nGames;

            std::vector<bool> new_completed_1 = completed_1;
            int nMinSubGames(-1);
            for (unsigned iLevel = 0; iLevel < nLevels; ++iLevel)
            {
                if (!completed_1[iLevel] && a_i[iLevel] <= nStars)
                {
                    new_completed_1[iLevel] = true;
                    int nSubGames = V(new_completed_1, completed_2, a_i, b_i, nStars+1,nLevels);
                    if (nSubGames != -1 && (nSubGames <= nMinSubGames || nMinSubGames == -1))
                    {
                        nMinSubGames = nSubGames;
                    }
                    new_completed_1[iLevel] = false;
                }
            }
            if (nMinSubGames == -1)
                return -1;

            nGames += nMinSubGames;

        return nGames;
}

int main (int argc, char *argv[])
{
    unsigned nCases;
    cin >> nCases;
    for (unsigned iCase = 1; iCase <= nCases; ++iCase)
    {
        unsigned nLevels;
        cin >> nLevels;
        std::vector<unsigned> a_i(nLevels, 0);
        std::vector<unsigned> b_i(nLevels, 0);
        for (unsigned iLevel = 0; iLevel < nLevels; ++iLevel)
        {
            cin >> a_i[iLevel];
            cin >> b_i[iLevel];
        }
        std::vector<bool> completed_1(nLevels, false);
        std::vector<bool> completed_2(nLevels, false);
        unsigned nStars = 0;
        unsigned nGames = 0;
        while (nStars < 2*nLevels)
        {
        foo:
            // First complete the 2-star ones if we can
            for (unsigned iLevel = 0; iLevel < nLevels; ++iLevel)
            {
                if (!completed_2[iLevel] && nStars >= b_i[iLevel])
                {
                    if (completed_1[iLevel])
                        nStars += 1;
                    else
                        nStars += 2;

                    completed_1[iLevel] = true;
                    completed_2[iLevel] = true;
                    nGames += 1;
                    // start again
                    goto foo;
                }
            }

            if (all_true(completed_2))
            {
                if (nStars != 2*nLevels)
                    std::cerr << "unexpected error - " << nStars << std::endl;
                break;
            }

            // Find an uncompleted 1-star level we can complete with highest 2-star
            unsigned idx(nLevels);
            int max_b(0);
            for (unsigned iLevel = 0; iLevel < nLevels; ++iLevel)
            {
                if (!completed_1[iLevel] && a_i[iLevel] <= nStars && b_i[iLevel] >= max_b)
                {
                    idx = iLevel;
                    max_b = b_i[iLevel];
                }
            }
            if (idx == nLevels)
            {
                // Can't do anything
                break;
            }
            else
            {
                completed_1[idx] = true;
                nStars += 1;
                nGames += 1;
            }
        }
        if (!all_true(completed_2))
        {
            std::cout << "Case #" << iCase << ": " << "Too Bad" << std::endl;
        }
        else
        {
            if (nStars != 2*nLevels)
                std::cerr << "unexpected error" << std::endl;
            std::cout << "Case #" << iCase << ": " << nGames << std::endl;
        }

        /*
        completed_1.assign(nLevels, false);
        completed_2.assign(nLevels, false);
        nStars = 0;
        nGames = V(completed_1, completed_2, a_i, b_i, nStars, nLevels);
        if (nGames == -1)
        {
            std::cout << "Case #" << iCase << ": " << "Too Bad" << std::endl;
        }
        else
        {
            std::cout << "Case #" << iCase << ": " << nGames << std::endl;
        }
        */
    }
	return 0;
}

