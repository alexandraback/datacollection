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
          cin>>N;
          
          vector <int> A(N);
          for (int i=0; i<N; i++) cin>>A[i];
          
          int best=1000;
          
          for (int i=1; i<=1000; i++) {
               int minutes_needed=i;
               for (int j=0; j<N; j++) minutes_needed+=(A[j]-1)/i;
               best=min(best, minutes_needed);
               }
          
          
          cout<<"Case #"<<test<<": "<<best<<"\n";
          }
     return 0;
     }
