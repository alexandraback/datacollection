#include <iostream>   //我是沙茶....今天又写搓了。。
#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <utility>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define abs(x) ((x)>0?(x):(-(x)))
#define FOR(i,a,b) for(int i = (a);i<=(b);i++)
#define FORD(i,a,b) for(int i = (a);i>=(b);i--)
#define REP(i,n) for(int i = 0;i<(n);i++)
#define rst(x,k) memset(x,k,sizeof(x))
#define lowbit(x) ((x)&(-(x)))
#define h(x) (1<<(x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define eps 1e-7
#define INF 100000000
#define maxn 1100
#define mod 1000000007LL
#define Pi acos(-1.0)
#define link fjksldfjaslkdfjas
#define y1 fksjdlf
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int iCase , n;
LL pp[110];
struct node{
    int l,r;
    bool flag;
}a[110];
char s[110][110];
int all[27];
bool visitout[27] , visitin[27];
void INIT(void){
    pp[0] = 1;
    FOR(i,1,100){
        pp[i] = pp[i - 1] * i;
        pp[i] %= mod;
    }
}
void solve(void){
    scanf("%d",&n);
    FOR(i,1,n)scanf("%s",s[i]);
    rst(all,0); rst(visitin,false); rst(visitout,false);
    printf("Case #%d: ",++iCase);
    LL ans = 1;
    int tot = 0;
    FOR(i,1,n){
        int len = strlen(s[i]);
        if(len == 1){
            all[s[i][0] - 'a']++;
            visitout[s[i][0] - 'a'] = true;
            a[i].flag = false;
            if(visitin[s[i][0] - 'a']){
                printf("0\n");
                return;
            }
            continue;
        }
        int ll = 0 , rr = len - 1;
        FOR(j,0,len-1){
            if(s[i][j] == s[i][0]){
                ll = j;
            }else break;
        }
        FORD(j,len-1,0){
            if(s[i][j] == s[i][len-1]){
                rr = j;
            }else break;
        }
        if(ll > rr){
            all[s[i][0] - 'a']++;
            visitout[s[i][0] - 'a'] = true;
            a[i].flag = false;
            if(visitin[s[i][0] - 'a']){
                printf("0\n");
                return;
            }
            continue;
        }
        a[i].flag = true;
        a[i].l = s[i][0] - 'a';
        a[i].r = s[i][len-1] - 'a';
        visitout[a[i].l] = true;
        visitout[a[i].r] = true;
        tot++;
        if(visitin[a[i].l] || visitin[a[i].r]){
            printf("0\n");
            return;
        }
        FOR(j,ll+1,rr-1){
            if(visitout[s[i][j] - 'a'] || visitin[s[i][j] - 'a']){
                printf("0\n");
                return;
            }
            if(j == rr - 1 || (s[i][j] != s[i][j+1])){
                visitin[s[i][j] - 'a'] = true;
            }
        }
    }
    REP(i,26){
        if(!all[i])continue;
        int tt = 0;
        FOR(j,1,n){
            if(a[j].flag){
                if(a[j].l == i || a[j].r == i){
                    tt++;
                }
            }
        }
        if(tt){
            ans = ans * pp[all[i]] % mod;
        }else{
            tot ++;
            ans = ans * pp[all[i]] % mod;
        }
    }
    int sl[30] , sr[30];
    rst(sl,0); rst(sr,0);
    FOR(i,1,n){
        if(a[i].flag){
            sl[a[i].l]++;
            sr[a[i].r]++;
        }
    }
    REP(i,26){
        if(sl[i] > 1 || sr[i] > 1){
            printf("0\n");
            return;
        }
    }
    //printf("deal with link color tot is %d\n",tot);
    while(true){
        bool exchange = false;
        FOR(i,1,n){
            if(!a[i].flag)continue;
            int tt = 0 , id;
            FOR(j,1,n){
                if(a[j].flag){
                    if(a[i].l == a[j].r){
                        tt++;
                        id = j;
                    }
                }
            }
            if(tt > 1 || (tt == 1 && id == i)){
                printf("0\n");
                return;
            }
            if(tt == 1){
                exchange = true;
                a[i].l = a[id].l;
                tot--;
                a[id].flag = false;
                if(a[i].l == a[i].r){
                    printf("0\n");
                    return;
                }
                break;
            }
            FOR(j,1,n){
                if(a[j].flag){
                    if(a[i].r == a[j].l){
                        tt++;
                        id = j;
                    }
                }
            }
            if(tt > 1 || (tt == 1 && id == i)){
                printf("0\n");
                return;
            }
            if(tt == 1){
                exchange = true;
                a[i].r = a[id].r;
                tot--;
                a[id].flag = false;
                if(a[i].l == a[i].r){
                    printf("0\n");
                    return;
                }
                break;
            }
        }
        if(!exchange)break;
    }
    //printf("tot is %d\n",tot);
    ans = ans * pp[tot] % mod;
    int res = (int) ans;
    printf("%d\n",res);
}

int main(void){
    //freopen("B-large.in","r",stdin);
    //freopen("out.out","w",stdout);
    INIT();
    iCase = 0;
    int casenum; scanf("%d",&casenum);
    while(casenum--) solve();
    return 0;
}
