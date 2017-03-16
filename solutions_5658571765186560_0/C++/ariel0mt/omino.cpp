/*
 * omino.cpp
 *
 *  Created on: 10/4/2015
 *      Author: ariel
 */
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <stack>
#include <queue>
using namespace std ;

string solve(int x,int r,int c){

  string ganador="GABRIEL";

  if(x>r && x>c)
    ganador="RICHARD";
  else if(ceil((float)x/2)>r||ceil((float)x/2)>c)
    ganador="RICHARD";
  else if((r*c)%x>0)
    ganador="RICHARD";
  else if(x==4 && r*c==8)
    ganador="RICHARD";
  else ;
  return ganador;
}

int main(){
  //clock_t start = clock();
  freopen("D-small-attempt0.in","r",stdin);
  freopen("D-small-ariel0.out","w",stdout);
  int casos;
  int x,r,c;
  cin>>casos;
  for(int icaso=1;icaso<=casos;icaso++){
      cin>>x>>r>>c;
      cout<<"Case #"<<icaso<<": "<<solve(x,r,c)<<endl;
  }
  //clock_t ends = clock();
  //cout<<"Tiempo:"<<(double)(ends-start)/CLOCKS_PER_SEC<<endl;


  return 0;
}
