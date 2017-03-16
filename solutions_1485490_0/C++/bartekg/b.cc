#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;


#define REPN(n) for (int i=0;i<(n);i++)
#define REP(n,j) for (int j=0;j<(n);j++)


long long boxT[1000];
long long boxS[1000];

long long toyT[1000];
long long toyS[1000];

int M;
int N;
  
long long bestmatch=0;

int go(int box,int toy,long long match,long long boxleft,long long toyleft) {
  long long t,b;
  if (match > bestmatch) bestmatch = match;
  if (toy==M) return bestmatch;
  if (box==N) return bestmatch;
  
//  cout << "B: " << bestmatch << endl;
//  cout << "Toy " << toy << endl;
//  cout << "Box: " << box << endl;
  if (boxT[box] == toyT[toy]) {    
    if (boxleft != -1) 
      b = boxleft;
    else 
      b = boxS[box];
    if (toyleft != -1) 
      t = toyleft;
    else 
      t = toyS[toy];    

  //  cout << "Zgodny typ: " << boxT[box] << " B: " << b << " T: " << t << " Toyleft " << toyleft << " Boxleft: " << boxleft << endl;
    match += min(b,t);

    if (b == t) {
      toy++;
      box++;
      boxleft=-1;
      toyleft=-1;
    }
    else { 
     
      if (b > t) { 
        toy++;
        toyleft=-1;
        boxleft=b - t;
      }
      else {
        box++;
        boxleft=-1;
        toyleft = t- b;
      }
    }
    go(box,toy,match,boxleft,toyleft);
    return bestmatch;
  }
  if (box < N)  {
//    cout << "Pomijam box" << endl;    
    go(box+1,toy,match,-1,toyleft);
//    return bestmatch;
  }
  if (toy < M)  { 
    go(box,toy+1,match,boxleft,-1);
//    return bestmatch;
//    cout << "Pomijam toy" << endl;
  }
  if (match > bestmatch) bestmatch = match;
  return bestmatch;
}
  
    
int main(void) {
  int T;
  int a;
  cin >> T;
  int cnt=1;
  REPN(T) {
    bestmatch=0;
    cin >> N >> M;
    REPN(N) { 
      cin >> boxS[i] >> boxT[i];
    }
    REPN(M) {
      cin >> toyS[i] >> toyT[i];
    }   
//    for (int i=0;i<M;i++) {
//      cout << "ToyType: " << toyT[i] << " " << toyS[i] << endl;
 //  }
    go(0,0,0,-1,-1);
    cout << "Case #" << (cnt) << ": " << bestmatch << endl;
    cnt++;
    
  }


}

    
