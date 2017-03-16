#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;

#define _abs(x) ((x)>0?(x):-(x))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long LL;

const int MAXN = 50+1;

int N;
LL M;
int mat[MAXN][MAXN];

int main() {
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
  
    int T; cin>>T;
    for (int loop = 1; loop<=T; ++loop) {
        printf("Case #%d:", loop);
        cin>>N>>M;
        
        LL sol = 1<<(N-2);
        
        
        
        if (M<=sol) {
            cout<<" POSSIBLE"<<endl;
            memset(mat,0,sizeof(mat));
            for (int i = 0; i<N; ++i)
               for (int j = i+1; j<N; ++j)
                   mat[i][j] = 1;
            LL dif = sol-M;
            for (LL k = 0; k<N-2; ++k) {
                if (dif&(1<<k)) {
                    mat[1+k][N-1] = 0;
                }
            }
            for (int i = 0; i<N; ++i) {
               for (int j = 0; j<N; ++j)
                   cout<<mat[i][j];
               cout<<endl;
           }
        }
        else {
            cout<<" IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}
