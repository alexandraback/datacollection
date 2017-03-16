#include <fstream>
#include <iostream>

int main()
{
  std::ifstream Input("A-large-0.in");
  size_t T;
  Input>>T;

  std::ofstream Output("A-large-0.out");
  Output.precision(15);
  for(size_t i = 1; i <= T; i++) {
    size_t A,B;
    Input >> A >> B;

    double BestExp = 2+B; // give up
    double CumProb = 1;
    for(int numdel = A-1; numdel >= 0; numdel--) {
      double NextProb;
      Input >> NextProb;
      CumProb *= NextProb;
      double ExpHere = (B-A+1+2*numdel);
      ExpHere += (1.0-CumProb)*(B+1);
      if(ExpHere < BestExp) BestExp = ExpHere;
    }
    Output << "Case #" << i << ": " << BestExp <<std::endl;
  }
  Output.close();
}
