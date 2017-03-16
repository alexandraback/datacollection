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

class C{
     public:
     int N;
     vector <string> ZIP;
     vector <vector <bool> > CONNECTED;
     vector <bool> passable;
     vector <bool> visited;
     string RES;
     vector <int> city_stack;
     int curr_city;
     int number_city_visited;
     
     C(vector <string> zip, vector<vector<bool> > connected) {
          N=zip.size();
          ZIP=zip;
          CONNECTED=connected;
          
          passable.resize(N, true);
          visited.resize(N, false);
          
          pair <string, int> BEST=make_pair(ZIP[0], 0);
          for (int i=0; i<N; i++) BEST=min(BEST, make_pair(ZIP[i], i));
          RES="";
          
          city_stack.resize(0);
          number_city_visited=0;
          
          visit_and_update(BEST.second);
          
          while (number_city_visited<N) {
               assert(passable[curr_city]);
               cerr<<curr_city<<"\t"<<number_city_visited<<"\n";
               
               vector <int> X;
               for (int i=0; i<city_stack.size(); i++) for (int j=0; j<N; j++) if (CONNECTED[city_stack[i]][j] && visited[j]==false) X.push_back(j);
               int best_possible2=evaluate_best(X);
               
               if (CONNECTED[curr_city][best_possible2]) {
                    cerr<<"go to best\n";
                    visit_and_update(best_possible2);
                    }
               else if (any_childred_can_become_disconnect(curr_city)) {
                    cerr<<"ill children\n";
                    
                    vector<int> children=get_list_children(curr_city);
                    
                    int best_children=evaluate_best(children);
                    visit_and_update(best_children);
                    }
               else {
                    cerr<<"go back\n";
                    city_stack.pop_back();
                    passable[curr_city]=false;
                    curr_city=*(city_stack.rbegin());
                    }
               cerr<<curr_city<<"\t"<<number_city_visited<<"\t"<<"\n\n";
               }
          }
     int evaluate_best(vector <int> x) {
          pair<string, int> B=make_pair(ZIP[x[0]], x[0]);
          for (int i=0; i<x.size(); i++) B=min(B, make_pair(ZIP[x[i]], x[i]));
          return B.second;
          }
     vector <int> get_list_children(int x) {
          vector <int> R;
          for (int i=0; i<N; i++) if (visited[i]==false) if (CONNECTED[i][x]) R.push_back(i);
          return R;
          }
     bool any_childred_can_become_disconnect(int x) {
          bool RES=false;

          passable[x]=false;

          vector <bool> A(N, false);
          A[city_stack[0]]=true;
          queue <int> Q;
          Q.push(city_stack[0]);
          while(Q.size()>0) {
               int f=Q.front();
               Q.pop();
               for (int i=0; i<N; i++) if ((CONNECTED[f][i]) && (A[i]==false) && (passable[i])) {
                    A[i]=true;
                    Q.push(i);
                    }
               }

          passable[x]=true;

          
          vector<int> children=get_list_children(x);
          for (int i=0; i<children.size(); i++) {
               int c=children[i];
               if (A[c]==false) RES=true;
               }
          
          return RES;
          }
     void visit_and_update(int x) {
          number_city_visited++;
          curr_city=x;
          city_stack.push_back(x);
          RES+=ZIP[x];
          visited[x]=true;
          }
     };

int main(void) {
     ifstream IN("C-small1.in");
     ofstream OUT("C-small1.out");
     int num_test;
     IN>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          int N,M;
          IN>>N>>M;
          
          vector <string> ZIP(N);
          for (int i=0; i<N; i++) IN>>ZIP[i];
          
          vector <vector <bool> > CONNECTED(N, vector<bool> (N, false));
          
          for (int i=0; i<M; i++) {
               int a, b;
               IN>>a>>b;
               CONNECTED[a-1][b-1]=true;
               CONNECTED[b-1][a-1]=true;
               }
          C solution(ZIP, CONNECTED);
          
          OUT<<"Case #"<<test<<": "<<solution.RES<<"\n";
//          system("PAUSE");
          }
     return 0;
     }
