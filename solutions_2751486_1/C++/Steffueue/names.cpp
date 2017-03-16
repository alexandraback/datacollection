#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

  set<char> vowels;
  vowels.insert('a');
  vowels.insert('e');
  vowels.insert('i');
  vowels.insert('o');
  vowels.insert('u');

  int T  = 0;
  cin >> T;
    for (int t = 0; t < T; t++) {
 
    string name;
    cin >> name;  
    long long N = 0;
    cin >> N;
    vector<long long> starts;

    long long n = 0;
    for (long long i = 0; i < name.size(); i++) {
      if (vowels.count(name[i]) == 0) {
        n++;
        if (n >= N) {
          int pos = i - N + 1;
          starts.push_back(pos);
        }
      } else {
        n = 0;
      }
    }

    long long nval = 0;
    long long startingAt = 0;
    for (vector<long long>::iterator it = starts.begin(); it != starts.end(); it++) {
      long long combBefore = ((*it) - startingAt) + 1;
      long long combAfter = name.size() - ((*it) + N) + 1;
      long long cnval = combAfter * combBefore;
      nval += cnval;
      startingAt = (*it) + 1;
    }

    cout << "Case #" << (t+1) << ": " << nval << endl;
  }
}
