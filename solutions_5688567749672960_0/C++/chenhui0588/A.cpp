#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000010;
int H[MAXN];
queue<int>Q;
void BFS(){
    while(!Q.empty()) Q.pop();
    memset(H,-1,sizeof(H));
    H[1] = 1;
    Q.push(1);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();

        if(x+1<MAXN &&H[x+1]==-1){
            H[x+1] = H[x] + 1;
            Q.push(x+1);
        }

        int y = 0;
        int t = x;
        while(t){
            y = y*10 + t%10;
            t/=10;
        }

        if(y<MAXN &&H[y]==-1){
            H[y] = H[x] + 1;
            Q.push(y);
        }
    }

//    for(int i=2; i<1000000; ++i){
//        if(H[i]!=H[i-1]+1)
//            printf("%d %d\n",i,H[i]);
//    }
//    printf("%d\n",H[MAXN-1]);
}
int main(){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int T,ca=1;
    scanf("%d",&T);
    BFS();
    while(T--){
        int x;
        scanf("%d",&x);
        printf("Case #%d: %d\n",ca++,H[x]);
    }

    return 0;
}
