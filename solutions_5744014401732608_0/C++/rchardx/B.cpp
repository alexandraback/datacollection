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

const int MAXN = 10+1;

int N;
LL M;
int pat[1<<15][2];
int num[MAXN][MAXN];
int ans = 0;
int mat[MAXN][MAXN];

void dfs(int x) {
    if (x==N-1) {
       ans++;
       return;
    }
    for (int i = x+1; i<N; ++i)
        if (mat[x][i]) dfs(i);
}

void print(int S) {
    for (int i = 0; i<N; ++i) {
        for (int j = 0; j<N; ++j)
            printf("%d",mat[i][j]);
        cout<<endl;
    }
}

int check(int S) {
    memset(mat,0,sizeof(mat));
    for (int i = 0; i+1<N; ++i) {
        for (int j = i+1; j<N; ++j)
            if (S&(1<<num[i][j])) {
               mat[i][j] = 1;
            }
    }
    //if (S==631) print(S);
    ans = 0;
    dfs(0);
    return ans;
}

int main() {
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
  
    int T; cin>>T;
    for (int loop = 1; loop<=T; ++loop) {
        printf("Case #%d:", loop);
        cin>>N>>M;
        int cnt = 0;
        for (int i = 0; i+1<N; ++i) {
            for (int j = i+1; j<N; ++j) {
                pat[cnt][0] = i;
                pat[cnt][1] = j;
                num[i][j] = cnt;
                ++cnt;
            }
        }
        
        bool flag = 0;
        int lim = (1<<cnt)-1;
        //cout<<cnt<<endl;
        for (int S = 0; S<=lim; ++S)
            if (check(S)==M) {
                flag = 1;
                cout<<" POSSIBLE"<<endl;
                print(S);
                break;
            }
        if (!flag) cout<<" IMPOSSIBLE"<<endl;
    }
    return 0;
}
