#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Password
{
public:
   Password(istream& in)
   {
      in >> mA;
      in >> mB;
      for (int i = 0; i < mA; i++) {
         double prob;
         in >> prob;
         mProbs.push_back(prob);
      }
   }

   double Test()
   {
      double bestChoice = mB + 2;
      double probabilityCorrect = 1.0;
      for (int kept = 0; kept <= mA; kept++) {
         double choice = (mA - kept + mB - kept + 1) + (mB + 1) * (1 - probabilityCorrect);
         if (choice < bestChoice) {
            bestChoice = choice;
         }
         if (kept < mA) {
            probabilityCorrect *= mProbs[kept];
         }
      }
      return bestChoice;
   }

   int mA;
   int mB;
   std::vector<double> mProbs;
};



int
main(int argc, char*argv[])
{
  int T;
  cin >> T;
  std::cout.precision(20);
  for (int i = 0; i < T; i++) {
    Password password(cin);
    cout << "Case #" << i + 1 << ": " << password.Test() << endl;
  }
}
