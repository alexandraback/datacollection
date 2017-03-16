#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

struct Contestant
{
  unsigned short Points;
  size_t position;
  double VotingYield;
  Contestant() {Points = 0; position = 0; VotingYield = 0.0;}
};

bool ComparePoints(const Contestant& cont1, const Contestant& cont2) {return cont1.Points < cont2.Points;}
bool ComparePosition(const Contestant& cont1, const Contestant& cont2) {return cont1.position < cont2.position;}

int main()
{
  std::ifstream Input("A-small-0.in");
  size_t T;
  Input >> T;
  std::ofstream Output("A-small-0.out");
  for(size_t i = 1; i <= T; i++) {
    size_t N;
    Input >> N;
    std::vector<Contestant> contestants;
    unsigned short TotalPoints = 0;
    for(size_t  j = 0; j < N; j++) {
      Contestant aCont;
      aCont.position = j;
      Input >> aCont.Points;
      TotalPoints += aCont.Points;
      contestants.push_back(aCont);
    }
    std::sort(contestants.begin(), contestants.end(), ComparePoints);
    double VotesAllocated = 0.0;
    size_t NextCont = 0;
    while(NextCont+1 < contestants.size()) {
      unsigned short pointThreshold = contestants[NextCont].Points;
      while(NextCont+1 < contestants.size() and contestants[NextCont+1].Points == pointThreshold) {
        NextCont++;
      }
      if(NextCont+1 == contestants.size()) break;
      if(VotesAllocated + double(NextCont+1)*(contestants[NextCont+1].Points - contestants[NextCont].Points)/TotalPoints > 1.0) {
        double VotesLeft = (1.0 - VotesAllocated)/(NextCont+1);
        for(size_t icont = 0; icont <= NextCont; icont++) contestants[icont].VotingYield += VotesLeft;
        VotesAllocated = 1.0;
        break;
      }
      double VotesToAllocate = double(contestants[NextCont+1].Points - contestants[NextCont].Points)/TotalPoints;
      for(size_t icont = 0; icont <= NextCont; icont++) contestants[icont].VotingYield += VotesToAllocate;
      VotesAllocated += VotesToAllocate * (NextCont+1);
      NextCont++;
    }

    if(VotesAllocated < 1.0) {
      for(size_t icont = 0; icont < contestants.size(); icont++) contestants[icont].VotingYield += (1.0-VotesAllocated)/contestants.size();
    }

    std::sort(contestants.begin(), contestants.end(), ComparePosition);
    Output << "Case #" << i << ": ";
    Output.setf(std::ios::fixed,std::ios::floatfield);
    Output.precision(8);
    for(size_t icont = 0; icont < contestants.size(); icont++) {
      Output << 100.0*contestants[icont].VotingYield << " ";
    }
    Output << std::endl;
  }
  Output.close();
}
