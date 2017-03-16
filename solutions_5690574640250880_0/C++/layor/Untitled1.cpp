
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define clr(a) memset(a,0,sizeof(a))
typedef pair<int,int> ii;
bool vis[60][60],ok[60][60];
int cnt[60][60];
int t,ca;
int r,c,m,mm;
char ans[60][60];
const char* im="Impossible";
queue<ii>q;
int a[30];
int dx[]={-1,-1,0,-1,1,0,1,1};
int dy[]={-1,0,-1,1,-1,1,0,1};

inline int getone(int i){
    int ret=0;
    while(i){
        ret++;
        i-=i&(-i);
    }
    return ret;
}
inline bool check(int x,int y){
    while(!q.empty()) q.pop();
    clr(vis),clr(ok),clr(cnt);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(ans[i][j]=='.'){
                for(int k=0;k<8;k++){
                    int a=i+dx[k];
                    int b=j+dy[k];
                    if(a>=0 && a<r && b>=0 && b<c && ans[a][b]=='*'){
                            cnt[i][j]++;
                    }
                }
            }
        }
    }
    if(cnt[x][y]!=0){
        return 0;
    }
    ok[x][y]=1;
    vis[x][y]=1;
    ii vn,vw;
    vn=make_pair(x,y);
    q.push(vn);
    while(!q.empty()){
        vn=q.front();q.pop();
        for(int i=0;i<8;i++){
            int a=vn.first+dx[i];
            int b=vn.second+dy[i];
            if(a>=0 && a<r && b>=0 && b<c && !vis[a][b] && ans[a][b]=='.'){
                vis[a][b]=1;
                ok[a][b]=1;
                if(cnt[a][b]==0){
                    vw=make_pair(a,b);
                    q.push(vw);
                }
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(ans[i][j]=='.' && ok[i][j]==0) return 0;
        }
    }
    return 1;
}
int main(){
    freopen("C-small-attempt3.in","r",stdin);
    freopen("out1.txt","w",stdout);
    scanf("%d",&t);
    ca=1;
    while(t--){
        //while(!q.empty()) q.pop();
        scanf("%d%d%d",&r,&c,&m);
        printf("Case #%d:\n",ca++);
        if(m+1==r*c){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(i==0&&j==0) putchar('c');
                    else putchar('*');
                }
                puts("");
            }
            continue;
        }
        mm=1<<(r*c);
        int rc=r*c;
        int tag=0;
        for(int i=0;i<mm && !tag;i++){
            if(getone(i)!=m){
                continue;
            }
            else{
                int b=0;
                for(int j=0;j<rc;j++){
                    if(i&(1<<j)){
                        ans[j/c][j%c]='*';
                    }
                    else{
                        ans[j/c][j%c]='.';
                        a[b++]=j;
                    }
                }
                for(int j=0;j<b;j++){
                    if(check(a[j]/c,a[j]%c)){
                        ans[a[j]/c][a[j]%c]='c';
                        for(int ii=0;ii<r;ii++){
                            for(int jj=0;jj<c;jj++){
                                putchar(ans[ii][jj]);
                            }
                            puts("");
                        }
                        tag=1;break;
                    }
                }
            }
        }
        if(!tag){
            puts(im);
        }
    }
    return 0;
}


