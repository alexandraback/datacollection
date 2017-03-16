#include <iostream>
#include <algorithm>

std::vector<unsigned int> motes;
unsigned int bestScore;

unsigned int solve()
{
    unsigned int mySize, moteCount;

    std::cin >> mySize >> moteCount;
    motes.resize(moteCount);

    for(unsigned int& mote : motes)
    {
        std::cin >> mote;
    }
    std::sort(motes.begin(), motes.end());

    bestScore = moteCount;

    for(unsigned int eat = 0; eat <= moteCount; eat++)
    {
        unsigned int currSize = mySize;
        unsigned int score = moteCount - eat;

        for(unsigned int i = 0; i < eat; i++)
        {
            while(currSize <= motes[i])
            {
                if(currSize == 1)
                {
                    score = bestScore;
                    goto gameover;
                }

                currSize += currSize - 1;
                score++;
            }

            currSize += motes[i];
        }

        gameover:

        bestScore = std::min(score, bestScore);
    }

    return bestScore;
}

int main()
{
    unsigned int caseCount;
    std::cin >> caseCount;

    for(unsigned int i = 1; i <= caseCount; i++)
    {
        std::cout << "Case #" << i << ": " << solve() << std::endl;
    }

    return 0;
}
