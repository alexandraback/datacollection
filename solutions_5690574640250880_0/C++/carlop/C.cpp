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
     ifstream IN("C-small.in");
     ofstream OUT("C-small.out");
     int num_test;
     IN>>num_test;
          
     for (int test=1; test<=num_test; test++) {
          int R,C,M;
          IN>>R>>C>>M;
          
          vector<string> S(R, string(C, '*'));
          bool doable=true;
          
          int left=R*C-M;
          
          if (left==1) {
               }
          else if (C==1) {
               for (int i=1; i<left; i++) S[i][0]='.';
               } 
          else if (R==1) {
               for (int i=1; i<left; i++) S[0][i]='.';
               } 
          else if (R==2 || C==2) {
               if (left%2!=0 || left==2) doable=false;
               else if (C==2) {
                    for (int i=0; i<left/2; i++) S[i][0]=S[i][1]='.';
                    } 
               else if (R==2) {
                    for (int i=0; i<left/2; i++) S[0][i]=S[1][i]='.';
                    } 
               }
          else {
               if (left==2 || left==3 || left==5 || left==7) doable=false;
               else {
                    if (left>=4) {
                         S[0][0]=S[1][0]=S[0][1]=S[1][1]='.';
                         left-=4;
                         }
                    if (left>=2) {
                         S[2][0]=S[2][1]='.';
                         left-=2;
                         }
                    for (int i=2; i<C; i++) if (left>=2) {
                         S[0][i]=S[1][i]='.';
                         left-=2;
                         }
                    for (int i=3; i<R; i++) if (left>=2) {
                         S[i][0]=S[i][1]='.';
                         left-=2;
                         }
                    if (left==1) S[2][2]='.';
                    else {
                         for (int r=0; r<R; r++) for (int c=0; c<C; c++) if (left>0) if (S[r][c]=='*') {
                              S[r][c]='.';
                              left--;
                              }
                         }
                    } 
               }

          S[0][0]='c';
          
                    
          OUT<<"Case #"<<test<<":\n";
          if (doable) for (int r=0; r<R; r++) OUT<<S[r]<<"\n";
          else OUT<<"Impossible\n";
          }
     return 0;
     }
