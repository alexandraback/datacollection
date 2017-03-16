#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

int main(void) {
     ifstream IN("A-large.in");
     ofstream OUT("A-large.out");
     int num_test;
     IN>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          long long num, den;
          IN>>num;
          IN.ignore(1, '/');
          IN>>den;
          long long k=1;
          while ((k*2)<=den && (den%(k*2)==0)) {
               k*=2;
               }
          
          OUT<<"Case #"<<test<<": ";
          if (num%(den/k)!=0) OUT<<"impossible";
          else {
               num/=(den/k);
               den=k;
               int count=0;
               while (num<den) {
                    num*=2;
                    count++;
                    }
               OUT<<count;
               }
          OUT<<"\n";
          }
     return 0;
     }
