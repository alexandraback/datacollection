#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int cons= 1000000;

int n;
int a[cons+5], rev[cons+5];
queue<int> q;

void build(){
    for(int i=1;i<=cons;i++){
        int x= i, y= 0;
        while(x!=0){
            y= y*10+ (x%10);
            x/= 10;
        }
        rev[i]= y;
    }
    //
    memset(a, -1, sizeof a); a[1]= 1; q.push(1);
    while(!q.empty()){
        int x= q.front(); q.pop();
        if(x+1<=cons && a[x+1]==-1){
            a[x+1]= a[x]+1;
            q.push(x+1);
        }
        int y= rev[x];
        if(a[y]==-1){
            a[y]= a[x]+1;
            q.push(y);
        }
    }
}

int main(){
    freopen("A(small).in","r",stdin);
    freopen("A(small).out","w",stdout);

    build();

    int test; scanf("%d", &test);
    for(int timer=1;timer<=test;timer++){
        scanf("%d", &n);
        printf("Case #%d: %d\n", timer, a[n]);
    }

    return 0;
}
