#include<iostream>
#include<map>
#include<vector>
using namespace std;
const int BUF = 20;


int nVal, val[BUF];

void read(){
  cin >> nVal;
  for(int i=0;i<nVal;i++) 
    cin >> val[i];
}


void printMask(int mask){
  for(int i=0,first=true;i<nVal;i++){
    if(!(mask&(1<<i))) continue;
    if(!first)
      cout << ' ';
    cout << val[i];
    first = false;
  }
  cout << endl;
}


void work(int cases){
  cout << "Case #" << cases << ":" << endl;

  map<int, vector<int> > M; //(sum of subset, list of mask)
  for(int mask=0;mask<(1<<nVal);mask++){
    int sum = 0;
    for(int i=0;i<nVal;i++)
      if(mask&(1<<i))
        sum += val[i];

    if(M.count(sum)){
      vector<int> &maskList = M[sum];
      for(int i=0;i<maskList.size();i++)
        if(!(maskList[i]&mask)){
          printMask(maskList[i]);
          printMask(mask);
          return;
        }
      M[sum].push_back(mask);
    }
    else
      M[sum] = vector<int>(1,mask);
  }

  cout << "Impossible" << endl;
}


int main(){
  int cases;
  cin >> cases;
  for(int i=0;i<cases;i++){
    read();
    work(i+1);
  }
  return 0;
}
