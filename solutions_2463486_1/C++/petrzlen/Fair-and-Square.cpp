#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <cmath> 

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)
typedef long long int LLI; 

string toDigits(LLI n){
  string result;
  while(n>0){
    result += (char)('0' + (n%10)); 
    n /= 10; 
  }
  reverse(result.begin(), result.end());
  return result; 
}

bool isPalindrome(LLI n){
  string D = toDigits(n); 
  REP(i, D.size()/2) if(D[i] != D[D.size()-1-i]) return false;
  return true; 
}

struct classcomp{
  bool operator() (const string& s1, const string& s2) const{
    if(s1.size() != s2.size()) return s1.size() < s2.size(); 
    return s1 < s2; 
  }
};

int main()
{
  map<string, int, classcomp> M;
  
    int id=1; 
    for(LLI s=1 ; s <= 12345678 ; s++){
      if(isPalindrome(s) && isPalindrome(s*s)){
        M[toDigits(s*s)]=id++;
        //cout << s << "=>" << s*s << endl;
      }
    }
    
  M["12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890"]=id++; 

  int T;
  cin >> T;
  REP(t, T){
    string A, B;
    cin >> A >> B;
    cout << "Case #" << t+1 << ": " << M.upper_bound(B)->second - M.lower_bound(A)->second << endl;
  } 

	return 0;
}
