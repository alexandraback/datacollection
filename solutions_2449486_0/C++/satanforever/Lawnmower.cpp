#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <complex>
using namespace std;

#define read(c) scanf("%d",&(c))
#define FOR(i,n) for (int i=0;i<(n);i++)
#define FR(i,a,b) for (int i=(a);i<(b);i++)
#define fillzero(d) memset(d,0,sizeof(d))
#define fillmax(d) memset(d,63,sizeof(d))
#define dumps(x) cerr<<(__LINE__)<< ':'<<#x<<" = "<<(x)<<endl
#define dump(x) cerr<<(__LINE__)<< ':'<<#x<<" = "<<(x)<<"	"
#define shit cerr<<"Line:"<<(__LINE__)<<endl;
#define fileread freopen("/Users/satanforever/Documents/input.txt","r",stdin)
#define filereadT freopen("/Users/satanforever/Downloads/B-small-attempt2.in.txt","r",stdin)
#define filewrite freopen("/Users/satanforever/Documents/B-small.out","w",stdout)
#define closeread fclose(stdin)
#define closewrite fclose(stdout)
#define MAXINT 0x7fffffff

int board[101][101];
int N, M, maxH;
bool solve(){
    bool shear[101][101];
    int maxNum;
    memset(shear, false, sizeof(shear));
    for (int i = 0; i < N; i++) {
        maxNum = 0;
        for (int j = 0; j < M; j++)
            maxNum = max(maxNum, board[i][j]);
        for (int j = 0; j < M; j++)
            if (board[i][j] == maxNum)
                shear[i][j] = true;
    }
    for (int j = 0; j < M; j++) {
        maxNum = 0;
        for (int i = 0; i < N; i++)
            maxNum = max(maxNum, board[i][j]);
        for (int i = 0; i < N; i++)
            if (board[i][j] == maxNum)
                shear[i][j] = true;
    }
    for (int i = 0; i < N; i++)
        for (int j =0; j < M; j++)
            if (!shear[i][j])
                return false;
    return true;
}
void input(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
}
void output(bool ret, int t){
    cout << "Case #" << t << ": " << (ret ? "YES" : "NO") <<endl;
}
int main() {
//filereadT;
//filewrite;
int T;
cin >> T;
for(int i = 1; i <= T; i++) {
  	input();
  	output(solve(), i);
}
//closeread;
//closewrite;
  	return 0;
}
