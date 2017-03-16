#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Level {
    int a, b, starsObtained;
};

struct LevelsByOneStar {
    bool operator()(const Level& lhs, const Level& rhs)
    {
        if (lhs.a != rhs.a) return lhs.a < rhs.a;
        return lhs.b > rhs.b;
    }
};

struct LevelsByTwoStar {
    bool operator()(const Level* lhs, const Level* rhs)
    {
        return lhs->b < rhs->b;
    }
};

int levelsTilComplete(vector<Level>& levelsByStarOne,
                      vector<Level*>& levelsByStarTwo)
{
    int numStars = 0;
    int numLevelsCompleted = 0;
    int aptr = 0, bptr = 0;
    while(bptr < levelsByStarTwo.size())
    {
        if (numStars >= levelsByStarTwo[bptr]->b) {
            numStars += 2 - levelsByStarTwo[bptr]->starsObtained;
            levelsByStarTwo[bptr]->starsObtained = 2;
            ++bptr;
        } else if (aptr < levelsByStarOne.size()
                && levelsByStarOne[aptr].a <= numStars)
        {
            ++numStars;
            levelsByStarOne[aptr].starsObtained = 1;
            ++aptr;
        }
        else {
            return -1;
        }
        while(aptr < levelsByStarOne.size()
           && 0 < levelsByStarOne[aptr].starsObtained)
        {
            ++aptr;
        }
        ++numLevelsCompleted;
    }
    return numLevelsCompleted;
}

int main()
{
    int numTests;
    cin >> numTests;
    for(int currTest = 0; currTest < numTests; ++currTest)
    {
        int numLevels;
        cin >> numLevels;
        vector<Level> levels(numLevels);
        for (int i = 0; i < numLevels; ++i)
        {
            cin >> levels[i].a >> levels[i].b;
            levels[i].starsObtained = 0;
        }

        vector<Level*> level2(levels.size());
        for(int i = 0; i < level2.size(); ++i)
        {
            level2[i] = &levels[i];
        }

        sort(levels.begin(), levels.end(), LevelsByOneStar());
        sort(level2.begin(), level2.end(), LevelsByTwoStar());

        int numTries = levelsTilComplete(levels, level2);
        if(0 > numTries) {
            cout << "Case #" << currTest+1 << ": Too Bad" << endl;
        }else {
            cout << "Case #" << currTest+1 << ": " << numTries << endl;
        }
    }
}
