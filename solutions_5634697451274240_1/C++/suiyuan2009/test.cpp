#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=105;

int n;
int f[maxn][2];
char str[maxn];

void pd(int &ret,int val){
    if(ret==-1||ret>val)ret=val;
}

int main() {
    //freopen("in.cpp","r",stdin);
    freopen("B-large.in","r",stdin);
    freopen("out","w",stdout);
    int ncase=0;
    int T;
    scanf("%d",&T);
    while(T--) {
        memset(f,-1,sizeof(f));
        scanf("%s",str);
        n=strlen(str);
        f[0][0]=f[0][1]=0;
        for(int i=0;i<n;i++){
            pd(f[i+1][0],f[i][0]+2*(str[i]!='-'));
            pd(f[i+1][0],f[i][1]+1);
            pd(f[i+1][1],f[i][0]+1);
            pd(f[i+1][1],f[i][1]+2*(str[i]!='+'));
        }
        printf("Case #%d: %d\n",++ncase,f[n][1]);
    }
    return 0;
}
