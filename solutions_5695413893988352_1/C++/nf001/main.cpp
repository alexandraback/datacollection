#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
#define inf 0x3f3f3f3f
#define N 1001
#define ll long long
#define M 2002
#define mm 1000000007

ll pp[19],mx=(1ull<<63)-1;
int len,c[20],j[20];
char C[20],J[20],ansC[20],ansJ[20];
void dfs(int i,int tp,ll v){
    if (i==len){
        if (abs(v)<mx){
            mx =abs(v);
            for (int i=0;i<len;i++){
                ansC[i]=C[i];
                ansJ[i]=J[i];
            }
        }
        return;
    }
    if (tp==1) {
        if (c[i] == 1) C[i]='0';
        if (j[i] == 1) J[i]='9';
        dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
    }
    if (tp==-1) {
        if (c[i] == 1) C[i]='9';
        if (j[i] == 1) J[i]='0';
        dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
    }
    if (tp==0) {
        if (c[i] == 1 && j[i] == 1) {
            C[i]='0';J[i]='0';tp=0;
            dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
            C[i]='0';J[i]='1';tp=-1;
            dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
            C[i]='1';J[i]='0';tp=1;
            dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
        }
        else if (c[i]==1){
                if (J[i]>'0'){
                C[i]=J[i]-1;tp=-1;
                dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
            }
            C[i]=J[i];tp=0;
            dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
            if (J[i]<'9'){
                C[i]=J[i]+1;tp=1;
                dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
            }
        }
        else if (j[i]==1){
            if (C[i]>'0'){
                J[i]=C[i]-1;tp=1;
                dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
            }
            J[i]=C[i];tp=0;
            dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);

            if (C[i]<'9'){
                J[i]=C[i]+1;tp=-1;
                dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
            }
        }
        else {
            if (C[i]<J[i]) tp =-1;
            if (C[i]==J[i]) tp =0;
            if (C[i]>J[i]) tp =1;
            dfs(i+1,tp,v+C[i]*pp[i]-J[i]*pp[i]);
        }
    }
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int T,cas=0;
    cin>>T;
    while (T--){
        memset(c,0,sizeof c);
        memset(j,0,sizeof j);
        mx=(1ull<<63)-1;
        scanf("%s%s",C,J);
        len=strlen(C);
        pp[len-1]=1;
        for (int i=len-2;i>=0;i--) pp[i]=pp[i+1]*10;
        for (int i=0;i<len;i++) {
            if (J[i]=='?') j[i]=1;
            if (C[i]=='?') c[i]=1;
        }
        dfs(0,0,0ull);
        printf("Case #%d: ",++cas);
        for (int i=0;i<len;i++)  printf("%c",ansC[i]);
        printf(" ");
        for (int i=0;i<len;i++)  printf("%c",ansJ[i]);
        puts("");
    }
}
