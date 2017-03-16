#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A-large.in","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e3+10;

int test,n;
char s[N];
int main(){
    INPUT;OUTPUT;
    scanf("%d\n",&test);
    FOR(T,1,test){
        scanf("%d %s",&n,s);
        //printf("%d\n%s\n",n,s);
        int cur=0,ans=0;
        FOR(i,0,n) if (s[i]!='0'){
            if (cur<i) ans+=i-cur,cur=i;
            cur+=s[i]-'0';
        }
        printf("Case #%d: %d\n",T,ans);
    }
}
