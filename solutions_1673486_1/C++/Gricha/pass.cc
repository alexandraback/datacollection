#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;

  for (int z=0; z<T;z++){
    int A,B;
    cin >> A >> B;

    double pref_p[A+1];
    for (int i=1;i<=A; i++)
      cin >> pref_p[i];

    double pref[A+1];
    pref[0] = 1;
    for (int i=1; i<=A; i++)
      pref[i] = pref[i-1] * pref_p[i];
    
    double exp[A+1];
    for (int i=0; i<= A; i++){
      exp[i] = pref[A-i]* (B-A+2*i+1) + (1-pref[A-i])*(2*B-A + 2 + 2*i);
//      cout << exp[i] << endl;
    }

    float mini = B+2;
  
      
    


    for (int i=0;i <= A; i++)
      mini = mini < exp[i] ? mini : exp[i];
  
    printf("Case #%d: %.6f\n", z+1, mini);
  }


  return 0;
}
