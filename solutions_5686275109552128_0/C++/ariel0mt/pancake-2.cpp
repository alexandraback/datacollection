/*
 * pancake.cpp
 *
 *  Created on: 11/4/2015
 *  Author: ariel
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
	int d,dtmp,tmax,tmin,sum;
	vector<int> dinners;
	cin>>d;
	tmax=0;
	for(int id=0;id<d;id++){
    cin>>dtmp;
    dinners.push_back(dtmp);
    tmax=max(tmax,dinners[id]);
	}
	tmin=tmax;
	for(int i=1;i<=tmax;i++){
    sum=i;
    for(int j=0;j<d;j++){
      if(dinners[j]>i){
        if(dinners[j]%i==0)
          sum+=(dinners[j]/i-1);
        else
          sum+=(dinners[j]/i);
      }
    }
    tmin=min(tmin,sum);
	}
  cout<<"Case #"<<caso<<": "<<tmin<<endl;
  dinners.clear();
}

int main(){
  freopen("B-small-attempt1.in","r",stdin);
  freopen("B-small-ariel1.out","w",stdout);
  int casos;
  cin>>casos;
  for(int ic=1;ic<=casos;ic++){
      solve(ic);
  }
return 0;
}
