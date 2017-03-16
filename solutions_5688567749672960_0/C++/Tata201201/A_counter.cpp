#include<stdio.h>
#include<map>
#include<queue>
using namespace std;
long long n=1000000;
typedef pair<long long,long long> II;
void printpath(map<long long,II> &m, long long x){
    if(x==0) return;
    printpath(m,m[x].second);
    printf("%lld ",x);
}
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    map<long long,II> m;
    priority_queue<II,vector<II>,greater<II> > pq;
    m[1]=II(1,0);
    pq.push(II(1,1));
    while(!pq.empty()){
        II temp = pq.top();
        pq.pop();
        long long curval = temp.second;
        long long curstep = temp.first;
        //printf(">>> %6d %6d >>>\n",curstep,curval);
        if(curval+1<=n && m[curval+1].first==0){
            m[curval+1] = II(curstep+1,curval);
            pq.push(II(curstep+1,curval+1));
            //printf("a   %6d %6d\n",curstep+1,curval+1);
        }
        long long rev = 0;
        while(curval > 0){
            rev *= 10;
            rev += curval % 10;
            curval /= 10;
        }
        if(rev<=n && m[rev].first==0){
            m[rev] = II(curstep+1,temp.second);
            pq.push(II(curstep+1,rev));
            //printf(" b  %6d %6d\n",curstep+1,rev);
        }
    }
    //printf("SUCCESS\n");
    /*
    while(true){
        long long x;
        scanf("%lld",&x);
        if(m[x].first==0) break;
        printf("%lld : ",x);
        printpath(m,x);
        printf("\n");
    }
    */
    int T;
    scanf("%d",&T);
    for(int tt = 1; tt <= T; tt++){
        int x;
        scanf("%d",&x);
        printf("Case #%d: %d\n",tt,m[x].first);
    }
}
