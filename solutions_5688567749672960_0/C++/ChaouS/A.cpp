#include <bits/stdc++.h>


using namespace std;
const int N = 1000006;
const long long inf = (long long)1e14;


long long voltear(long long x){

    long long res = 0;
    while(x > 0){
        res = res * 10 + (x % 10);
        x/=10;
    }
    return res;

}

int d[N];
int main(){

   freopen("/home/docente/A-small-attempt0.in","r",stdin);
   freopen("on.c","w",stdout);

 //  freopen("in.c","r",stdin);

    memset(d,-1,sizeof d);

    d[1] = 1;
    queue<long long> q;
    q.push(1);

    while(!q.empty()){
        int u = q.front(); q.pop();

        if( u + 1 < N ){
            if(d[u+1]==-1 || 1 + d[u] < d[u+1]){
                d[u+1] = 1 + d[u];
                q.push(u+1);
            }
        }
        long long v = voltear(u);
        if(v < N){
            if(d[v] == -1 || 1 + d[u] < d[v]){
                d[v] = 1 + d[u];
                q.push(v);
            }
        }
    }

    int tc , nc = 1;
    cin >> tc;

    while(tc--){
        int x;
        cin >> x;
        printf("Case #%d: %d\n",nc++,d[x]);
    }






	return 0;
}




