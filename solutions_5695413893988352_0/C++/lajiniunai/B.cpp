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
const int INF = 1e9;
char A[105], B[105];
int main() {
    freopen("data.in", "r", stdin);
    freopen("check.out", "w", stdout);
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%s%s", A, B);
        int n=strlen(A),m=strlen(B);
        int ans = INF;
        pair<int,int>ans1;
        for(int j = 0; j <= 999; j++) {
            for(int k = 0; k <= 999; k++) {
                int flag=1;
                int t=j;
                for(int i=n-1;i>=0;i--){
                    if(A[i]!='?'){
                        if(t%10!=A[i]-'0') flag=0;
                    }
                    t/=10;
                }
                if(t) flag=0;
                t=k;
                for(int i=m-1;i>=0;i--){
                    if(B[i]!='?'){
                        if(t%10!=B[i]-'0') flag=0;
                    }
                    t/=10;
                }
                if(t) flag=0;
                if(flag){
                    if(abs(j-k)<ans){
                        ans=abs(j-k);
                        ans1={j,k};
                    }
                }
            }
        }
        printf("Case #%d: ",cas++);
        char out[]="%00d %00d\n";
        out[2]=n+'0';
        out[7]=m+'0';
        printf(out,ans1.first,ans1.second);
    }
    return 0;
}
