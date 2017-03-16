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
int p[1005];
int cao(int x,int val)
{
    if(val<=x) return 0;
    return (val-1)/x;
}
int main()
{
    freopen("B-small-attempt1.in" , "r" , stdin);
    freopen("B-small-attempt1.out" , "w" , stdout);
    int t,cnt=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
       /* priority_queue<int>q;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            q.push(x);
        }
        int time=0;
        while(!q.empty()){
            int cur=q.top();
            q.pop();
            ans=min(ans,cur+time);
            if(cur==1) break;
            time++;
            q.push(cur/2);
            q.push(cur-cur/2);
        }*/
        int m=0;
        for(int i=0;i<n;i++){
            scanf("%d",&p[i]);
            m=max(m,p[i]);
        }
        int ans=INF;
        for(int i=1;i<=m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=cao(i,p[j]);
            }
            sum+=i;
            ans=min(ans,sum);
        }
        printf("Case #%d: %d\n",++cnt,ans);
    }
    return 0;
}
