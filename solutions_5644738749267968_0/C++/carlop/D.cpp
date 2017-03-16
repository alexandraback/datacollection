#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

vector<double> read_vector(ifstream & IN, int N) {
     vector <double> A(N);
     for (int i=0; i<N; i++) IN>>A[i];
     sort(A.begin(), A.end());
     return A;
     }

pair<int,int> war(vector <double> A, vector <double> B, int N) {
     int R=0;
     int a=0, b=0;
     for (int b=0, a=0; b<N; b++) {
          if (B[b]>A[a]) {
               R++;
               a++;
               }
          }
     return make_pair(N-R, R);
     }

int main(void) {
     ifstream IN("D-small.in");
     ofstream OUT("D-small.out");
     int num_test;
     IN>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          int N;
          IN>>N;
          
          vector <double> A=read_vector(IN, N);
          vector <double> B=read_vector(IN, N);
          
          OUT<<"Case #"<<test<<": "<<war(B, A, N).second<<" "<<war(A, B, N).first<<"\n";
          }
     return 0;
     }
