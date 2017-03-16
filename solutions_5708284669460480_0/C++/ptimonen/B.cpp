#include<bits/stdc++.h>
using namespace std;

const int LETTERS = 'Z' - 'A' + 1;
string tar;
string kb;
int l;
int nul;
int maxNum = 0;
double expected = 0;

void create(string s, double prob) {
  //cout << s.size() << " " <<  l << "\n";
  if(s.size() == l) {
    int num = 0;
    for(int a = 0; a <= s.size() - tar.size(); ++a) {
      for(int b = 0; b <= tar.size(); ++b) {
	if(b == tar.size()) {
	  ++num;
	} else if(s[a + b] != tar[b]) {
	  //cout << s[a + b] << " " << tar[b] << "\n";
	  break;
	}
      }
    }
    expected += num * prob; 
    maxNum = max(maxNum, num);
    return;
  }
  double chance = 1.0 / kb.size();
  for(char c : kb) {
    create(s + c, prob * chance);
  }
}

int main() {
  int t;
  cin >> t;
  for(int test = 1; test <= t; ++test) {
    maxNum = 0;
    expected = 0;
    cin >> nul >> nul >> l;
    cin >> kb >> tar;
    create("", 1.0);
    double ans = 0;
    printf("Case #%d: %.16f\n", test, maxNum - expected);
  }
  return 0;
}
