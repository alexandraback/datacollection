#include<cstdio>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include<string>
#include<sstream>
#include<cassert>
#include<ctime>
#include<cmath>

#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

using namespace std;
int height[1500],nheight[1500];
bool ch[1500];
int d[20],n[20],w[20],e[20],s[20],da_d[20],da_p[20],da_s[20];
struct event{
    int day;
    int w,e;
    int h;
    event(int d,int ww,int ee,int height){
        day=d,w=ww,e=ee,h=height;
    }
};
struct s_cmp{
    bool operator()(const event &a, const event &b) const{
        return a.day < b.day;
    }
};
int ans;
bool process(event t){
    bool f=false;
    for(int i=t.w+500;i<=t.e+500;i++){
        assert(i>=0 && i<=1000);
        if(height[i]<t.h){
            nheight[i]=max(nheight[i],t.h);
            ch[i]=true;
            f=true;
        }
    }
    if(f){
        ans++;
        return true;
    }
    return false;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,N;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        memset(height,0,sizeof(height));
        scanf("%d",&N);
        multiset<event,s_cmp> Q;
        for(int i=0;i<N;i++){
            scanf("%d%d%d%d%d%d%d%d",&d[i],&n[i],&w[i],&e[i],&s[i],&da_d[i],&da_p[i],&da_s[i]);
            for(int j=0;j<n[i];j++){
                Q.insert(event(d[i]+da_d[i]*j,2*(w[i]+da_p[i]*j),2*(e[i]+da_p[i]*j),(s[i]+da_s[i]*j)));
            }
        }
        ans=0;
        while(!Q.empty()){
            memset(nheight,0,sizeof(nheight));
            memset(ch,0,sizeof(ch));
            event s = *(Q.begin());Q.erase(Q.begin());
            process(s);
            while(!Q.empty() && Q.begin()->day == s.day){
                event t = *(Q.begin());Q.erase(Q.begin());
                process(t);
            }
            for(int i=0;i<=1000;i++) if(ch[i]) height[i]=nheight[i];
        }
        printf("Case #%d: %d\n",I,ans);
    }
    return 0;
}

