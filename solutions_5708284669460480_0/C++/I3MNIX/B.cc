#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
const double EPS = 1e-8;

int K, L, S;
string type, target;
long long total;
long long index;
int max_b;
vector <int> letters;

void cnt(string str){
  int res = 0;
  for (int i = 0; i <= (S-L); i++){
    string tmp = string(str.begin() + i, str.begin() + i + L);
    if (tmp == target) res++;
  }
  total += res;
  max_b = max(max_b, res);
  index++;
}

void gen_strings(string str){
  int sz = (int) str.length();
  if (sz >= S) {
    cnt(str);
    return;
  }
  for (int i = 0; i < K; i++){
    string tmp = str;
    tmp += type[i];
    gen_strings(tmp);;
  }
}

double solve(){
  for (int i = 0; i < L; i++){
    int c = (int) target[i] - 'A';
    if (letters[c] == 0) return 0.0;
  }
  index = 0;
  total = 0;
  max_b = 0;
  string tmp = "";
  gen_strings(tmp);
  double ans = (double) (max_b * index) - (total);
  ans /= double(index);
  return ans;
}

int main(){
  int t;
  cin >> t;
  for (int idx = 1; idx <= t; idx++){
    letters.assign(30, 0);
    cout << "Case #" << idx << ": ";
    cin >> K >> L >> S;
    cin >> type >> target;
    for (int i = 0; i < K; i++){
      int c = (int) type[i] - 'A';
      letters[c]++;
    }
    cout << fixed;
    cout << setprecision(10) << solve() << endl;
  }


  return 0;
}
