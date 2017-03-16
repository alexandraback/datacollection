#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// int palindromes: e.g. 6 11 121
// fair and square number
// = palindrome & square of a palindrome
// e.g. 1 9 121
// given interval, how many fair&square exists in the interval??

typedef long long int LL;

bool check(string str){
  for(int i = 0; i < str.length(); i++){
    if(str[i] != str[str.length()-i-1]) return false;
  }
  return true;
}

int main(){


  vector<LL> vec;
  for(LL i = 1; i <= 40000000; i++){
    stringstream rawSs, sqSs;
    string rawStr;
    string sqStr;
    rawSs << i;
    rawStr = rawSs.str();
    bool raw = check(rawStr);
    sqSs << i*i;
    sqStr = sqSs.str();
    bool sq = check(sqStr);
    if(sq && raw){
      vec.push_back(i*i);
      //cout << i << ' ' << i*i <<  endl;
    }
  }
    
  int T;
  cin >> T;
  for(int t = 0; t < T; t++){
    LL A, B;
    cin >> A >> B;
    int posA=-1, posB=-1;
    for(int i = 0; i < vec.size(); i++){
      if(posA == -1 && vec[i] >= A){
	posA = i;
      }	
      if(vec[i] <= B){
	posB = i;
      }
    }
    if(posA == -1){posA = vec.size();}
    //cout << posA << ' ' << posB << ' ' << posB-posA+1 << endl;
    cout << "Case #" << t+1 << ": " << posB-posA+1 << endl;
  }
}
