#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

int main(void) {
     int num_test;
     cin>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          int N;
          string S;
          cin>>N>>S;
          
          int required_friends=0;
          
          int sum_untill_now=0;
          for (int i=0; i<=N; i++) {
               required_friends=max(required_friends, i-sum_untill_now);
               sum_untill_now+=(int)S[i]-(int)'0';
               }
          
          cout<<"Case #"<<test<<": "<<required_friends<<"\n";
          }
     return 0;
     }
