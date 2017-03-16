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
#define MAXSETS 70
#define MAXK 7
#define MAXN 3
#define MAXM 5

int N,M,K,R,f;
bool valid[MAXSETS];
int a[MAXK];
int s[MAXSETS][1<<MAXN],num[MAXSETS][MAXN];
int L[MAXM-1]={2,3,4,5};

void construct()
{
    f = 0;
    for(int i=0;i<4;i++){
        for(int j=i;j<4;j++){
            for(int k=j;k<4;k++){
                //printf("%d %d %d\n", L[i], L[j], L[k]);
                num[f][0] = L[i];
                num[f][1] = L[j];
                num[f][2] = L[k];
                s[f][0] = 1;
                s[f][1] = L[i];
                s[f][2] = L[j];
                s[f][3] = L[i]*L[j];
                s[f][4] = L[k];
                s[f][5] = L[i]*L[k];
                s[f][6] = L[j]*L[k];
                s[f][7] = L[i]*L[j]*L[k];
                f++;
            }
        }
    }
    //printf("total sets = %d\n", f);
}

int main()
{
    R = 100; N = 3; M = 5; K = 7;
    construct();
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int cases;
    scanf("%d", &cases);
    printf("Case #%d:\n", cases);
    scanf("%d%d%d%d", &R, &N, &M, &K);
    for(int i=0;i<R;i++){
        for(int j=0;j<f;j++) valid[j] = true;
        for(int j=0;j<K;j++){
            int prod;
            scanf("%d", &prod);
            for(int k=0;k<f;k++){
                bool curr = false;
                for(int x=0;x<(1<<N);x++){
                    if(s[k][x] == prod) curr = true;
                }
                if(!curr) valid[k] = 0;
            }
        }
        for(int j=0;j<f;j++){
            if(valid[j]){
                for(int k=0;k<N;k++) printf("%d",num[j][k]); printf("\n");
                break;
            }
        }
    }
    return 0;
}
