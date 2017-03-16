#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <queue>

using namespace std;

class Level
{
public:
   Level(istream& in)
   {
      in >> mOneStarDiff;
      in >> mTwoStarDiff;
   }

   bool operator<(const Level& other) const
   {
      return mTwoStarDiff > other.mTwoStarDiff;
   }

   int mOneStarDiff;
   int mTwoStarDiff;
};

typedef std::list<Level> LevelList;

class Game
{
public:
   Game(istream& in)
   {
      in >> mCount;
      for (int i = 0; i < mCount; i++) {
         mUnplayed.push_back(Level(in));
      }
      mUnplayed.sort();
   }

   std::string Test()
   {
      int count = 0;
      int stars = 0;
      while (!mUnfinished.empty() || !mUnplayed.empty()) {
         if (!mUnfinished.empty() && mUnfinished.top().mTwoStarDiff <= stars) {
            mUnfinished.pop();
            count ++;
            stars ++;
            continue;
         }
         if (!mUnplayed.empty()) {
            if (mUnplayed.back().mTwoStarDiff <= stars) {
               LevelList::iterator it = mUnplayed.end();
               it--;
               mUnplayed.erase(it);
               count ++;
               stars += 2;
               continue;
            }
            bool found = false;
            for(LevelList::iterator it = mUnplayed.begin(); it != mUnplayed.end(); it++) {
               if (it->mOneStarDiff <= stars) {
                  mUnfinished.push(*it);
                  mUnplayed.erase(it);
                  count ++;
                  stars ++;
                  found = true;
                  break;
               }
            }
            if (found) {
               continue;
            }
         }
         return "Too Bad";
      }
      ostringstream output;
      output << count;
      return output.str();
   }

   int mCount;
   LevelList mUnplayed;
   priority_queue<Level> mUnfinished;
};



int
main(int argc, char*argv[])
{
  int T;
  cin >> T;
  std::cout.precision(20);
  for (int i = 0; i < T; i++) {
    Game game(cin);
    cout << "Case #" << i + 1 << ": " << game.Test() << endl;
  }
}
