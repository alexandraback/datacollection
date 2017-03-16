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
    int N = 0;
    cin >> N;
    vector<int> starts;

    int n = 0;
    for (int i = 0; i < name.size(); i++) {
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

    int nval = 0;
    int startingAt = 0;
    for (vector<int>::iterator it = starts.begin(); it != starts.end(); it++) {
      int combBefore = ((*it) - startingAt) + 1;
      int combAfter = name.size() - ((*it) + N) + 1;
//      cout << "letters before n-consequtive consunant (starting at: " << startingAt << "): " << combBefore << endl;
//      cout << "letters after n-consequtive consunant: " << combAfter << endl;
      int cnval = combAfter * combBefore;
//      cout << "current nval: " << cnval << endl;
      nval += cnval;
      startingAt = (*it) + 1;
    }

    cout << "Case #" << (t+1) << ": " << nval << endl;
  }
}
