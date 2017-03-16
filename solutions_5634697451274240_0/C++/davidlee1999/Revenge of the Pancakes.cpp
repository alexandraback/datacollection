#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int main()
{
    int T,test,n,now,i;
    string s;
    freopen("Bsmall0.in","r",stdin);
    freopen("Bsmall0.out","w",stdout);
    cin>>T;
    for(test=1;test<=T;test++)
    {
        printf("Case #%d: ",test);
        cin>>s;
        n=s.size();
        now=0;
        for(i=1;i<n;i++)
            if(s[i]!=s[i-1])
                now++;
        if(s[n-1]=='-')
            now++;
        cout<<now<<endl;
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
