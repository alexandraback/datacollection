#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

int main(void) {
     ifstream IN("B1.in");
     ofstream OUT("B1.out");
     
     int num_test;
     IN>>num_test;
     for (int test=1; test<=num_test; test++) {
          int N, X, Y;
          IN>>N>>X>>Y;
          
          if (X<0) X*=-1;
          
          int T=(X+Y)/2;

          int tot=0, n=1;
          for (int t=0; t<T; t++) {
               tot+=n;
               n+=4;
               }
          
          
          double RESd;
          string RES="";
          if (N<=tot) RES="0.0";
          else if (X==0 && N<tot+n) RES="0.0";
          else if (N>=tot+n) RES="1.0";
          else if (N>tot+n/2+Y) RES="1.0";
          else {
               N-=tot;
               Y++;
               vector <double> A(Y+1, 0.0);
               A[0]=1.0;
               
               for (int i=0; i<N; i++) {
                    for (int j=A.size()-1; j>0; j--) {
                         A[j]+=A[j-1];
                         A[j]*=0.5;
                         }
                    A[0]*=0.5;
                    }
               
               RES="";
               RESd=1.0;
               for (int i=0; i<Y; i++) RESd-=A[i];
//               if (RESd<1e-7) RES="0.0";
               }
          
          if (RES=="") OUT<<"Case #"<<test<<": "<<RESd<<"\n";
          else OUT<<"Case #"<<test<<": "<<RES<<"\n";
          }
          
     system("pause");
     return 0;
     }
