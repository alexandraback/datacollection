#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int op(long int A, int N, long int m[], int& d){
    int act1 = 0;
    int act2 = 0;
    long int A2;
    long int As[1];
    int z;
        do {
            
        sort(m, m+N);
            As[0] = A;
           if (*min_element(m,m+N)<*min_element(As,As+0)){
              
              for (int j=0;j<N;j++){
                  if (m[j]<A){
                     if (m[j]!=999999999){
                        A += m[j];
                        m[j] = 999999999;
                        d++;
                     }
                  } else break;
              }
           } else {
             act1 = N-d;
             if (A==1){
                act2=999999999;
                break;
             }
             do {
                A = A+A-1;
                act2++;
                As[0]=A;
             } while (*min_element(m,m+N)>*min_element(As,As+0));
             act2 = act2+op(A, N, m, d);
           }
        } while (d != N);
    return (min(act1, act2));
}

int main(){
    long int T, A, N, act;
    int d;
    cin >> T;
    for (int i=1;i<=T;i++){
        d = 0;
        cin >> A >> N;
        long int m[N];
        for (int j=0;j<N;j++){
            cin >> m[j]; 
        }
        act = op(A, N, m, d);
        cout << "Case #" << i << ": " << act << endl;
    }
}
