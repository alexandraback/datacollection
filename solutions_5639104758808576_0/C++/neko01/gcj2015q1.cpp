/**
 * @author neko01
 */
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define clr(a) memset(a,0,sizeof a)
#define clr1(a) memset(a,-1,sizeof a)
#define dbg(a) printf("%d\n",a)
typedef pair<int,int> pp;
const double eps=1e-9;
const double pi=acos(-1.0);
const int INF=0x3f3f3f3f;
const LL inf=(((LL)1)<<61)+5;
string s;
int main()
{
    int t,cnt=0;
    freopen("A-small-attempt0.in" , "r" , stdin);
    freopen("A-small-attempt0.out" , "w" , stdout);
    scanf("%d",&t);
    while(t--){
        int S;
        cin>>S>>s;
        int ans=0,sum=s[0]-'0';
        for(int i=1;i<=S;i++){
            if(sum<i){
                ans+=i-sum;
                sum+=i-sum;
            }
            sum+=s[i]-'0';
        }
        printf("Case #%d: %d\n",++cnt,ans);
    }
    return 0;
}
