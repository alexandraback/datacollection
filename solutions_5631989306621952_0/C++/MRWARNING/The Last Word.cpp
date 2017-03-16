#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<string>
#include<bitset>
#define LL long long

const int MAXN=0;
const int MAXM=0;
const long long LLINF=9000000000000000000;
const int INF=2147483647;//careful because of floyed and so on
const int MOD=1000000007;
double eps=0.00000001;

using namespace std;

int T;
char s[1007];

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    string ts;
    for (int cas=1;cas<=T;cas++){
            ts="";
            scanf("%s",s);
            int len=strlen(s);
            for (int i=0;i<len;i++){
                    if (ts.length()==0 || s[i]>=ts[0]){
                            ts=s[i]+ts;
                    }
                    else{
                            ts=ts+s[i];
                    }
            }
            printf("Case #%d: ",cas);
            cout<<ts<<endl;
    }
    return 0;
}
