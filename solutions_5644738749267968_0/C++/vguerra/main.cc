// Victor Guerra <vguerra@gmail.com>
// 2014-04-13

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;

    vector<double> NaoBlocks(N, 0);
    vector<double> KenBlocks(N, 0);
    for (int i = 0; i < N; ++i) {
      cin >> NaoBlocks[i];
    }
    for (int i = 0; i < N; ++i) {
      cin >> KenBlocks[i];
    }

    sort(NaoBlocks.begin(), NaoBlocks.end());
    sort(KenBlocks.begin(), KenBlocks.end());

    vector<double> copyKenBlocks(KenBlocks);
    vector<double> copyNaoBlocks(NaoBlocks);


    int NaoPointsWar = 0;
    int NaoPointsDWar = 0;
    for (int step = 0; step < N; ++step) {
      double NaoBlock = NaoBlocks[step];

      // Playing War
      vector<double>::iterator kenPos =
          std::upper_bound(KenBlocks.begin(), KenBlocks.end(), NaoBlock);
      if (kenPos == KenBlocks.end()) {
        kenPos = KenBlocks.end() - 1;
      }
      if (NaoBlock > *kenPos) ++NaoPointsWar;
      KenBlocks.erase(kenPos);

      // Playing Deceitful War
      vector<double>::iterator naoPos = copyNaoBlocks.end() - 1;
      kenPos = copyKenBlocks.end() - 1;
      if (*naoPos > *kenPos) {
        ++NaoPointsDWar;
      } else {
        naoPos = copyNaoBlocks.begin();    
        if (*naoPos > *kenPos) ++NaoPointsDWar;
      }
      copyKenBlocks.erase(kenPos);
      copyNaoBlocks.erase(naoPos);
    }
    cout << "Case #" << t << ": " << NaoPointsDWar << " " << NaoPointsWar
         << "\n";
  }
  return 0;
}
