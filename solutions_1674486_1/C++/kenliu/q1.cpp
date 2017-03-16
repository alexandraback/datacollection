#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#define PI 3.141592653589793
#define DEBUG 0
#define INF 1000000007 

using namespace std;

int n,K,cases=1;
vector<int>egs[1001];
bool used[1001][1001];
bool p[1001];
bool DFS(int prev, int current,int len){
    if(p[current])return true;
    if(DEBUG)printf("p = %d\n",current);
    p[current]=1; 
    int i,a=current,b;
    for(i=0;i<egs[a].size();i++){
        b=egs[a][i];
        if(!used[a][b]){
            used[a][b]=1;
            if(DFS(current,b,len+1))return true;
        }
    }
    return false;
}
void getNum(){
    int i;
    for(i=1;i<=K;i++){
        memset(p,0,sizeof(p));
        memset(used,0,1001*1001);
        if(DEBUG)printf("%d:\n", i);
        if(DFS(i,i,0)){printf("Case #%d: Yes\n",cases);return;}
    }
    printf("Case #%d: No\n",cases);
}
void init(){
    int i;
    for(i=0;i<1001;i++)
        egs[i].clear();
}
int main(){
    int i,j,k,b,c;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&K);
        for(j=1;j<=K;j++){
            scanf("%d",&b);
            for(k=0;k<b;k++){
                scanf("%d",&c);
                egs[j].push_back(c);
            }
        }
        getNum();
        init();
        cases++;
    }
            
    return 0;
}
