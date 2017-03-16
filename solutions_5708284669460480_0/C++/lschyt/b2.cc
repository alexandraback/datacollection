#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int count_overlap(string target) {
  int overlap = 0;
  for (int i = target.length()-1; i >=1; --i) {
    string testtarget = target.substr(0,i);
    string targetsuffix = target.substr(target.length()-i,i);
    if (testtarget.compare(targetsuffix) == 0) {
      overlap = i;
      break;
    }
  }
  return overlap;
}
int count_max(string keyboard, string target, int outputlength) {
  if (outputlength<target.length())
    return 0;
  bool exist[128] = {false};
  for (int i = 0; i < keyboard.length(); ++ i) {
    exist[keyboard[i]] = true;
  }
  for (int i = 0; i < target.length(); ++i) {
    if (!exist[target[i]]) {
      return 0;
    }
  }
  int overlap = count_overlap(target);
  int remain = outputlength-target.length();
  return 1+(remain/(target.length() - overlap));
}
double check(string curr,string target) {
  //  cout << curr <<" " << target << endl;
  double ans = 0;
  for (int i = 0; i < curr.length()-target.length()+1; ++i) {
    if (curr.substr(i,target.length()).compare(target)==0){
      ans++;
    }
  }
  return ans;
}
double count_expected(string keyboard, string target, int outputlength, string curr) {
  if (curr.length()==outputlength) {
    return check(curr,target);
  }
  double ans = 0;
  for (int i = 0; i < keyboard.length(); ++i) {
    ans += count_expected(keyboard, target, outputlength, curr+keyboard[i]);
  }
  ans = ans/keyboard.length();
  return ans;
}
int main() {
  int t;
  cin >> t;
  for (int casecnt = 1; casecnt <= t; ++casecnt) {
    int k,l,s;
    cin >> k >> l >> s;
    string keyboard, target;
    cin >> keyboard >> target;
    int maxcnt = count_max(keyboard, target, s);
    double expected = count_expected(keyboard, target, s, "");
    //    cout << maxcnt <<" " << expected <<endl;
    cout << "Case #" << casecnt <<": " << fixed << setprecision(9)<< (maxcnt-expected)<< endl;
    
  }
}
