#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 
typedef pair<int, int> PII; 

bool is_c(char c){
  return !(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); 
}

int main()
{
  int T; 
  cin >> T;
  REP(t, T){
    string s; 
    int n;
    cin >> s >> n; 
    
    int cc=0; 
    LLI min_start = 0; 
    LLI max_start = 0;
    LLI min_end = 0; 
    LLI result = 0;
    
    while(min_end < s.size()){
      while(min_end < s.size() && cc < n){
        cc += is_c(s[min_end]); 
        min_end++; 
      }
      //precondition: count of consonants in [max_start, min_end) is cc
      while(max_start < min_end && !is_c(s[max_start])){
        max_start++; 
      }
      
      //precondition: is_c(s[max_start])
      if(cc == n && min_end-max_start == n){
        //cout << "(" << min_start << "," << max_start << ") " << min_end; 
        result += (max_start - min_start + 1) * (s.size() - min_end + 1); 
        max_start++; 
        cc--;
        min_start = max_start;
      }
      else{
        max_start++; 
        cc--; 
      }
    }
    
    cout << "Case #"<<t+1<<": " << result << endl;
  }
	return 0;
}
