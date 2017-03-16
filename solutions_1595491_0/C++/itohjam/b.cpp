#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  int T;
  cin >> T;

  for(int SET = 1; SET <= T; SET++){
    printf("Case #%d: ", SET);
    int n, s, p;
    cin >> n >> s >> p;

    int cntP = 0;
    int cntSupP = 0;

    for(int i = 0; i < n; i++){
      int t;
      cin >> t;

      int best = (t == 0 ? 0 : (t - 1) / 3 + 1);

      if(best >= p){
        cntP++;
      }
      else{
        if((t % 3 == 0 && t >= 3 || t % 3 == 2 && t >= 2) && best + 1 >= p){
          cntSupP++;
        } 
      }
    }

    printf("%d\n", min(cntSupP, s) + cntP);
  }
}
