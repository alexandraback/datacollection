#include <iostream>
#include <deque>
#include <algorithm>
#include <limits>
using namespace std;

struct Level
{
  int oneStar;
  int twoStars;
};

bool levelCompare(Level A, Level B)
{
  if (A.twoStars == B.twoStars)
    return (A.oneStar > B.oneStar);
  return (A.twoStars < B.twoStars);
}

int main()
{
  int cases = 0;
  cin >> cases;
  for (int i = 1; i <= cases; i++)
  {
    cout << "Case #" << i << ": ";
    int levelCount = 0;
    cin >> levelCount;
    int levelRuns = 0; // this is the number of levels needed
    Level level;
    deque<Level> game;
    for (int j = 1; j <= levelCount; j++)
    {
      cin >> level.oneStar;
      cin >> level.twoStars;
      game.push_back(level);
    }
    sort(game.begin(), game.end(), levelCompare);
    int stars = 0;
    while (game.size() > 0)
    {
      if (game.at(0).twoStars <= stars)
      {
        if (game.at(0).oneStar < numeric_limits<int>::max())
          stars += 2;
        else
          stars += 1;
        levelRuns++;
        game.pop_front();
      }
      else
      {
        int k = game.size() - 1;
        while (k >= 0)
        {
          if (game.at(k).oneStar <= stars)
          {
            stars += 1;
            levelRuns++;
            game.at(k).oneStar = numeric_limits<int>::max();
            break; // while k >= 0
          }
          k--;
        }
        if (k < 0)
        {
          cout << "Too Bad" << endl;
          break; // while game.size > 0
        }
      }
    } // while game.size > 0
    if (game.size() == 0)
      cout << levelRuns << endl;
  } // cases for loop
  return 0;
}

