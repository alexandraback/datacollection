#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
#define LL long long
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const int M = 2e3 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
char s[M];
string A[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int C[]={0,2,6,8,4,1,3,5,7,9};
char D[]={'Z','W','X','G','U','O','R','F','S','I'};
int B[26];
int ans[26];
int main() {
    freopen("data.in","r",stdin);
    freopen("check.out","w",stdout);
    int T,cas=1;
    scanf("%d",&T);
    while(T--){
        memset(B,0,sizeof(B));
        scanf("%s",s);
        int n=strlen(s);
        for(int j=0;j<n;j++){
            B[s[j]-'A']++;
        }
        for(int j=0;j<=9;j++){
            int now=C[j];
            int t=B[D[j]-'A'];
            //printf("%c %d\n",D[j],t);
            ans[now]=t;
            for(int k=0;k<A[now].size();k++){
                B[A[now][k]-'A']-=t;
            }

        }
        printf("Case #%d: ",cas++);
        for(int j=0;j<=9;j++){
            for(int k=0;k<ans[j];k++){
                printf("%d",j);
            }
        }
        printf("\n");
    }
    return 0;
}
