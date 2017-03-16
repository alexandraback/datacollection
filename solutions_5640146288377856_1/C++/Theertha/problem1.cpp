#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include<fstream>
#include<set>
using namespace std;
int main()
{
  int T,R,C,W;
  set<int> denominations;
  vector<int> current;
  vector<char> keyboard;
  vector<char> seq;
  int i,j,k,l,m,temp;
  long double expected;
  char c;
  int add,index;
   ifstream input;
  ofstream output;
  bool notpossible;
  input.open("C.in");
  output.open("bout.txt");
  input >> T;
  for(i=0;i<T;i++) {
    input >> R;
    input >> C;
    input >> W;
    int checking = C/W;
    output << "Case #"<< i+1 <<": ";
    output <<  checking*(R-1)+ W + (C-1)/W  << endl;
  }
  return 0;
}
