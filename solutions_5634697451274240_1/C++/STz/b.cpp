#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
#define N 111111
#define M 222222
#define md 1000000007
#define ll long long

int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int s=1;s<=t;s++){
        int ans = 0;
        char m[111];
        scanf("%s",&m);
        for(int i=0;;i++) if(m[i+1]==0){ m[i+1]='+', m[i+2]=0; break; }
        for(int i=1;m[i];i++) if(m[i-1] != m[i]) ans++;
        printf("Case #%d: %d\n",s,ans);
    }
}