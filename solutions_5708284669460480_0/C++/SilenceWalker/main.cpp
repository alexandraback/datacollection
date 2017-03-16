#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<cstring>
#include<map>
#include<algorithm>
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,b,a) for(int i = (b); i >= (a); --i)
#define clr(a,x) memset(a,(x),sizeof(a))
#define ll long long
#define ull unsigned long long
#define all(o) o.begin(),o.end()
#define eps 1e-6
#define mp make_pair
int K, L, S;
const int maxn = 100 + 5;
char base[maxn];
char T[maxn], str[maxn];

bool vis[maxn];
int ans;
int maxlen = 0;
bool match(char * s)
{
    rep(i,0,L) if (s[i] != T[i])
        return false;
    return true;
}

int Cal()
{
    int result = 0;
    rep(i,0,S-L+1) {
        result += match(str+i);
    }
    if (result > maxlen) maxlen = result;
    return result;
}

void dfs(int cur)
{
    if (cur == S) {
        ans += Cal();
        return;
    }
    rep(j,0,K) {
        str[cur] = base[j];
        dfs(cur+1);
    }
}

int main()
{
    //Getinput(); return 0;
    #ifdef ACM
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif // ACM
    int _T; scanf("%d",&_T);
    rep(cas,1,_T+1) {
        scanf("%d%d%d",&K,&L,&S);
        ans = maxlen = 0;
        scanf("%s",base); scanf("%s",T);
        dfs(0);
        double out = ans / std::pow(K,S);
        out = maxlen - out;
        printf("Case #%d: %.10f\n",cas,out);
    }
}
