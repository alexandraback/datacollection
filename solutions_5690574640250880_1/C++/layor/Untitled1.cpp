#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

#define clr(a) memset(a,0,sizeof(a))
typedef pair<int,int> ii;

const char* im="Impossible";
int num[60][60];
int cnt[60][60];
bool vis[60][60],ok[60][60];
int ca,t,r,c,m,mm;
char ans[60][60];
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={-1,-1,-1,0,0,1,1,1};
queue<ii>q;

inline void init(){
    for(int i=1;i<60;i++){
        for(int j=1;j<60;j++){
            num[i][j]=i*j;
        }
    }
}

inline void Do(){
    clr(cnt);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(ans[i][j]=='.'){
                for(int k=0;k<8;k++){
                    int a=i+dx[k];
                    int b=j+dy[k];
                    if(a>=1 && a<=r && b>=1 && b<=c && ans[a][b]=='*'){
                            cnt[i][j]++;
                    }
                }
            }
        }
    }
}

inline bool check(int x,int y){
    while(!q.empty()) q.pop();
    clr(vis),clr(ok);
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
            if(a>=1 && a<=r && b>=1 && b<=c && !vis[a][b] && ans[a][b]=='.'){
                vis[a][b]=1;
                ok[a][b]=1;
                if(cnt[a][b]==0){
                    vw=make_pair(a,b);
                    q.push(vw);
                }
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(ans[i][j]=='.' && ok[i][j]==0) return 0;
        }
    }
    return 1;
}

inline void Print(){
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            putchar(ans[i][j]);
        }
        puts("");
    }
}
int main(){
    freopen("C-large.in","r",stdin);
    freopen("ooo.out","w",stdout);
    init();
    ca=1;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&r,&c,&m);
        mm=r*c-m;
        printf("Case #%d:\n",ca++);
        if(m==r*c-1){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(i==0 && j==0) putchar('c');
                    else putchar('*');
                }
                putchar('\n');
            }
            continue;
        }
        if(m==0){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(i==0 && j==0) putchar('c');
                    else putchar('.');
                }
                putchar('\n');
            }
            continue;
        }
        int tag=1;
        for(int i=0;tag&&i<=r;i++){
            for(int j=0;tag&&j<=c;j++){
                for(int k=i;tag&&k<=r;k++){
                    for(int p=0;tag&&p<=j;p++){
                        if(num[i][j]+num[k][p]-num[i][p] == m){
                            for(int ii=1;ii<=r;ii++){
                                for(int jj=1;jj<=c;jj++){
                                    ans[ii][jj]='.';
                                }
                            }
                            for(int ii=1;ii<=i;ii++){
                                for(int jj=1;jj<=j;jj++){
                                    ans[ii][jj]='*';
                                }
                            }
                            for(int ii=1;ii<=k;ii++){
                                for(int jj=1;jj<=p;jj++){
                                    ans[ii][jj]='*';
                                }
                            }
                            Do();
                            if(check(r,c)){
                                ans[r][c]='c';
                                Print();
                                tag=0;
                            }
                        }
                    }
                }
            }
        }
        if(tag){
            for(int i=0;tag&&i<=r;i++){
                for(int j=0;tag&&j<=c;j++){
                    for(int k=i;tag&&k<=r;k++){
                        for(int p=0;tag&&p<=j;p++){
                            if(num[i][j]+num[k][p]-num[i][p] == mm){
                                for(int ii=1;ii<=r;ii++){
                                    for(int jj=1;jj<=c;jj++){
                                        ans[ii][jj]='*';
                                    }
                                }
                                for(int ii=1;ii<=i;ii++){
                                    for(int jj=1;jj<=j;jj++){
                                        ans[ii][jj]='.';
                                    }
                                }
                                for(int ii=1;ii<=k;ii++){
                                    for(int jj=1;jj<=p;jj++){
                                        ans[ii][jj]='.';
                                    }
                                }
                                Do();
                                if(check(1,1)){
                                    ans[1][1]='c';
                                    Print();
                                    tag=0;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(tag) puts(im);
    }
    return 0;
}
