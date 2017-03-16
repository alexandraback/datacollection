//
//  main.cpp
//  GCJ
//
//  Created by Bryan Hooi on 14/4/12.
//  Copyright (c) 2012 Clinkle. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define printv(v) for (int q=0;q<v.size();q++) cout<<v[q]<<" "; cout<<endl;

int main (int argc, const char * argv[])
{
  ifstream fin("/Users/HOOI/Documents/CS/GCJ/GCJ/in.txt");
  ofstream fout("/Users/HOOI/Documents/CS/GCJ/GCJ/out.txt");
  int cases; fin>>cases;
  for (int cs=1;cs<=cases;cs++){
    int n; fin>>n;
    vi a(n), b(n), stat(n,0);
    for (int i=0;i<n;i++) fin>>a[i]>>b[i];
//    cout<<"INPUT"<<endl;
//    printv(a); printv(b);
    int turns=0,score=0;
    while(true){
//      printv(stat);
//      cout<<"turns="<<turns<<endl;
//      cout<<"score="<<score<<endl;
      bool done=false;
      for (int i=0;i<n;i++) if (score >= b[i] && stat[i]==0){
        stat[i]=2; turns++; score+=2; done=true; break; 
      }
      if (done) continue;
      for (int i=0;i<n;i++) if (score >= b[i] && stat[i]==1){
        stat[i]=2; turns++; score++; done=true; break;
      }
      if (done) continue;
      int bestIndex=-1; int bestB=-1;
      for (int i=0;i<n;i++) if (score >= a[i] && stat[i]==0){
        if (b[i] > bestB){
          bestB = b[i]; 
          bestIndex = i;
        }
      }
      if (bestIndex != -1){
        stat[bestIndex] = 1; turns++; score++; done=true;
      }
      if (done) continue;
      else break;
    }
    if (score==2*n) fout<<"Case #"<<cs<<": "<<turns<<endl;
    else fout<<"Case #"<<cs<<": Too Bad"<<endl;
  }
  return 0;
}

