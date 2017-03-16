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
#define MAXSETS 20000
#define MAXK 12
#define MAXN 12
#define MAXM 8

int N,M,K,R,f;
bool cand[MAXSETS];
int freq[MAXSETS];
set<LL> s[MAXSETS];
LL num[MAXSETS][MAXN];
LL temp[MAXN];
queue<int> myq;
LL prod[MAXK];
LL fact[20];
int ct[10];

void dfs(int depth)
{
    if(depth == N){
        for(int i=0;i<10;i++) ct[i] = 0;
        for(int i=0;i<N;i++) num[f][i] = temp[i],ct[num[f][i]]++;
        freq[f] = fact[N];
        for(int i=0;i<10;i++) freq[f] /= fact[ct[i]];
        for(int i=0;i<(1<<N);i++){
            LL curr = 1LL;
            for(int j=0;j<N;j++) if(i & (1<<j)) curr *= num[f][j];
            s[f].insert(curr);
        }
        f++;
        return ;
    }
    int start;
    if(depth == 0) start = 2;
    else start = temp[depth-1];
    for(int i=start;i<=M;i++){
        temp[depth] = i;
        dfs(depth+1);
    }
}

void construct()
{
    fact[0] = 1;
    for(LL i=1;i<=12;i++) fact[i] = fact[i-1]*i;
    f = 0;
    dfs(0);
    //printf("total sets = %d\n", f);
}

int main()
{
    freopen("input5.txt", "r", stdin);
    freopen("output5.txt", "w", stdout);
    int cases;
    scanf("%d", &cases);
    printf("Case #%d:\n", cases);
    scanf("%d%d%d%d", &R, &N, &M, &K);
    construct();
    for(int i=0;i<R;i++){
        for(int j=0;j<K;j++) scanf("%lld", &prod[j]);
        for(int j=0;j<f;j++){
            bool valid = true;
            for(int k=0;k<K;k++){
                if(s[j].find(prod[k])==s[j].end()){
                    valid = false;
                    break;
                }
            }
            cand[j] = valid;
        }
        int mx = -1;
        for(int j=0;j<f;j++) if(cand[j]) mx = max(mx,freq[j]);
        for(int j=0;j<f;j++){
            if(cand[j] && freq[j] == mx){
                for(int k=0;k<N;k++) printf("%lld", num[j][k]); printf("\n");
                break;
            }
        }
    }
    return 0;
}
