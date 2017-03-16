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
typedef vector<double> vd;
typedef pair<int, int> pii;

#define printv(v) for (int q=0;q<v.size();q++) cout<<v[q]<<" "; cout<<endl;

int main (int argc, const char * argv[])
{
  ifstream fin("/Users/HOOI/Documents/CS/GCJ/GCJ/in.txt");
  ofstream fout("/Users/HOOI/Documents/CS/GCJ/GCJ/out.txt");
  int cases; fin>>cases;
  for (int cs=1;cs<=cases;cs++){
    int a,b; fin>>a>>b;
    vd p(a),prod(a+1,1),times(a+1);
    for (int i=0;i<a;i++)fin>>p[i];
    for (int i=1;i<=a;i++)prod[i]=prod[i-1]*p[i-1];
//    printv(p); printv(prod);
    double ifTyping=b-a+1+(1-prod[a])*(b+1);
//    cout<<"typing: "<<ifTyping<<endl;
    double ifEnter=b+2;
//    cout<<"enter: "<<ifEnter<<endl;
    for (int i=0;i<=a;i++){
      times[i]=a+b-2*i+1 + (1-prod[i])*(b+1);
    }
//    printv(times);
    double best=min(ifTyping, ifEnter);
    for (int i=0;i<=a;i++) best=min(best, times[i]);
    fout<<fixed<<showpoint<<setprecision(6)<<"Case #"<<cs<<": "<<best<<endl;
  }
  
  return 0;
}

