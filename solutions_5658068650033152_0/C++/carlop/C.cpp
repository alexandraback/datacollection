#include <vector>
#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <set>
#include "assert.h"
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

int main(void) {
     ifstream IN("C-small1.in");
     ofstream OUT("C-small1.out");
     int num_test;
     IN>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          int N,M,K;
          IN>>N>>M>>K;
          
          int RES=K;
          
          if (min(N,M)>=2) {
               int a=3;
               int cover=5;
               int used=4;
               vector <int> sides(4, 2);
               RES=min(RES, used+max(K-cover, 0));
               
               while (a<min(N,M)) {
                    used+=2;
                    if (a%2==1) {
                         cover+=a;
                         sides[0]=sides[1]=sides[0]+1;
                         }
                    else {
                         cover+=a+1;
                         sides[2]=sides[3]=sides[0];
                         }
                    a++;
                    
                    RES=min(RES, used+max(K-cover, 0));
                    RES=min(RES, used+1+max(K-cover-(sides[0]-1),0));
                    }
               while (a<max(N,M)) {
                    used+=2;
                    cover+=min(N,M);
                    a++;
                    RES=min(RES, used+max(K-cover, 0));
                    RES=min(RES, used+1+max(K-cover-(sides[0]-1),0));
                    }
               
               while (sides[0]>0) {
                    used++;
                    cover+=sides[0]-1;
                    sides[0]--;
                    
                    RES=min(RES, used+max(K-cover, 0));
                    
                    
                    sort(sides.rbegin(), sides.rend());
                    }
               }
          
          
          OUT<<"Case #"<<test<<": "<<RES<<"\n";
          }
     return 0;
     }
