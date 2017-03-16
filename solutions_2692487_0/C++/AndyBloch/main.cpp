// 2013 code jam round 1B Problem A
int verbose = 0 ;

#include <iostream>
using namespace std ;
#include <vector>
#include <deque>
//#include <string>
//#include <map>
//#include <set>

int caseNumber;

void display(long long A, deque<long long> m) {
  cout << "A = " << A << " |" ;
  int i;
  for (i = 0 ; i < m.size() ; i++){
    cout << " " << m[i];
  }
  cout << endl ;
}

long long solve(long long A, long long N, deque<long long> m) {
  while ((N>0) && (A > m[0])) {
    A += m[0] ;
    m.pop_front();
    N--;
  }
  long long best = N ;
  if (best <= 1) {
    return best ;
  }
  int i ;
  for (i = 1 ; i < N ; i++) {
    A += A-1;
    while (m.size() && (A > m[0])) {
      A += m[0] ;
      m.pop_front();
    }
    long long totalMoves = i + m.size() ;
    if (totalMoves < best)
      best = totalMoves ;
    if (m.size() <= 1)
      break ;
  }
  
  return best ;
}

int runTest() {
  deque<long long> m;
  long long A, N;
  cin >> A >> N ;
  long long i ;
  for (i = 0 ; i < N ; i++){
    long long mm ;
    cin >> mm ;
    m.push_back(mm);
  }
  
  sort(m.begin(),m.end());
  if (verbose) {
    for (i = 0 ; i < N ; i++){
      cout << " " << m[i];
    }
    cout << endl ;
  }
  
  
  cout << "Case #" << caseNumber << ": " ;
  cout << solve(A, N, m) << endl ;
  
  return 1;
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

