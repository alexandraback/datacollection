
#include <cassert>
#include <cstdio>
#include <vector>
#include <set>
#include <unordered_set>

class Chest
{
public:

  int mKeyTypeToOpen;

  std::vector<int> mKeyTypesInside;

  Chest *mNextUnopenedChest;

};

int numKeys[200];
int numChests;
Chest chests[200];

int chestOpenOrder[200];
int numOpenedChests;

Chest *firstUnopenedChest;

int openedChests;

std::vector<char> seenOpenedChestses;

bool openNextChest()
{
  if(openedChests < seenOpenedChestses.size())
  {
    //TODO: if we have seen a (set of opened chests, number of keys) tuple that dominates the current one, die
    if(seenOpenedChestses[openedChests])
    {
      //we've seen the same set of opened chests before
      return false;
    }
    seenOpenedChestses[openedChests] = true;
  }

  if(firstUnopenedChest == nullptr)
  {
    return true;
  }

  Chest **prevsNextLink = &firstUnopenedChest;
  for(Chest *chest = firstUnopenedChest; chest != nullptr; prevsNextLink = &chest->mNextUnopenedChest, chest = chest->mNextUnopenedChest)
  {
    if(numKeys[chest->mKeyTypeToOpen] > 0)
    {
      --numKeys[chest->mKeyTypeToOpen];
      for(auto i : chest->mKeyTypesInside)
      {
        ++numKeys[i];
      }
      chestOpenOrder[numOpenedChests] = chest - chests;
      ++numOpenedChests;
      *prevsNextLink = chest->mNextUnopenedChest;
      openedChests |= (1 << (chest - chests));

      if(openNextChest())
      {
        return true;
      }

      openedChests &= ~(1 << (chest - chests));
      *prevsNextLink = chest;
      --numOpenedChests;
      for(auto i : chest->mKeyTypesInside)
      {
        --numKeys[i];
      }
      ++numKeys[chest->mKeyTypeToOpen];
    }
  }

  return false;
}

int main()
{
  int t;
  std::scanf("%d", &t);
  for(int tt = 0; tt < t; ++tt)
  {
    int numStartingKeys;
    std::scanf("%d %d", &numStartingKeys, &numChests);

    std::uninitialized_fill_n(numKeys, sizeof(numKeys) / sizeof(numKeys[0]), 0);
    for(int i = 0; i < numStartingKeys; ++i)
    {
      int keyType;
      std::scanf("%d", &keyType);
      ++numKeys[keyType - 1];
    }

    numOpenedChests = 0;
    firstUnopenedChest = &chests[0];
    for(int i = 0; i < numChests; ++i)
    {
      if(i == numChests - 1)
      {
        chests[i].mNextUnopenedChest = nullptr;
      }
      else
      {
        chests[i].mNextUnopenedChest = &chests[i + 1];
      }

      int keyTypeToOpen;
      int numKeysInside;
      std::scanf("%d %d", &keyTypeToOpen, &numKeysInside);
      chests[i].mKeyTypeToOpen = keyTypeToOpen - 1;

      chests[i].mKeyTypesInside.clear();
      for(int j = 0; j < numKeysInside; ++j)
      {
        int keyType;
        std::scanf("%d", &keyType);
        chests[i].mKeyTypesInside.push_back(keyType - 1);
      }
    }

    std::printf("Case #%d:", tt + 1);

    seenOpenedChestses.clear();
    seenOpenedChestses.resize(1 << 20);
    openedChests = 0;
    if(openNextChest())
    {
      assert(numOpenedChests == numChests);
      for(int i = 0; i < numChests; ++i)
      {
        std::printf(" %d", chestOpenOrder[i] + 1);
      }
    }
    else
    {
      std::printf(" IMPOSSIBLE");
    }

    std::printf("\n");

    std::fflush(stdout);
  }

  //std::system("pause");
}
