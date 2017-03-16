#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
bool s[55][55];
int r,c,m;
int gi[4]={0,1,0,-1},gj[4]={1,0,-1,0};
int ai[8]={-1,-1,-1,0,0,1,1,1},aj[8]={-1,0,1,-1,1,-1,0,1};
bool in(int i, int j) {
    if(i<0 || i>=r) return false;
    if(j<0 || j>=c) return false;
    return true;
}
bool check(int i,int j) {
    if(!in(i,j)) {
        return false;
    }
    return !s[i][j];
}
bool make() {
    memset(s,1,sizeof(s));
        int res = r * c - m;
        int k = 1;
        while(k*k<=res && (k+1)<=r && (k+1)<=c) {
            if((k+1)*(k+1)>res) {
                break;
            }
            k++;
        }
        for(int i=0;i<k;i++) {
            for(int j=0;j<k;j++) {
                s[i][j]=0;
            }
        }
        int tr = k , tc = k;
        res -= k*k;
        if(res>0) {
            if(res >= tr) {
                if(tc<c) {
                    int ff = min(res/tr, c-tc);
                    res -= ff * tr;
                    for(int i=0;i<tr;i++)
                    for(int j=tc;j<tc+ff;j++) {
                        s[i][j] = 0;
                    }
                    tc += ff;
                }
            }
            if(res >= tc) {
                if(tr<r) {
                    int ff = min(res/tc, r-tr);
                    res -= ff * tc;
                    for(int i=tr;i<tr+ff;i++)
                    for(int j=0;j<tc;j++) {
                        s[i][j] = 0;
                    }
                    tr += ff;
                }
            }
        }
        if(res > 0) {
            if(tc<c) {
                if(res > 1) {
                    for(int i=0;i<res;i++) {
                        s[i][tc] = 0;
                    }
                } else {
                    s[tr-1][tc-1] = 1;
                    s[0][tc] = 0;
                    s[1][tc] = 0;
                }
            } else {
                if(res > 1) {
                    for(int i=0;i<res;i++) {
                        s[tr][i] = 0;
                    }
                } else {
                    s[tr-1][tc-1] = 1;
                    s[tr][0] = 0;
                    s[tr][1] = 0;
                }
            }
        }
    return true;
}
bool goo(int st) {
    bool use[50][50]={0};
    queue<int> clk;
    clk.push(st);
    use[st/c][st%c]=1;
    while(clk.size()) {
        int x = clk.front()/c,y = clk.front()%c;
        clk.pop();
        int mine=0;
        for(int i=0;i<8;i++) {
            int tx = x+ai[i],ty = y+aj[i];
            if(in(tx,ty) && s[tx][ty]) {
                mine++;
                break;
            }
        }
        if(!mine) {
            for(int i=0;i<8;i++) {
                int tx = x+ai[i],ty = y+aj[i];
                if(!use[tx][ty] && check(tx,ty)) {
                    clk.push(tx*c+ty);
                    use[tx][ty]=1;
                }
            }
        }
    }
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(s[i][j]==0 && use[i][j]==0) {
                return false;
            }
        }
    }
    return true;
}
int judge() {
    queue<int> Q;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(!s[i][j]) {
                Q.push(i*c+j);
            }
        }
    }
    while(Q.size()) {
        int c = Q.front();
        Q.pop();
        if(goo(c)) {
            return c;
        }
    }
    return -1;
}
int main() {
    freopen("/Users/liverliu/Documents/codejam/C-large.in","r",stdin);
    freopen("/Users/liverliu/Documents/codejam/C-large.out","w",stdout);
    int T=0,cas=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&r,&c,&m);
        printf("Case #%d:\n",++cas);
        if(!make()) {
            puts("Impossible");
            continue;
        }
        /*
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++){
                printf("%d",s[i][j]);
            }
            puts("");
        }
        */
        int ans = judge();
        if(ans != -1) {
            int x = ans / c, y = ans % c;
            for(int i=0;i<r;i++) {
                for(int j=0;j<c;j++) {
                    if(s[i][j]) {
                        putchar('*');
                    } else if(i==x && j==y) {
                        putchar('c');
                    } else {
                        putchar('.');
                    }
                }
                puts("");
            }
        } else {
            puts("Impossible");
        }
    }
    return 0;
}
