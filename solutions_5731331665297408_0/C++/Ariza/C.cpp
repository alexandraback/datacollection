#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1
#define PI (2*acos(0.0))

int N,M;
int graph[50][50];
string POS[50];
void init(){
     for (int i=0;i<50;++i){
         POS[i]="";
         for (int j=0;j<50;++j)
             graph[i][j]=0;
     }
}
bool possible(vector<int> conf){
     int memo[10];
     memset(memo,0,sizeof(memo));
     memo[conf[0]]=1;
     bool ok;
     for (int i=1;i<N;++i){
         ok=0;
         for (int j=i-1;j>=0;--j){
             if (memo[conf[j]] && graph[conf[i]][conf[j]]){
                memo[conf[i]]=1;
                ok=1;
                break;
             }
             else{
                  memo[conf[j]]=0;
             }
         }
         if (!ok) return 0;
     }
     return 1;
}
void solve(){
     init();
     printf(" ");
     scanf("%d %d",&N,&M);
     for (int i=0;i<N;++i) cin >> POS[i];
     int a,b;
     for (int i=0;i<M;++i){
         scanf("%d %d",&a,&b);
         a--; b--;
         graph[a][b]=graph[b][a]=1;
     }
     vector<int>permut;
     for (int i=0;i<N;++i) permut.pb(i);
     string str;
     string ans="";
     for (int i=0;i<N;++i) ans+="99999";
     do{
        if (possible(permut)){
           str="";
           for (int i=0;i<N;++i){
               str+=POS[permut[i]];
           }
           if (str<ans) ans=str;
        }
     }while (next_permutation(permut.begin(),permut.end()));
     cout << ans << endl;
}

int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d:",test);
        solve();
    }
    return 0;
}
