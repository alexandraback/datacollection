#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
char ch[20],ch1[20];
const long long oo = (1LL<<60) - 10;
long long ans,sa,sb;
void dfs(long long a,long long b,int k) {
    if(k == N) {
        long long x = a - b;
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
    if(a > b) {
        if(ch[k] == '?') a *= 10;
        else a = a * 10 + (ch[k] - '0');
        if(ch1[k] == '?') b = b * 10 + 9;
        else b = b * 10 + (ch1[k] - '0');
        dfs(a,b,k + 1);
    }
    else if(a < b) {
        if(ch[k] == '?') a = a*10 + 9;
        else a = a * 10 + (ch[k] - '0');
        if(ch1[k] == '?') b *= 10;
        else b = b * 10 + (ch1[k] - '0');
        dfs(a,b,k + 1);
    }
    else {
        if(ch[k] == '?' && ch1[k] == '?') {
            dfs(a * 10 , b * 10 , k + 1);
            dfs(a * 10 + 1, b * 10 , k + 1);
            dfs(a * 10 , b * 10 + 1 , k + 1);
        }
        else if(ch[k] != '?' && ch1[k] == '?') {
            long long d = ch[k] - '0';
            if(d > 0) dfs(a * 10 + d , b * 10 + d - 1 , k + 1);
            dfs(a * 10 + d , b * 10 + d , k + 1);
            if(d < 9) dfs(a * 10 + d , b * 10 + d + 1 , k + 1);
        }
        else if(ch[k] == '?' && ch1[k] != '?') {
            long long d = ch1[k] - '0';
            if(d > 0) dfs(a * 10 + d - 1 , b * 10 + d , k + 1);
            dfs(a * 10 + d , b * 10 + d , k + 1);
            if(d < 9) dfs(a * 10 + d + 1 , b * 10 + d , k + 1);
        }
        else {
            long long d = ch[k] - '0';long long d1 = ch1[k] - '0';
            dfs(a * 10 + d , b * 10 + d1 , k + 1);
        }
    }
}
void prt(long long a){
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
    freopen("BL.in","r",stdin);
    freopen("BLdata.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++){
        scanf("%s%s",ch,ch1);
        N = strlen(ch);
        ans = oo;
        dfs(0,0,0);
        //cout<<"AA"<<endl;
        printf("Case #%d:",tt);
        prt(sa);prt(sb);
        printf("\n");
    }
    return 0;
}
