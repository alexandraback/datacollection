#include<stdio.h>
#include<queue>
#include<cstring>

using namespace std;

bool ud[1002];
vector<int> to[1002];

bool bfs(int start)
{
    queue<int> qq;
    memset(ud,0,sizeof(ud));
    ud[start]=true;
    qq.push(start);
    vector<int> :: iterator t;
    while(!qq.empty()){
        int tmp=qq.front();
        qq.pop();
        for(t=to[tmp].begin();t!=to[tmp].end();t++){
            if(ud[*t])return true;
            ud[*t]=true;
            qq.push(*t);
        }
    }
    return false;
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int i,cases,cc,n,mi,j,a;
    scanf("%d",&cases);
    for(cc=1;cc<=cases;cc++){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            to[i].clear();
            scanf("%d",&mi);
            for(j=1;j<=mi;j++){
                scanf("%d",&a);
                to[i].push_back(a);
            }
        }
        bool yes=false;
        for(i=1;i<=n;i++){
            if(bfs(i))yes=true;
        }
        printf("Case #%d: ",cc);
        if(yes)puts("Yes");
        else puts("No");
    }
    
    
    return 0;
}
