#include <iostream>
#include <list>
#include <set>

using namespace std;

int t = 0, n = 0;
set<double> blocksOfNaomi, blocksOfKen;

int PointWhenDeceitfulWarPlayed() {
  list<double> copiedBlocksOfKen;
  int point = 0;

  for (set<double>::iterator blockK = blocksOfKen.begin(); blockK != blocksOfKen.end(); ++blockK) {
    copiedBlocksOfKen.push_back(*blockK);
  }

  for (set<double>::iterator blockN = blocksOfNaomi.begin(); blockN != blocksOfNaomi.end(); ++blockN) {
    if (*blockN < copiedBlocksOfKen.front()) {
      copiedBlocksOfKen.pop_back();
    } else {
      point++;
      copiedBlocksOfKen.pop_front();
    }
  }

  return point;
}

int PointWhenWarPlayed() {
  set<double> copiedBlocksOfKen = blocksOfKen;
  int point = 0;

  for (set<double>::iterator blockN = blocksOfNaomi.begin(); blockN != blocksOfNaomi.end(); ++blockN) {
    bool kenGotPoint = false;

    for (set<double>::iterator blockK = copiedBlocksOfKen.begin(); blockK != copiedBlocksOfKen.end(); ++blockK) {
      if (*blockK > *blockN) {
        copiedBlocksOfKen.erase(blockK);
        kenGotPoint = true;
        break;
      }
    }

    if (!kenGotPoint) {
      point++;
      copiedBlocksOfKen.erase(copiedBlocksOfKen.begin());
    }
  }

  return point;
}

int main() {
  cin >> t;

  for (int caseNum = 1; caseNum <= t; ++caseNum) {
    blocksOfNaomi.clear();
    blocksOfKen.clear();

    cin >> n;

    for (int i = 0; i < n; ++i) {
      double massOfBlock;

      cin >> massOfBlock;
      blocksOfNaomi.insert(massOfBlock);
    }

    for (int i = 0; i < n; ++i) {
      double massOfBlock;

      cin >> massOfBlock;
      blocksOfKen.insert(massOfBlock);
    }

    cout << "Case #" << caseNum << ": " << PointWhenDeceitfulWarPlayed() << " " << PointWhenWarPlayed() << endl;
  }

  return 0;
}

