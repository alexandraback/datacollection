#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main() {

  int ncases;
  cin >> ncases;

  for (int i = 0; i < ncases; i++) {
    int keys, tlen, slen;
    cin >> keys >> tlen >> slen;
    string keyboard, target;
    cin >> keyboard;
    cin >> target;

    //frequency table for keyboard
    map<char, int> freq;
    for (int j = 0; j < keyboard.length(); j++) {
      char c = keyboard.at(j);
      if (freq.find(c) == freq.end()) freq[c] = 1;
      else freq[c] = freq[c]+1;
    }

    //make sure all needed letters are present
    bool present = true;
    for (int j = 0; j < target.length(); j++) {
      char c = target.at(j);
      if (freq.find(c) == freq.end()) {
        present = false;
        break;
      }
    }
    if (!present) {
      cout << "Case #" << i+1 << ": " << 0.0 << endl;
      continue;
    }
  
    //best monkey string
    int overlap = 0;
    for (int j = tlen-1; j > 0; j--) {
      if (target.substr(0, j) == target.substr(tlen-j)) {
        overlap = j;
        break;
      }
    }
    //cout << overlap << endl;

    string bmstr = target;  
    for (int j = tlen; j < slen; j += tlen-overlap) {
      if (slen-j > tlen-overlap) bmstr += target.substr(overlap);
      else bmstr += target.substr(overlap, slen-j);
    }
    
    int max_count = 0;
    size_t pos = 0;
    while (true) {
      size_t found = bmstr.find(target, pos); 
      pos = found+1;
      if (found == string::npos) break;
      max_count++;
    }
    //cout << target << endl;
    //cout << bmstr << endl;
    //cout << "count: " << max_count << " len: " << slen;

    //probability of target in tlen letters
    double pr = 1;
    for (int j = 0; j < tlen; j++) {
      char c = target.at(j);
      pr *= (double)freq[c] / (double)keys;
    }

    double num_occ = (double)(slen-tlen+1)*pr;
    cout << "Case #" << i+1 << ": " << ((double)max_count) - num_occ << endl;

  }
  return 0;
}
