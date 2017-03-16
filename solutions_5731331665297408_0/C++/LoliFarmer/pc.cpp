#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,m;
vector<int> conn[10];
int ans[10];
int now[10];
int go[10];
int back[10][10];
int num[10];
void DFS(int np, int ok){
    if(ok==n){
        int flag = 0;
        if(ans[0] == -1){
            flag = 1;
        }else{
            for(int i=0;i<n && flag ==0;i++){
                if(now[i] < ans[i]){
                    flag = 1;
                }
                if(now[i] > ans[i]){
                    break;
                }
            }
        }
        if(flag == 1){
            for(int i=0;i<n;i++){
                ans[i] = now[i];
            }

        }    
        /*
            fprintf(stderr, "@");
            for(int i=0;i<n;i++){
                fprintf(stderr,"%d",ans[i]);
            }
            fprintf(stderr, "\n");
            */
        return;
    }
    if(ans[0] != -1){
        int flag = 0;
        for(int i=0;i<ok;i++){
            if(now[i] < ans[i]){
                break;
            }
            if(now[i] > ans[i]){
                flag = 1;
            }
        }
        if(flag){
            return;
        }
    }
    int Size = conn[np].size();
    for(int i=0;i<Size;i++){
        int nxp = conn[np][i];
        if( go[nxp] == 0 ){
            back[nxp][np]++;
            now[ok] = num[nxp];
            go[nxp] = 1;
            DFS(nxp, ok+1);
            go[nxp] = 0;
            back[nxp][np]--;
        }
        if( back[np][nxp] ){
            back[np][nxp]--;
            DFS(nxp, ok);
            back[np][nxp]++;
        }
    }
}



int main(){
    int T;
    scanf("%d",&T);
    int a,b;
    for(int f=1;f<=T;f++){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            conn[i].clear();
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            conn[a].push_back(b);
            conn[b].push_back(a);
        }
        memset(go,0,sizeof(go));
        memset(back,0,sizeof(back));
        ans[0] = -1;
        for(int i=1;i<=n;i++){
            go[i] = 1;
            now[0] = num[i];
            DFS(i, 1);
            go[i] = 0;
        }
        printf("Case #%d: ", f);
        for(int i=0;i<n;i++)
            printf("%d", ans[i]);
        printf("\n");
    }
}
