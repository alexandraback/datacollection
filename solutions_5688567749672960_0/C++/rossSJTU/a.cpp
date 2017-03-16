#include<stdio.h>
#include<queue>
using namespace std;
int ss[15];
int rev(int x)
{
    int sz = 0;
    for(;x;x/=10){
        ss[sz++] = x%10;
    }
    int res = 0;
    for(int i =0;i<sz;i++){
        res =res*10+ss[i];
    }
    return res;
}
int ans[1000005];
int main ()
{
    ans[1] = 1;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        if(x+1<1000005&&ans[x+1]==0){
            ans[x+1] = ans[x]+1;
            Q.push(x+1);
        }
        int y = rev(x);
        if(y<1000005&&ans[y]==0){
            ans[y] = ans[x]+1;
            Q.push(y);
        }
    }
    int T,n;
    scanf("%d",&T);
    for(int _ = 1;_<=T;_++){
        scanf("%d",&n);
        printf("Case #%d: %d\n",_,ans[n]);
    }
    
    return 0;
}