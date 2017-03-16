#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;



int compute (int N, int M, int K) {
   int best = 100;
   //bool arr[N][M];
   int firstR[N];
   int lastR[N];
   int firstC[M];
   int lastC[M];


   for(int i = 1; i < (1<<(N*M)); i++){

      //for(int a = 0; a < N; a++)
         //for(int j = 0; j < M; j++) 
            //arr[a][j] = 0;

      bitset<20> b(i);
      for(int i = 0; i < N; i++){
      firstR[i] = 1000;
      lastR[i] =  -1;
      }
      for(int i = 0; i < M; i++){
      firstC[i] = 1000;
      lastC[i] = -1;
      }

      for(int j = 0; j < N*M; j++) {
         if(b[j]){
            //arr[j/M][j%M] = 1;
            firstR[j/M] = min(firstR[j/M], j%M);
            lastR[j/M] = max(firstR[j/M], j%M);
            firstC[j%M] = min(firstC[j%M], j/M);
            lastC[j%M] = max(firstC[j%M], j/M);
         }
      }


      int count=0;
      for(int a = 0; a < N; a++)
         for(int j = 0; j < M; j++) {
            if(a >= firstC[j] && a <= lastC[j] && j >= firstR[a] && j <= lastR[a]) {
               count++;
            }
         }


      if(count >= K){
         best = min(best,(int)b.count());

      }

   }
return best;
}


void solve() {
   int N,M,K;
   cin >> N>>M>>K;
   /*if(N <= 2 || M <= 2){
      cout << K;
      return;
   }*/
   cout<< compute(N,M,K);



}

int main() {

int t;
cin >> t;
for (int i = 0; i < t; i++) {
   cout << "Case #" << i+1 << ": "; 
   solve();
   cout << endl;
}


return 0;
}
