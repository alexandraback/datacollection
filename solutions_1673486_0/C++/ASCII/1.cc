#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(void){
 int T;
 cin >> T;
 for(int t = 1; t <= T; ++t){
  cout << "Case #" << t << ": ";
  int A,B;
  cin >> A >> B;
  vector<double> P;
  P.clear();
  for(int i = 0; i < A; ++i){
   double j;
   cin >> j;
   P.push_back(j);
  }
  double keep_typing = 0;
  double hit_enter = B + 2;
  double p_right = P[0];
  double p_wrong = 0;
  for(int i = 1; i < A; ++i){
   p_right *= P[i];
  }
  p_wrong = 1- p_right;
  keep_typing = p_right * (B-A+1) + p_wrong * (B - A + 2 + B);
  //cout << "keep typing " << keep_typing << endl;
  double best_backspace = 4*B+2;
  for(int N = 1; N <= A; ++N){
   int lim = A-N-1;
   p_right = P[0];
   if(lim < 0){
    p_right = 1;
   }
   for(int i = 1; i <= lim; ++i){
    p_right *= P[i];
   }
   p_wrong = 1-p_right;
   double e_back = p_right * (B+2*N-A+1) + p_wrong * (B+B+2*N-A+2);
   if( e_back < best_backspace){
    best_backspace = e_back;
   }
   /*cout << N << " backspaces " << e_back << endl;
   cout << "p(right) = " << p_right << endl;
   cout << "p(wrong) = " << p_wrong << endl;
   cout << "(B+2*N-A+1) " << (B+2*N-A+1) << endl;
   cout << "(B+B+2*N-A+2) " << (B+B+2*N-A+2) << endl;*/
  }
  //cout << "enter " << hit_enter << endl;
  double best = keep_typing;
  if(best_backspace < best){
   best = best_backspace;
  }
  if(hit_enter < best){
   best = hit_enter;
  }
  //cout << best << endl;
  printf("%.6f\n",best);
 }
}
