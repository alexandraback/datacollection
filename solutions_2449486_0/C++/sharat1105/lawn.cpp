#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<cassert>
#include<iomanip>
using namespace std;

#define LL long long
#define PI pair<int,int>
#define F first
#define S second
#define MP make_pair
#define VI vector<int>
#define VPI vector<PI>
#define PB push_back

#define MAXN 100
#define MAXM 100
#define MAXH 100

int N,M;
int a[MAXN][MAXM];
int b[MAXN][MAXM];
bool mark[MAXN][MAXM];
bool poss;

void level(int h,int x,int y)
{
    bool valid = true;
    // move the lawn mover along the column
    for(int i=0;i<N;i++){
        if(mark[i][y] && b[i][y] > h) valid = false;
    }
    if(valid){
        mark[x][y] = true;
        b[x][y] = h;
        //printf("trimming along column at (%d,%d)\n", x,y);
        for(int i=0;i<N;i++){
            if(!mark[i][y]){
                b[i][y] = h;
                if(b[i][y] == a[i][y]) mark[i][y] = true;
            }
        }
        return ;
    }
    valid = true;
    // move the lawn mover along the row
    for(int j=0;j<M;j++){
        if(mark[x][j] && b[x][j] > h) valid = false;
    }
    if(valid){
        mark[x][y] = true;
        b[x][y] = h;
        //printf("trimming along row at (%d,%d)\n", x,y);
        for(int j=0;j<M;j++){
            if(!mark[x][j]){
                b[x][j] = h;
                if(b[x][j] == a[x][j]) mark[x][j] = true;
            }
        }
        return ;
    }
    //printf("failed to trim (%d,%d)\n", x, y);
    poss = false;
}

void trim(int h)
{
    for(int i=0;i<N && poss;i++){
        for(int j=0;j<M && poss;j++){
            if(a[i][j] == h && !mark[i][j]){
                level(h,i,j);
                //for(int ii=0;ii<N;ii++){for(int jj=0;jj<M;jj++) printf("%d",(int)mark[ii][jj]); printf("\n");}
            }
        }
    }
}

int main()
{
    freopen("input1.txt","r", stdin);
    freopen("output1.txt", "w", stdout);
    int cases;
    scanf("%d", &cases);
    for(int casenum=1;casenum<=cases;casenum++){
        scanf("%d%d", &N, &M);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf("%d", &a[i][j]);
                b[i][j] = 100;
                mark[i][j] = false;
            }
        }
        poss = true;
        for(int h=MAXH;h>0 && poss;h--) trim(h);
        if(poss) printf("Case #%d: YES\n", casenum);
        else printf("Case #%d: NO\n", casenum);
    }
    return 0;
}
