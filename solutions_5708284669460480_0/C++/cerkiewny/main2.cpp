#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>

using namespace std;

int chars[26];
char word[100];

double countprop(int len, int total){
  double res = 1.0;
  for(int i = 0; i < len; i++){
     res *= (double)chars[word[i] - 'A'] / total;
  }
  return res;
}

bool checkpos(int l){
  for(int i = 0; i < l; i++){
    if (chars[word[i] - 'A'] == 0){
      return false; 
    }
  }
  return true;
}

int countcomp(int l){
  for(int i = 1; i < l; i++){
    bool res = true;
    for(int j = 0; j < l; j++){
      if(word[j] != word[(j + i) % l]){
        res = false;
      }
    }
    if (res)
      return i;
  }
  return l;
}

int main(){

  ifstream in ("in");
  ofstream out ("out");

  int ncases;

  in >> ncases;

  for(int i = 0; i < ncases; i++){
    double res;
    for(int j = 0; j < 26; j++){
      chars[j] = 0;
    }


    int k, l, s;

    in >> k >> l >> s;

    for(int j = 0; j < k; j++){
       char tmp;
       in >> tmp;
       chars[tmp - 'A']++;
    }

    for(int j = 0; j < l; j++){
       in >> word[j];
       cout << word[j];
    }

    int compneed = countcomp(l);
    cout << compneed << endl;
    if (checkpos(l) && l <= s){
      cout << "possible" << endl;
      int maxocur = 1 + (s - l) / compneed;
      double teilprop = countprop(compneed, k);
      double wholeprop = countprop(l, k);
      double expect = 0.0;
      cout << wholeprop << endl;
      cout << teilprop << endl;
      if(compneed == 1 && wholeprop == 1.0){
        expect = (double)maxocur;
      }
      else{
        for (int j = 0; j < maxocur; j++){
            expect += wholeprop * pow(teilprop, j) * ( j + 1 );
            cout << "exp" << expect << endl;
        }
      }
      res = (double)maxocur - expect;
      cout << maxocur << endl << endl;
    }
    else{
      res = 0.0;
    }

    cout << res << endl;
    out << setprecision(9) << "Case #" << i + 1 << ": " << res << endl;

  }

  return 0;

}
