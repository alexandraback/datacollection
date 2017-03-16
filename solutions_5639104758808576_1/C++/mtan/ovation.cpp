#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;
using std::string;

vector<int> partition (long digits, ifstream& inFile){
  vector<int> result;
  char c;
  for(int i = 0; i <= digits; ++i){
    inFile >> c;
    result.push_back((int)(c-'0'));
  }
  return result; 
}

long calculateFriends (long digits, vector<int> partition){
  long result = 0;
  long sum = 0;
  for(long i = 0; i <= digits; ++i){
    if (sum < i){
      result += (i - sum);
      sum = i;
    }
    sum += partition[i];
  }
  return result;
}


int main(){
  ifstream inFile("A-large.in");
  ofstream outFile("output.txt");
  
  int cases;
  long digits;
  long result;
  vector<int> split;
  
  inFile >> cases;

  for(int i = 1; i <= cases; ++i){ 
    inFile >> digits;
    split = partition(digits, inFile);
    
    result = calculateFriends(digits, split);
    outFile << "Case #" << i << ": " << result << endl;
  }
  return 0;
}
