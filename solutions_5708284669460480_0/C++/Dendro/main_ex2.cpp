#include <iostream>
#include <random>
#include <time.h>
#include <limits>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;



class Instance{
public:
  void read();
  void write();

  void compute();
private:
 long long _n;
 vector< int > _K;
 vector< int > _L;
 vector< int > _S;
 vector<string> _keyboard;
 vector<string> _word;
 vector<long double> res;
};


void Instance::read()
{
  cin >> _n;

  for (long long i = 0; i < _n; ++i) {
    int inp ;
    cin >> inp;
    _K.push_back(inp);
    cin >> inp;
    _L.push_back(inp);
    cin >> inp;
    _S.push_back(inp);
    string ke;
    cin >> ke;
    _keyboard.push_back(ke);
    cin >> ke;
    _word.push_back(ke);

  }
}


void Instance::write()
{
   for (long long i = 0; i < _n; ++i) {
     cout << "Case #" << i+1 << ": " << setprecision(8) << res[i] << endl;
   }

}


int count_substrings(string & all, string & sub)
{
//cout << all  << " sub " << sub << endl;
   int num = 0;
   int last = all.find(sub);
   while (last != string::npos) {
    num++;
     last = all.find(sub, last+1);
   }
   return num;
}


int enumerate(string & nstr, string key, string & word, long long & sum_ban, long long &max_ban, int pos)
{
  if (pos >= nstr.length()) {
    int ban = count_substrings(nstr, word);
    sum_ban += ban;
    if (ban > max_ban) {
      max_ban = ban;
    }
    return 0;
  }
  for (int j = 0; j < key.length(); ++j){
    nstr[pos] = key[j];
    enumerate(nstr, key, word, sum_ban, max_ban, pos+1);
  }
  return 0;
}


void Instance::compute()
{
  for (int i = 0; i < _n; ++i){
    // First brute force
    int K = _K[i];
    int L = _L[i];
    int S = _S[i];
    string key = _keyboard[i];
    string word = _word[i];

    string nstr;
    long long num_words = 1;
    for (int i = 0; i < S; ++i) {
      nstr += "X";
      num_words *= key.length();
    }

    long long max_ban = 0;
    long long sum_ban = 0;
    enumerate(nstr, key, word, sum_ban, max_ban,0);

long double s = (long double) max_ban - ((long double) sum_ban/ (long double) num_words);
    res.push_back(s);
  }
}


int main(int argc, char** argv){
  Instance I;
  I.read();
  I.compute();
  I.write();
}
