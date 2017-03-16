/*    brioso     */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include<set>
#include<map>
#include<queue>

using namespace std;
#define MAXN 1005
#define inf 0x3f3f3f3f
typedef long long ll ;
const double eps =1e-8;
const int mod = 1000000007;
typedef pair<int, int> P;
const double PI = acos(-1.0);

struct node{
    int j,k;
    int x;
    bool operator < (const node a) const{
        return x>a.x;
    }
};
int aa[MAXN][MAXN];
int bb[MAXN][MAXN];
int cc[MAXN][MAXN];
int d[MAXN][5];
char s[MAXN];
int dp[MAXN];
int vis[MAXN][MAXN];
int n,m;
int ans;


int main()
{
    freopen("C-small-attempt4 (2).in","r",stdin);
    freopen("2.out","w",stdout);
    int t,ca = 1;
    int p,q;
    int a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d",&a,&b,&c,&n);

        ans = 0;
        priority_queue<node> que;
        for(int i = 1 ; i <= a ; i++){
            for(int j = 1 ; j <= b ; j++){
                for(int k = 1 ; k <= c ; k++){
                    que.push(node{j,k,0});
                }
            }
            memset(aa,0,sizeof(aa));
        memset(bb,0,sizeof(bb));
        memset(cc,0,sizeof(cc));
            node p ;
            int j ;
            int k ;
            int x ;
            memset(vis,0,sizeof(vis));
            int now = 1;
            while( now || vis[j][k] <= 1){
                now = 0;
                p = que.top();
                que.pop();
                j = p.j;
                k = p.k;
                vis[j][k] ++;
                if(aa[i][j]>=n || bb[i][k]>=n || cc[j][k]>=n || vis[j][k]>=2)
                    continue;
                aa[i][j]++;
                bb[i][k]++;
                cc[j][k]++;
                d[ans][0]=i;
                d[ans][1] = j;
                d[ans][2] = k;
                ans++;
                que.push(node{j,k,x+1});
            }
            que.push(p);
        }
        printf("Case #%d: ",ca++);
        printf("%d\n",ans);
        for(int i = 0 ; i < ans ; i++)
            printf("%d %d %d\n",d[i][0],d[i][1],d[i][2]);
    }
    return 0;
}


/*

unsigned   int   0～4294967295
int   2147483648～2147483647
unsigned long 0～4294967295
long   2147483648～2147483647
long long的最大值：9223372036854775807
long long的最小值：-9223372036854775808
unsigned long long的最大值：18446744073709551615

__int64的最大值：9223372036854775807
__int64的最小值：-9223372036854775808
unsigned __int64的最大值：18446744073709551615

*/
