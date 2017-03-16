#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<map>
using namespace std;

#define PB push_back
#define MP make_pair
#define SL size()
#define LE length()
#define INFI 2000000000
#define X first
#define Y second
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
int N,M;
int A[105][105];
//bool C[105][105];
int maxN[105], maxM[105];
bool isPossible(){
    for(int i=0;i<N;i++){
       for(int j = 0;j<M;j++){
          if(A[i][j] < maxN[i] && A[i][j] < maxM[j]) return false;
       }
    }
    return true;
}
     
int main(){
     int T; cin>>T;
     for(int kases = 1; kases <= T;kases++){
             cin>>N>>M; for(int i=0;i<105;i++) maxN[i] = maxM[i] = 0;
             for(int i = 0; i <N;i++){
                for(int j = 0; j < M; j++){
                    cin>>A[i][j]; 
                    maxN[i] = MAX(maxN[i], A[i][j]);
                    maxM[j] = MAX(maxM[j], A[i][j]);
                }
             }
             /*for(int j = 0;j<M; j++){
             }*/
             cout<<"Case #"<<kases<<": "<<(isPossible()?"YES":"NO")<<endl;
     }    
}
