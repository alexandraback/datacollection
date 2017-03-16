#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

void printVec(vector<int> vec);

bool sortFunc (int i, int j) {return (i>j);}

vector<int> sortVec (vector<int> vec){
  std::sort(vec.begin(), vec.end(), sortFunc);
  return vec;
  
}

vector<int> inputSort(int num, ifstream& inFile){
  vector<int> result;
  int a;
  for (int i = 0; i < num; ++i){
    inFile >> a;
    result.push_back(a);
  }
  result = sortVec(result);
  return result;
}

int ceil(int dividend, int divisor){
  if(dividend%divisor){
    return dividend/divisor;
  }
  else{
    return dividend/divisor - 1;
  }
}


int Algorithm(vector<int> vec){
  int min = vec[0];
  int n = 0;
  for(int i = 1; i <= vec[0]; ++i){
    for(unsigned long j = 0; j < vec.size(); ++j){
      n+= (ceil(vec[j], i));
    }
    if (n + i < min){
      min = n + i;
    }
    n = 0;
  }
  return min;
}  

void printVec(vector<int> vec){
  for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
    cout << *it << ", ";
  }
  cout << endl;
}

int main(){
  vector<int> diners;
  int cases;
  int result;
  int numDiners;
  ifstream inFile("B-large.in");
  ofstream outFile("output.txt");
  
  inFile >> cases;

  for(int i = 1; i <= cases; ++i){
    inFile >> numDiners;
    diners = inputSort(numDiners, inFile);
    printVec(diners);
    result = Algorithm(diners);
    outFile << "Case #" << i << ": " << result << endl; 
    
  }
  return 0;
}
