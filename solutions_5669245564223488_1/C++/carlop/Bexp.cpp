#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

string reduce_(string S) {
     string R="";
     R+=S[0];
     for (int i=1; i<S.size(); i++) if (*R.rbegin()!=S[i]) R+=S[i];
     return R;
     }

long long compute_brute_force_solution(vector <string> V) {
     long long RES=0;
     int N=V.size();
     vector <int> A(N);
     for (int i=0; i<N; i++) A[i]=i;
     do {
          string K="";
          for (int i=0; i<N; i++) K+=V[A[i]];
          K=reduce_(K);
          vector <int> conta(26, 0);
          for (int i=0; i<K.size(); i++) conta[K[i]-'a']++;
          
          bool doable=true;
          for (int i=0; i<26; i++) if (conta[i]>1) doable=false;
          if (doable) RES++;
          
          } while (next_permutation(A.begin(), A.end()));
     return RES;
     }

int main(void) {
     ifstream IN("B-large.in");
     ofstream OUT("B-large.out");
     int num_test;
     IN>>num_test;
     
     long long MOD=1000000007;
     
     for (int test=1; test<=num_test; test++) {
          int N;
          IN>>N;

          vector <long long> inner_combination(26, 1);
          vector <long long> how_many_single(26, 0);
          vector <int> inbound(26, 0);
          vector <int> outbound(26, 0);
          vector <int> middle_presence(26, 0);

          vector <string> V;
          string S;
          map<char, char> MAP;
          long long R=1;
          for (int i=0; i<N; i++) {
               IN>>S;
               S=reduce_(S);
               V.push_back(S);

               if (S.size()==1) {
                    how_many_single[S[0]-'a']++;
                    inner_combination[S[0]-'a']=(inner_combination[S[0]-'a']*how_many_single[S[0]-'a'])%MOD;
                    }
               else {
                    int s=*S.begin()-'a';
                    int e=*S.rbegin()-'a';

                    inbound[s]++;
                    outbound[e]++;
                    if (MAP.count(s)!=0) R=0;
                    MAP[s]=e;
                    while (MAP.count(MAP[s])!=0 && R!=0) {
                         MAP[s]=MAP[MAP[s]];
                         if (s==MAP[s]) R=0;
                         }
                    
                    for (int i=1; i+1<S.size(); i++) middle_presence[S[i]-'a']++;
                    }
               
               }
          
          long long number_outbound=0;
          
          for (int i=0; i<26; i++) {
               if (inbound[i]>1 || outbound[i]>1 || middle_presence[i]>1) R=0;
               else if ((inbound[i]!=0 || outbound[i]!=0) && middle_presence[i]!=0) R=0;
               else R=(R*inner_combination[i])%MOD;
               
               if ((outbound[i]==1 || how_many_single[i]>=1) && inbound[i]==0) {
                    number_outbound++;
                    R=(R*number_outbound)%MOD;
                    }
               }
          
//assert(R==compute_extensively(V));

          OUT<<"Case #"<<test<<": "<<R<<"\n";
          }
     return 0;
     }
