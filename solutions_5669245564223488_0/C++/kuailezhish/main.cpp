//made by kuailezhish
//gl && hf
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include <complex>
#include <cstring>
#include <ctime>
#define mem(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define lINF 0x3f3f3f3f3f3f3f3fll
#define dINF 1e30
#define eps 1e-8
#define lld long long
#define sqr(x) ((x)*(x))
#define ab(x) (((x)>0) ? (x) : -(x))
#define PI 3.14159265358979323846
#define psl pair<sting,lld>
#define pll pair<lld,lld>
#define pii pair<int,int>
#define mp make_pair
#define er(i) (1ll<<(i))
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define cp complex<double>
#define here printf("!!!!!!!!\n");
#define foreach(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define upmin(a,b) {if ((a)>(b)) (a)=(b);}
#define upmax(a,b) {if ((a)<(b)) (a)=(b);}
#define upmod(a,b) (a)=((a)%(b)+(b))%(b)
#define equ(a,b) (fabs(a-b)<eps)
#define rin freopen("in.txt","r",stdin)
#define pout freopen("out.txt","w",stdout)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

#define mod 1000000007
#define maxn 130

struct node{
    char st[maxn];
    lld len;
}list[maxn];

lld ph[maxn];
lld num[maxn],tab[maxn][maxn];
lld vis[maxn],exist[maxn];
lld n;

map<char ,int>M;
int invalid(char *s){
    int i,j,tem;
    int len=strlen(s);
    M.clear();
    for (i=0; i<len; i++){
        if (i>0 && s[i]==s[i-1]) continue;
        if (M.find(s[i])!=M.end()) return 1;
        M[s[i]]=i;
    }
    return 0;
}


lld dfs(lld s){
    lld i,j,tem;
    vis[s]=1;
    for (i=1; i<=26; i++) if (tab[s][i]) {
        if (vis[i]==1) return 0;
        tem=dfs(i);
        if (tem==0) return 0;
    }
    vis[s]=-1;
    return 1;
}

lld have_circle(){
    lld i,j,tem;
    for (i=0; i<=26; i++)
        if (vis[i]==0 && num[i] && dfs(i)==0) return 1;
    return 0;
}


lld mark;
void redfs(lld s){
    lld i,j,tem;
    vis[s]=1;
    for (i=1; i<=26; i++) if (tab[s][i]){
        if (vis[i]) mark=1;
        else redfs(i);
    }
}

lld cau(){
    lld i,j,tem;
    mem(num,0); mem(exist,0);
    mem(tab,0);
    for (i=1; i<=n; i++){
        int len=list[i].len;
        if (invalid(list[i].st)) return 0;
        if (M.size()==1) num[list[i].st[0]-'a'+1]++;
        if (M.size()==2){
            char a = list[i].st[0];
            char b = list[i].st[len - 1];
            exist[a-'a'+1]++; exist[b-'a'+1]++;
            tab[a-'a'+1][b-'a'+1]++;
        }
        if (M.size()>2){
            char a = list[i].st[0];
            char b = list[i].st[len - 1];
            for (j=0; j<len; j++) if (list[i].st[j]!=a && list[i].st[j]!=b){
                char c=list[i].st[j];
                for (lld k=0; k<=n; k++) if (k!=i){
                    for (lld l=0; l<list[k].len; l++)
                        if (list[k].st[l] == c) return 0;
                }
            }
            exist[a-'a'+1]++; exist[b-'a'+1]++;
            tab[a-'a'+1][b-'a'+1]++;
        }
    }
    for (i=1; i<=26; i++) if (exist[i] && num[i]==0) num[i]=1;
    num[0]=1;

    for (i=1; i<=26; i++)
        for (j=1; j<=26; j++)
            if (tab[i][j]>1) return 0;

    for (i=1; i<=26; i++){
        lld deg=0;
        for (j=1; j<=26; j++) if (tab[i][j]) deg++;
        if (deg>1) return 0;

        deg=0;
        for (j=1; j<=26; j++) if (tab[j][i]) deg++;
        if (deg>1) return 0;
        if (deg==0 && num[i]) tab[0][i]=1;
    }

    mem(vis,0);
    if (have_circle()) return 0;
    

    mem(vis,0);
    lld cnt=0;
   
   
    for (i=1; i<=26; i++)
        if (vis[i]==0 && num[i]>0){
            mark=0;
            redfs(i);
            //cnt+=mark;
            if (mark==0) cnt++;
        }

    lld ans=ph[cnt];
    for (i=1; i<=26; i++) if (num[i]>0)
        ans=(ans*num[i])%mod;
    return ans;
}


int main(){
    lld i,j,tem,T,cas=0;
    rin; pout;
    ph[0]=1; for (i=1; i<=100; i++) ph[i]=(ph[i-1]*i)%mod;
    scanf("%lld",&T);
    while (T--){
        scanf("%lld",&n);
        for (i=1; i<=n; i++){
            scanf("%s",list[i].st);
            list[i].len=strlen(list[i].st);
        }
        lld ans=cau();
        printf("Case #%lld: %lld\n",++cas,ans);
    }
    return 0;
}














