#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include<fstream>
#include<set>
using namespace std;
int main()
{
  int T,K,L,S;
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
    input >> K;
    input >> L;
    input >> S;
    keyboard.clear();
    seq.clear();
    notpossible = 0;
    expected =(long double)(S-L+1);
    for(j=0;j<K;j++) {
      input>> c;
      keyboard.push_back(c);
    }
    for (j = 0;j <L ; j++) {
      input >> c;
      seq.push_back(c);
      temp =0;
      for(vector<char>::iterator it = keyboard.begin();
	  it!= keyboard.end();
	  it++) {
	if (*it == c) {
	  temp++;
	}
      }
      expected = expected*((long double)temp/(long double)K);
      if (temp == 0) {
	notpossible = 1;
      }
    }
    int shift = 0;
    int best =L;
    bool contra;
    for(shift = L; shift != 0; shift--) {
      contra = 0; 
      for(j = 0; j < L -shift; j++) {
	if(seq[j] != seq[j+shift])
	  contra = 1;
      }
      if (contra == 0){
	best = min(best,shift);
      }
    }
    int max = 1 + (S - L)/best;
    if (notpossible == 1)
      max = 0;
    cout << best << " " << max << endl;
    output << "Case #"<< i+1 <<": ";
    if (expected < 0.00000001){
      expected = 0;
    }
    output << std::setprecision(9) << (long double)max - expected  << endl;
  }
  return 0;
}
