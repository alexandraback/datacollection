#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
char ch[20],ch1[20];
int ans = 1000000,sa,sb;
void dfs(int a,int b,int k) {
    if(k == N) {
        int x = a - b;
        if(x < 0) x = -x;
        if(x < ans) {
            ans = x;
            sa = a;sb = b;
        }
        else if(x == ans) {
            if(a < sa) {
                sa = a;sb = b;
            }
            else if(a == sa){
                sb = min(b,sb);
            }
        }
        return ;
    }
    for(int i=0;i<10;i++) {
        if(ch[k] == '?' || ch[k] == i + '0') {
            for(int j=0;j<10;j++) {
                if(ch1[k] == '?' || ch1[k] == j + '0') {
                    dfs(a*10+i,b*10+j,k+1);
                }
            }
        }
    }
}
void prt(int a){
    char cc[20];
    for(int i=N - 1;i>=0;i--) {
        cc[i] = (a % 10) + '0';
        a /= 10;
    }
    printf(" ");
    for(int i=0;i<N;i++) {
        printf("%c",cc[i]);
    }
}
int main(){
    freopen("B.in","r",stdin);
    freopen("Bdata.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        scanf("%s%s",ch,ch1);
        N = strlen(ch);
        ans = 1000000;
        dfs(0,0,0);
        //cout<<"AA"<<endl;
        printf("Case #%d:",tt);
        prt(sa);prt(sb);
        printf("\n");
    }
    return 0;
}
