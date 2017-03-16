#pragma comment(linker, "/STACK:65536000")
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<iostream>
#include<time.h>
#include <list>
#include <numeric>
#include <complex>
#define forn(i,n) for(int i=0;i<n;i++)
#define clr(a,b) memset(a,b,sizeof(a))
#define ll long long
#define ull unsigned long long
#define lowb(i) (i&(-i))
#define bug(n,m,x) forn(i,n){forn(j,m)printf("%d ",x[i][j]);puts("");}puts("")
#define sqr(x) ((x)*(x))
using namespace std;
const int inf=1<<30;
const double eps=1e-8;
const double pi=acos(-1.0);
//const ll mod = 9223372034707292160LL;
//const double inf = 1e10;
const double E=2.718281828459;


int n,m;
int ti=1,t;
int a[1010];
int vis[1010];
struct my{
    int p,c;
    my(){};
    my(int p,int c):p(p),c(c){}
};

int get(int q,int w){
    vector<int> b;
    for(int i=1;i<=n;i++){
        if(a[i]==q&&i!=w){
            queue<my> que;
            bool vis[1010]={0};
            vis[q]=vis[w]=1;
            que.push(my(i,1));
            vis[i]=1;
            int ans=0;
            while(!que.empty()){
                my now=que.front();
                que.pop();
                ans=max(now.c,ans);
                for(int j=1;j<=n;j++)if(!vis[j]&&a[j]==now.p){
                    que.push(my(j,now.c+1));
                    vis[j]=1;
                }
            }
            b.push_back(ans);
        }
    }
    int ret=0;
    sort(b.begin(),b.end());
    if(b.size())ret+=b[b.size()-1];
    b.clear();
    for(int i=1;i<=n;i++){
        if(a[i]==w&&i!=q){
            queue<my> que;
            bool vis[1010]={0};
            vis[q]=vis[w]=1;
            que.push(my(i,1));
            vis[i]=1;
            int ans=0;
            while(!que.empty()){
                my now=que.front();
                que.pop();
                ans=max(now.c,ans);
                for(int j=1;j<=n;j++)if(!vis[j]&&a[j]==now.p){
                    que.push(my(j,now.c+1));
                    vis[j]=1;
                }
            }
            b.push_back(ans);
        }
    }
    sort(b.begin(),b.end());
    if(b.size())ret+=b[b.size()-1];
    return ret;
}

int main(){
#ifdef jordan13game
    freopen("D:\\in.txt","r",stdin);
    freopen("D:\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)cin>>a[i];
        clr(vis,0);
        int ans=0;
        map<pair<int,int>, int> mp;
        for(int i=1;i<=n;i++)if(!vis[i]){
            int num=0;
            clr(vis,0);
            vector<int> b;
            int p=i;
            int tt=1;
            while(!vis[p]){
                vis[p]=tt;
                b.push_back(p);
                p=a[p];
                tt++;
            }
            num=tt-vis[p];
            if(num==2){
                int q=b[b.size()-1],w=b[b.size()-2];
                if(w<q)swap(q,w);
                int tmp=get(q,w);
                mp[make_pair(q,w)]=tmp;
                num+=tmp;
            }
            ans=max(num,ans);
        }
        int tmp=0;
        for(map<pair<int,int>, int>::iterator it=mp.begin();it!=mp.end();it++)tmp+=it->second;
        ans=max(ans,tmp+2*(int)mp.size());
        printf("Case #%d: %d\n",ti++,ans);
    }
    return 0;
}




