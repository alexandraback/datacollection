// 2013 code jam round 1C Problem C
int verbose = 0 ;

#include <iostream>
using namespace std ;
#include <vector>
//#include <string>
//#include <map>
//#include <set>

int caseNumber;

int runTest() {
  int N;
  cin >> N ;
  vector<long long> d;
  vector<long long> n;
  vector<long long> w;
  vector<long long> e;
  vector<long long> s;
  vector<long long> dd;
  vector<long long> dp;
  vector<long long> ds;
  
  int i ;
  for (i = 0 ; i < N ; i++) {
    long long  i;
    cin >> i ;
    d.push_back(i);
    cin >> i ;
    n.push_back(i);
    cin >> i ;
    w.push_back(i);
    cin >> i ;
    e.push_back(i);
    cin >> i ;
    s.push_back(i);
    cin >> i ;
    dd.push_back(i);
    cin >> i ;
    dp.push_back(i);
    cin >> i ;
    ds.push_back(i);
  }
  long long wallarray[401] ;
  long long *wall = wallarray+200;
  long long newwallarray[401] ;
  long long *newwall = newwallarray+200;

  
  long long attacks = 0 ;
  for (i = -200 ; i<=200 ; i++) {
    wall[i] = 0 ;
    newwall[i] = 0 ;
  }
  
  while(1){
    long long day = *min_element(d.begin(), d.end()) ;
    if (day > 676060)
      break ;
  
    for (i = 0 ; i < N ; i++) {
      if (day == d[i]) {
        if (verbose) {
          cout << "Day " << day << " tribe " << i << " attacking, from " << w[i] << " to " << e[i] << " s " << s[i] << endl ;
        }
        long long p ;
        int success = 0 ;
        for (p = w[i]; p<= e[i] ; p++) {
          if (wall[p] < s[i]) {
            if (newwall[p]<s[i])
              newwall[p] = s[i] ;
            success=1 ;
          }
        }
        if (verbose) {
          if (success)
            cout << "Success!" << endl ;
        }
        attacks += success ;
        d[i] += dd[i] ;
        w[i] += dp[i] ;
        e[i] += dp[i] ;
        s[i] += ds[i] ;
        n[i] -- ;
        if (n[i]<= 0) {
          d[i] = 676061 ;
        }
      }
    }
    for (i = -200 ; i<=200 ; i++) {
      wall[i] = newwall[i] ;
      if (verbose && (i >= 0) && (i < 15))
        cout << " " << wall[i] ;
    }
    if (verbose)
      cout << endl ;
    
  }
  
  cout << "Case #" << caseNumber << ": " ;
  cout << attacks << endl ;
  
  return i;
}

int main (int argc, const char * argv[])
{
  int testCases ;
  cin >> testCases ;
  if (verbose) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  for (caseNumber=1 ; caseNumber <= testCases ; caseNumber++) {
    if (verbose)
      cout << "// Running case #" << caseNumber << endl ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  return 0;
}

