#include <iostream>
#include <vector>
using namespace std;

int main(void){

 int T;
 cin >> T;
 for(int t = 1; t <= T; ++ t){
  cout << "Case #" << t << ": ";
  int N;
  cin >> N;
  vector<int> star1(N), star2(N);
  vector<bool> complete(N), both_stars(N);
  int stars = 0;
  int levels = 0;
  for(int n = 0; n < N; ++n){
   int ai, bi;
   cin >> ai >> bi;
   star1[n] = ai;
   star2[n] = bi;
   complete[n] = both_stars[n] = false;
  }
  bool win = true;
  do{
   win = true;
   for(int i = 0; i < N; ++i){
    if(both_stars[i]){
     continue;
    }
    if(stars >= star2[i]){
     if(!complete[i]){
      stars += 2;
      complete[i] = true;
      both_stars[i] = true;
      win = false;
      ++levels;
      break;
     }else{
      ++stars;
      ++levels;
      both_stars[i] = true;
      win = false;
      break;
     }
    }
   }
   if(!win){
    continue;
   }
   for(int i = 0; i < N; ++i){
    if(complete[i]){
     continue;
    }
    if(stars >= star1[i]){
     ++stars;
     ++levels;
     complete[i] = true;
     win = false;
     break;
    }
   }
  }while(!win);
  win = true;
  for(int i = 0; i < N; ++i){
   if(!both_stars[i]){
     win = false;
     break;
   }
  }
  if(!win){
   cout << "Too Bad" << endl;
  }else{
   cout << levels << endl;
  }
 }

}
