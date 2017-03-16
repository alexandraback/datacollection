/*  ^^ ====== ^^ 
ID: meixiuxiu
PROG: test
LANG: C++11
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
#define pi acos(-1.0)
#define maxn 40000
#define maxv 100005
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
#define LOCAL
int a[55][55];
int dig[550];

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif
    int t;cin >> t;
    int kase =1;
    while(t--){
        MEM(a,0);
        MEM(dig,0);
        printf("Case #%d:",kase++);
        ll b,m;cin >> b >> m;
        int cnt = 0;
        ll ans = m; 
        a[1][b] = 1;
        m--;
        while(m){
            if(m&1)dig[cnt++]=1;
            else dig[cnt++] = 0;
            m>>=1;
        }   
        int ok =1;
        if((1ll<<(b-2)) < ans){
            ok = 0;
            puts(" IMPOSSIBLE");
        }
        else puts(" POSSIBLE");
        for(int i=1;i<b;i++){
            for(int j=i+1;j<b;j++){
                a[i][j] = 1;
            }
        }
        for(int i=0;i<cnt;i++){
            if(dig[i]){
                a[i+2][b] = 1;
            } 
        }
        if(ok){
            for(int i=1;i<=b;i++){
                for(int j=1;j<=b;j++){
                    printf("%d",a[i][j]);
                }
                printf("\n");
            }
        }
    }
	return 0;
}