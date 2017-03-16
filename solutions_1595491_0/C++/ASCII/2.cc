#include <iostream>

using namespace std;

int main(void){
 int T;
 int S;
 int p;
 int N;
 cin >> T;
 for(int t = 1; t <= T; ++t){
  cout << "Case #" << t << ": ";
  cin >> N;
  cin >> S;
  cin >> p;
  int total = 0;
  for(int i = 0; i < N; ++i){
   int ti;
   cin >> ti;
   if(ti == 0){
    if(p == 0){
     total++;
    }
    continue;
   }
   if(ti%3 == 0){
    int x = ti/3;
    if(x >= p){
     total++;
     //cout << ti << " mod 3 = 0, " << ti << "
    }else if(x+1 >= p and S > 0){
     total++;
     S--;
    }
   }else if(ti%3 == 1){
    int x = ti/3+1;
    if(x >= p){
     total++;
    }
   }else if(ti%3 == 2){
    int x = ti/3+1;
    if(x >= p){
     total++;
    }else if(x+1 >= p and S > 0){
     total++;
     S--;
    }
   }
  }
  cout << total << endl;
 }
}
