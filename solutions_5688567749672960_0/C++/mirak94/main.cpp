#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#define MOD 1000000007
#define MAXN 25

using namespace std;
int t;
int dist[10000100];
int n,m;
typedef pair<int, int>  ii;
int get_len(int num){
    int ret =0;
    while (num) {
        ret++;
        num/=10;
    }
    return ret;
}
int rev_num(int num){
    int pw=1;
    for (int i =0; i<get_len(num)-1; i++) {
        pw*=10;
    }
    int ret=0;
    while (num) {
        ret+=(pw*(num%10));
        num/=10;
        pw/=10;
    }
    return ret;
}

void bfs(){
    for(int i =0;i<=n;i++){
        dist[i]=1000000000;
    }
    dist[1]=0;
    priority_queue<ii,vector<ii > ,greater<ii> >pq;
    pq.push(ii(0,1));
    
    while(!pq.empty()){
        ii front = pq.top();
        pq.pop();
        int u = front.second;
        int d = front.first;
        if(d==dist[u]){
            int v1 = u+1;
            int v2 = rev_num(u);
            vector<int>vs;
            vs.push_back(v1);
            vs.push_back(v2);
            for(int i =0;i<vs.size();i++){
                int v = vs[i];
                if(dist[u]+1<dist[v]){
                    dist[v]=dist[u]+1;
                    pq.push(ii(dist[v],v));
                }
            }
        }
    }
    
}
int main (){
    freopen("/Users/Masoud/Desktop/in.txt", "r", stdin);
    freopen("/Users/Masoud/Desktop/out.txt", "w", stdout);
    scanf("%d",&t);
    int ca =1;
    while(t--){
        scanf("%d",&n);
        memset(dist, 0, sizeof(dist));
        bfs();
        printf("Case #%d: %d\n",ca++,dist[n]+1);
    }
    
    return 0;
}