/*
 * main.cpp
 *
 *  Created on: 2011/09/24
 *      Author: taik
 */


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <vector>

using namespace std;
typedef long long s64;

//#define debug_printf printf
#define debug_printf

bool check(set<int> *all_des,vector<int> *descendants[1001],int start){
  if (all_des->find(start) != all_des->end()){
    //printf("found %d\n",start);
    return true;
  }
  all_des->insert(start);
  for(int i=0;i<(*descendants)[start].size();++i){
//    printf(" child check %d <- %d\n",i,(*descendants)[start][i]);
    if (check(all_des,descendants,(*descendants)[start][i] - 1)){
      return true;
    }
  }
  return false;



}

int main(int argc,const char *argv[]){


  int T,prob = 1;
  int N;
  for (cin >> T;T--;){
    cin >> N;
    vector<int> *descendants = new vector<int>[1001];


    for(int i=0;i<N;++i){
      int M;
      descendants[i].clear();
      cin >> M;
      for(int j=0;j<M;++j){
        int d;
        cin >> d;
        descendants[i].push_back(d);
      }
    }

    bool yes = false;
    for(int i=0;i<N;++i){
      if (descendants[i].size() > 1){
        set<int> all_des;
        all_des.clear();
//        printf("check %d\n",i);
        if (check(&all_des,&descendants,i)){
          yes = true;
          break;
        }
      }
    }
    printf("Case #%d: %s\n",prob++,yes ? "Yes" : "No");


  }


  return 0;
}


