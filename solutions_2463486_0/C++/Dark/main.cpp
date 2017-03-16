#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int,int> PII;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-11
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
#define ALL(n) n.begin(),n.end()
#define pb push_back
#define mp make_pair
#define iFor(i,n) for(typeof(n.begin()) i=n.begin();i!=n.end();i++)
bool test(LL t){
    int h[1005],len=0;
    while(t){
        h[len++] = t%10;
        t/=10;
    }
    For(i,len/2) if(h[i]!=h[len-1-i]) return false;
    return true;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int ca = 0;
    LL ans[10000],t=0;
    For(i,10000000){
        if(test(i)&&test(1LL*i*i))
            ans[t++] = 1LL*i*i;
            //cout<<i<<" "<<1LL*i*i<<endl;
    }
    scanf("%d",&ca);
    For(c, ca){
        LL A,B;
        int res = 0;
        cin>>A>>B;
        For(i,t) if(ans[i]<A) continue;
        else if(ans[i]>B) continue;
        else res++;
        printf("Case #%d: %d\n",c+1,res);
    }
}
