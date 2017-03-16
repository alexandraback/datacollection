/*
*Rainto96
*Beijing University of Posts and Telecommunications School of Software Engineering
*http://blog.csdn.net/u011775691
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define VINT vector<int>
#define PII pair<int,int>
#define MP(x,y) make_pair((x),(y))
#define ll long long
#define ull unsigned long long
#define MEM0(x)  memset(x,0,sizeof(x))
#define scand(x) scanf("%d",&x)
#define Max(a,b) a=max(a,b)
vector<int > tmp;
int rever(int x){
        tmp.clear();
        while(x){
                tmp.pb(x%10);
                x/=10;
        }
        int sum=0;
        for(auto& m:tmp){
                sum=sum*10+m;
        }
        return sum;
}
int bfs(int x){
        queue<PII > q;
        vector<bool> vis(1011111);
        q.push(MP(1,1));
        vis[1]=true;
        while(!q.empty()){
                PII nowP=q.front();q.pop();
                if(nowP.first==x) return nowP.second;
                int now=nowP.first , step=nowP.second;
                if(!vis[now+1]){
                        vis[now+1]=true;
                        q.push(MP(now+1,step+1));
                }
                int reverNow=rever(now);
                if(!vis[reverNow]){
                        vis[reverNow]=true;
                        q.push(MP(reverNow,step+1));
                }
        }
        return -1;
}
int main(){
        #ifndef ONLINE_JUDGE
                //freopen("in.txt","r",stdin);
                //freopen("A-small-attempt0.out","w",stdout);
        #endif // ONLINE_JUDGE
        int T;scand(T);
        for(int t=1;t<=T;t++){
                int x;scand(x);
                int step=bfs(x);
                printf("Case #%d: ",t);
                if(step!=-1) cout<<step<<endl;
                else cout<<"cant!"<<endl;
        }
        return 0;
}
