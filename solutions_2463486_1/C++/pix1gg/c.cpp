#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct Big : public vector<long>{
  Big() : vector<long> (){
  }
  Big(size_t n) : vector<long> (n){
  }
  Big(const Big & big) : vector<long> (big){
  }
  Big(const string & str) {
    for (int i=0; i<str.size(); i++) {
      push_back(str[i]-'0');
    }
    tight();
  }

  void tight() {
    vector<long>::iterator it = begin();
    while (it != end()) {
      if (*it != 0) {
        break;
      }
      it++;
    }
    erase(begin(), it);
    if (0 == size()) {
      push_back(0);
    }
  }

  Big square() {
    Big s;
    for (int i=0; i<size()*2; i++) {
      s.push_back(0);
    }
    int high = size() * 2 - 1;
    for (int i=0; i<size(); i++) {
      for (int j=0; j<size(); j++) {
        s[i+j+1] += (*this)[i] * (*this)[j];
      }
    }
    for (int i=size() * 2 - 1; i>0; i--) {
      s[i-1] += s[i] / 10;
      s[i] %= 10;
    }

    s.tight();
    return s;
  }

  bool fair() {
    for (int i=0; i<size()/2; i++) {
      if ((*this)[i] != (*this)[size()-i-1]) {
        return false;
      }
    }
    return true;
  }

  string str() {
    string res;
    for (vector<long>::iterator it = begin(); it != end(); it++) {
      res += *it + '0';
    }
    return res;
  }
};

bool operator<(const Big & a, const Big & b) {
  if (a.size() < b.size()) {
    return true;
  } else if (a.size() > b.size()) {
    return false;
  }

  for (int i=0; i<a.size(); i++) {
    if (a[i] < b[i]) {
      return true;
    } else if (a[i] > b[i]) {
      return false;
    }
  }
  return false;
}

void get_fairs(int n, vector<Big> & fairs) {
  for (int i=0; i<10; i++) {
    Big fair(n);
    fair[0] = fair[n-1] = i;

    if (n <= 2) {
      fairs.push_back(fair);
      continue;
    }

    vector<Big> sub_fairs;
    get_fairs(n-2, sub_fairs);
    for (int j=0; j<sub_fairs.size(); j++) {
      for (int k=0; k<n-2; k++) {
        fair[k+1] = sub_fairs[j][k];
      }
      fairs.push_back(fair);
    }
  }
}



int main(int argc, char * argv[]) {
  int T;
  string A, B;
  cin >> T;

  for (int i=1; i<=T; i++) {
    cin >> A >> B;
    Big a(A);
    Big b(B);
    //cout << a.str() << '\t' << a.size() << endl;
    //cout << b.str() << '\t' << b.size() << endl;
    
    int count = 0;
    bool flag = true;
    for (int n=(a.size()+1)/2; flag && n<=b.size(); n++) {
      vector<Big> fairs;
      get_fairs(n, fairs);
      for (int j=0; j<fairs.size(); j++) {
        if (fairs[j][0] == 0) {
          continue;
        }
        //cout << fairs[j].str() << endl;
        Big s = fairs[j].square();
        if (s < a) {
          continue;
        } 
        if (b < s) {
          flag = false;
          break;
        }
        if (s.fair()) {
          count++;
        }
      }
    }
    cout << "Case #" << i << ": " << count << endl;
  }

  return 0;
}
