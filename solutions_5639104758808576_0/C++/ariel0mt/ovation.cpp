/*
 * ovation.cpp
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


void solve(int caso){
	string audiencia;
	int pie=0,inv=0,smax;
	cin>>smax;
	cin>>audiencia;
	pie=audiencia[0]-'0';
  for(int i=1;i<audiencia.size();i++){
    if(audiencia[i]!='0'){
      int c=audiencia[i]-'0';
      if(pie>=i) pie+=c;
      else{
          inv+=i-pie;
          pie+=(i-pie)+c;
      }
      //cout<<c<<"["<<i<<"]:"<<pie<<","<<inv<<endl;
    }
  }
  cout<<"Case #"<<caso<<": "<<inv<<endl;
}

int main(){
  //clock_t start = clock();
  freopen("A-small-attempt0.in","r",stdin);
  freopen("A-small-answer-ariel0.out","w",stdout);

  int casos;

  cin>>casos;
  for(int icasos=1;icasos<=casos;icasos++){
	  solve(icasos);
  }

  //clock_t ends = clock();
  //cout<<"Tiempo:"<<(double)(ends-start)/CLOCKS_PER_SEC<<endl;


  return 0;
}








