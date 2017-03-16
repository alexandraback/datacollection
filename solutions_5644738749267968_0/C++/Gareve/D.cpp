#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

const int MX = 1009;

int N;
double A[MX],B[MX];

int war(){
   int score = 0;

   set<double> stB(B,B+N);
   set<double>::iterator it;
   for(int a=0;a<N;a++){
      it = stB.lower_bound(A[a]);
      if(it == stB.end()){
         score++;
         it = stB.begin();
      }
      stB.erase(it);
   }

   return score;
}

int main(){
   int NC;scanf("%d",&NC);

   for(int i=1;i<=NC;i++){
      scanf("%d",&N);
      for (int j = 0; j < N; ++j)scanf("%lf",&A[j]);
      for (int j = 0; j < N; ++j)scanf("%lf",&B[j]);

      int war_score = war();
      swap(A,B);
      int deceitful_war_score = N - war();

      printf("Case #%d: %d %d\n",i,deceitful_war_score,war_score);
   }
}