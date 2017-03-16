#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

int A[57][57];
char C[57][57];
int T[57][57];
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
queue<int> Q;

void hladaj(int y, int x) {
    Q.push(y); Q.push(x);
    T[y][x]=true;
    while(!Q.empty()) {
        int y1=Q.front(); Q.pop();
        int x1=Q.front(); Q.pop();
        if(A[y1][x1]!=0) continue;
        For(i,8) {
            int y2=y1+dy[i],x2=x1+dx[i];
            if(A[y2][x2]==-1 || T[y2][x2]) continue;
            T[y2][x2]=true;
            Q.push(y2); Q.push(x2);
        }
    }
}

void solve(int num) {
    int r,c,m;
    scanf("%d %d %d",&r,&c,&m);
    printf("Case #%d:\n",num);
    int n=r*c;
    For(i,1<<n) {
        int poc=0;
        For(j,n) if(i&(1<<j)) poc++;
        if(poc!=m) continue;
        For(j,r+5) For(k,c+5) A[j][k]=0;
        For(j,r) For(k,c) if(i&(1<<(j*c+k))) A[j+1][k+1]=-1;
        For(j,r) For(k,c) {
            if(A[j+1][k+1]==-1) continue;
            For(i1,8) if(A[j+1+dy[i1]][k+1+dx[i1]]==-1) A[j+1][k+1]++;
        }
        For(j,r+2) A[j][0]=A[j][c+1]=-1;
        For(j,c+2) A[0][j]=A[r+1][j]=-1;
        int zx=-1,zy=-1;
        For(i1,r) For(j1,c) if(A[i1+1][j1+1]==0) {zy=i1+1; zx=j1+1;}
        if(zx==-1) {
            For(i1,r) For(j1,c) if(A[i1+1][j1+1]!=-1) {zy=i1+1; zx=j1+1;}
        }
        For(i1,r+2) For(j1,c+2) T[i1][j1]=false;
        hladaj(zy,zx);
        bool t=true;
        For(i1,r) For(j1,c) if(A[i1+1][j1+1]!=-1 && !T[i1+1][j1+1]) t=false;
        if(t) {
            For(i1,r) For(j1,c) {
                if(A[i1+1][j1+1]==-1) C[i1][j1]='*';
                else C[i1][j1]='.';
            }
            C[zy-1][zx-1]='c';
            For(i,r) {For(j,c) printf("%c",C[i][j]); printf("\n");}
            return;
        }
    }
    printf("Impossible\n");
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
return 0;
}
