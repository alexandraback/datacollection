#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

const int maxn=105;
const int MaxN=1000000;
const int kind=26;
const int inf=10000;
int size=0;

struct node{
    int word,fail,ch[kind];
    int pre(){
        fail=word=0;
        memset(ch,0,sizeof(ch));
        return size;
    }
}trie[MaxN];

void init(){
    size=0;
    trie[0].pre();
}
void built(char str[]){
    int p=0,k=0,idx;
    for(;str[k];k++){
        idx=str[k]-'A';
        if(trie[p].ch[idx]==0) trie[p].ch[idx]=trie[++size].pre();
        p=trie[p].ch[idx];
    }
    trie[p].word++;
}

void BFS_AC(){
    queue<int>Q; Q.push(0);
    int temp,son,p;
    while(Q.size()){
        temp=Q.front();Q.pop();
        p=trie[temp].fail;
        for(int i=0;i<kind;i++){
            if(trie[temp].ch[i]>0){
                son=trie[temp].ch[i];
                Q.push(son);
                if(temp==0)continue;
                trie[son].fail=trie[p].ch[i];
            }
            else{
                if(temp==0)continue;
                trie[temp].ch[i]=trie[p].ch[i];
            }
        }
    }
}

int k,l,s;
char str[maxn];
double p[kind];
int f[kind];
double dp[maxn][maxn];
int dp2[maxn][maxn];

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    static int T,Cas;
    scanf("%d",&T);
    for(Cas=1;Cas<=T;Cas++){
        static int i,j;
        for(i=0;i<26;i++)
            f[i]=0;
        scanf("%d%d%d",&k,&l,&s);
        scanf("%s",str);
        for(i=0;i<k;i++)
            f[(int)(str[i]-'A')]++;
        for(i=0;i<kind;i++)
            p[i]=f[i]/(double)k;
        scanf("%s",str);
        init();
        built(str);
        BFS_AC();
        static double ans;
        for(i=0;i<=s;i++)
        for(j=0;j<=size;j++)
            dp[i][j]=0.0;
        dp[0][0]=1.0;
        ans=0;
        for(i=0;i<=s;i++){
            ans+=dp[i][size];
            for(j=0;j<=size;j++)
            for(k=0;k<26;k++)
                dp[i+1][trie[j].ch[k]]+=dp[i][j]*p[k];
        }
        static int ans2;
        ans2=0;
        for(i=0;i<=s;i++)
        for(j=0;j<=size;j++)
            dp2[i][j]=-inf;
        dp2[0][0]=0;
        for(i=0;i<=s;i++){
            dp2[i][size]++;
            if(dp2[i][size]>ans2)ans2=dp2[i][size];
            for(j=0;j<=size;j++){
                for(k=0;k<26;k++)
                    if(f[k] && dp2[i+1][trie[j].ch[k]]<dp2[i][j])dp2[i+1][trie[j].ch[k]]=dp2[i][j];
            }
        }
        printf("Case #%d: %.10f\n",Cas,ans2-ans);
    }
    return 0;
}
