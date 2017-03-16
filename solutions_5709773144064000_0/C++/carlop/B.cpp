#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

double optimal_time(double C, double F, double X) {
     double production=2.0;
     double BEST=X/production;
     double curr_time=0;
     
     while (true) {
          double time_needed=C/production;
          curr_time+=time_needed;
          production+=F;
          if (BEST>curr_time+X/production) BEST=curr_time+X/production;
          else return BEST;
          }
     }

int main(void) {
     ifstream IN("B-small.in");
     ofstream OUT("B-small.out");
     int num_test;
     IN>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          double C,F,X;
          IN>>C>>F>>X;
          
          OUT.precision(15);
          
          OUT<<"Case #"<<test<<": "<<optimal_time(C,F,X)<<"\n";
          }
     return 0;
     }
