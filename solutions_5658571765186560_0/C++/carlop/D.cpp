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
          int X,R,C;
          cin>>X>>R>>C;
          
          bool who=false;
          
          if (X==1) who=true;
          else if (X==2) {
               if ((R*C)%2==0) who=true;
               }
          else if (X==3) {
               if ((R*C)%3==0 && R>=2 && C>=2) who=true;
               }
          else if (X==4) {
               if ((R*C)%4==0 && R>=3 && C>=3) who=true;
               }
          
          string winner="RICHARD";
          if (who) winner="GABRIEL";
          
          cout<<"Case #"<<test<<": "<<winner<<"\n";
          }
     return 0;
     }
