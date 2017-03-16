#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
	ifstream in(argv[1]);
	ofstream out("phone.out");
  int T;
  in >> T;
  for(int C=1; C<=T; C++){
    string S;
    in >> S;
    int letters[26] = {};
    int numbers[10] = {};
    for(int i=0; i<S.length(); i++){
      letters[S[i]-'A']++;
    }
    //ZERO SIX SEVEN FOUR TWO FIVE EIGHT THREE ONE  NINE
    int n = letters['X'-'A'];
    numbers[6] = n;
    letters['S'-'A'] -= n;
    letters['I'-'A'] -= n;
    letters['X'-'A'] -= n;
    n = letters['Z'-'A'];
    numbers[0] = n;
    letters['Z'-'A'] -= n;
    letters['E'-'A'] -= n;
    letters['R'-'A'] -= n;
    letters['O'-'A'] -= n;
    n = letters['S'-'A'];
    numbers[7] = n;
    letters['S'-'A'] -= n;
    letters['E'-'A'] -= n;
    letters['V'-'A'] -= n;
    letters['E'-'A'] -= n;
    letters['N'-'A'] -= n;
    n = letters['U'-'A'];
    numbers[4] = n;
    letters['F'-'A'] -= n;
    letters['O'-'A'] -= n;
    letters['U'-'A'] -= n;
    letters['R'-'A'] -= n;
    n = letters['W'-'A'];
    numbers[2] = n;
    letters['T'-'A'] -= n;
    letters['W'-'A'] -= n;
    letters['O'-'A'] -= n;
    n = letters['V'-'A'];
    numbers[5] = n;
    letters['F'-'A'] -= n;
    letters['I'-'A'] -= n;
    letters['V'-'A'] -= n;
    letters['E'-'A'] -= n;
    n = letters['G'-'A'];
    numbers[8] = n;
    letters['E'-'A'] -= n;
    letters['I'-'A'] -= n;
    letters['G'-'A'] -= n;
    letters['H'-'A'] -= n;
    letters['T'-'A'] -= n;
    n = letters['R'-'A'];
    numbers[3] = n;
    letters['T'-'A'] -= n;
    letters['H'-'A'] -= n;
    letters['R'-'A'] -= n;
    letters['E'-'A'] -= n;
    letters['E'-'A'] -= n;
    n = letters['O'-'A'];
    numbers[1] = n;
    letters['O'-'A'] -= n;
    letters['N'-'A'] -= n;
    letters['E'-'A'] -= n;
    n = letters['I'-'A'];
    numbers[9] = n;
    letters['N'-'A'] -= n;
    letters['I'-'A'] -= n;
    letters['N'-'A'] -= n;
    letters['E'-'A'] -= n;
    stringstream ss;
    for(int j=0; j<10; j++){
      for(int k=0; k<numbers[j]; k++){
        ss << j;
      }
    }
    out << "Case #" << C << ": " << ss.str() << endl;
  }
}
