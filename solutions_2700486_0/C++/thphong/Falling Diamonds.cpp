#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstring>

#define MAXN 105
#define INFTY 1000000000

using namespace std;
int N, X, Y;

int Layer(){
    return (abs(X)+abs(Y))/2;
}

int Num(int k){
    return 4*k+1;
}

double f[MAXN][MAXN];

double Solve(){
       int K = Layer();
       int S = Num(K);
       if(N >= S) return 1.0;
       int S1 = Num(K-1);
       if(N <= S1) return 0.0;
       int R = N - S1;
       if(R <= Y) return 0.0;
       if(X==0){ //dinh
            return 0.0;
       }
       int H = 2*K;
       
       //cout<<R<<" "<<H<<" "<<Y+1<<endl;
       double sum = 0.0;
       double num = 0.0;
       for(int i= 0; i<=R; i++){
               if(i<=H && (R-i)<=H){
                       sum += f[i][R-i];
                       if(i >= Y+1){
                            //cout<<i<<" "<<R-i<<" "<<f[i][R-i]<<endl;
                            num += f[i][R-i];
                       }
               }
       }
       return num/sum;
}

void Init(){
     f[0][0] = 1.0;
     for(int i=1; i<=20; i++){
           f[i][0] = 0.5*f[i-1][0];
           f[0][i] = 0.5*f[0][i-1];
     }
     for(int i=1; i<=20; i++)
     for(int j=1; j<=20; j++) {
          f[i][j] = 0.5*f[i-1][j]+0.5*f[i][j-1];
          //cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
     }
}

int main () {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    Init();
    for(int ca=1; ca<=t; ca++){
        cin >> N >> X >> Y;            
        cout<<"Case #"<<ca<<": ";
        printf("%.8lf\n", Solve());
    }
    return 0;
}
