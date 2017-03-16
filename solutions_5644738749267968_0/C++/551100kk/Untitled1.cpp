#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> ans;
struct P{
    int x,y,val;
    friend bool operator < (P a,P b){
        return a.val>b.val;
    }
};
priority_queue<P> que;
int n,m,d[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int used[55][55];
char s[55][55];
int check(int x,int y){
    int tmp=0,i,X,Y;
    for(i=0;i<8;i++){
        X=x+d[i][0];
        Y=y+d[i][1];
        if(X>=0 && Y>=0 && X<n && Y<m && s[X][Y]==0)
            tmp++;
    }
    return tmp;
}
void sett(int x,int y){
    int i,X,Y;
    vector<P> tmp;
    for(i=0;i<8;i++){
        X=x+d[i][0];
        Y=y+d[i][1];
        if(X>=0 && Y>=0 && X<n && Y<m && s[X][Y]==0){
            s[X][Y]='.';//printf("(%d,%d,)",X,Y);
            tmp.push_back((P){X,Y,1});
        }
    }
    for(i=0;i<tmp.size();i++){
        tmp[i].val=check(tmp[i].x,tmp[i].y);
        que.push(tmp[i]);
    }
}
int main(){
    //freopen("B-large.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,i,j,x,y,C=0;
    scanf("%d",&t);
    while(t--){
        int flag=0,res;
        scanf("%d%d%d",&n,&m,&x);
        while(que.size()) que.pop();
        if(n>m) swap(n,m),flag=1;
        memset(s,0,sizeof(s));
        memset(used,0,sizeof(used));
        res=n*m-x-1;
        s[0][0]='c';
        que.push((P){0,0,check(0,0)});//printf("%d..",check(0,0));
        while(res && que.size()){
            P in=que.top();
            que.pop();
            if(in.val!=check(in.x,in.y)){
                in.val=check(in.x,in.y);
                que.push(in);
                continue;
            }
            if(in.val>res || used[in.x][in.y]) continue;
            used[in.x][in.y]=1;
            res-=in.val;
            sett(in.x,in.y);
            for(i=0;i<n;i++){
                    for(j=0;j<m;j++)
                        putchar(s[i][j]);
                    puts("");
                }
        }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                if(s[i][j]==0)
                    s[i][j]='*';

        printf("Case #%d:\n",++C);
        res=0;
        if(res) puts("Impossible");
        else{
            if(flag==0){
                for(i=0;i<n;i++){
                    for(j=0;j<m;j++)
                        putchar(s[i][j]);
                    puts("");
                }
            }
            else{
                for(i=0;i<m;i++){
                    for(j=0;j<n;j++)
                        putchar(s[j][i]);
                    puts("");
                }
            }
        }
    }
}
