#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

bool doable(long long M, vector<int> V, int R, int D) {
     for (int i=0; i<D; i++) V.pop_back();
     
     for (int i=0; i<V.size(); i++) {
          if (M>V[i]) {
               if (M<=5000000) M+=V[i];
               }
          else {
               if (R<=0) return false;
               else {
                    R--;
                    i--;
                    M+=(M-1);
                    }
               }
          }
     return true;
     }

int main(void) {
     ifstream IN("A2.in");
     ofstream OUT("A2.out");
     int num_test;
     IN>>num_test;
     cout<<num_test<<"\n";
     for (int test=1; test<=num_test; test++) {
          int M, N;
          IN>>M>>N;
          vector<int> V(N);
          for (int i=0; i<N; i++) IN>>V[i];
          sort(V.begin(), V.end());
          
          int best=N;
          
          for (int rimuovi=0; rimuovi<=N; rimuovi++) for (int raddoppia=0; raddoppia<=N; raddoppia++) if (rimuovi+raddoppia<best) {
               if (doable(M, V, rimuovi, raddoppia)) best=rimuovi+raddoppia;
               }

          OUT<<"Case #"<<test<<": "<<best<<"\n";
          }
          
     system("pause");
     return 0;
     }
