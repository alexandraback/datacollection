#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define N 4000

struct node{
    bool ok;    
    node *a[26];
};

int i,j,k,m,n,l;
char s[N+10];
int idx;
node pool[2000000];
node *a;
int f[N+10][10];

void build(node *a, int i, char *s){
    if (i==-1){
        a->ok=1; return;
    }
    char c=s[i]-'a';
    if (a->a[c]==NULL){
        a->a[c]=&pool[idx++];
        rep(j, 26) a->a[c]->a[j]=NULL;
        a->a[c]->ok=0;
    }
    build(a->a[c], i-1, s);
}

void init(){
    freopen("garbled_email_dictionary.txt", "r", stdin);    
    
    a=&pool[idx++];
    rep(i, 26) a->a[i]=NULL; a->ok=0;
    
    while (~scanf("%s", s)){
        build(a, strlen(s)-1, s);
        clr(s, 0);
    }
}

int v[1000];
void find(node *a, char *s, int i){
    if (a->ok){
        v[++v[0]]=i+1;
    }

    if (i==-1) return;
    char c=s[i]-'a';
    if (a->a[c]!=NULL) find(a->a[c], s, i-1);
}

int main(){
    init();
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

    int tests;
    scanf("%d", &tests);
    repf(test, 1, tests){
        scanf("%s", s), n=strlen(s);
        clr(f, -1), f[0][4]=0;
        repf(i, 1, n){
            v[0]=0, find(a, s, i-1);
            
            repf(j, 1, v[0]) rep(k, 5) 
                if (f[v[j]][k]!=-1) _checkmin( f[i][min(4, i-v[j]+k)], f[v[j]][k]);
            
            rep(l, min(i, 10) ){
                char c=s[i-1-l];
                rep(z, 26) if (z!=c-'a'){
                    s[i-1-l]=z+'a';
                    v[0]=0, find(a, s, i-1);
                    repf(j, 1, v[0]) rep(k, 5)
                        if (i-l-(v[j]-k)>=5 && f[v[j]][k]!=-1) _checkmin( f[i][min(4, l)], f[v[j]][k]+1);
                }
                s[i-1-l]=c;
            }
            
            rep(l, min(i, 10) ) repf(o, l+5, min(i, 10)-1){
                char c=s[i-1-l], h=s[i-1-o];
                rep(z, 26) if (z+'a'!=c) rep(y, 26) if (y+'a'!=h){
                    s[i-1-l]=z+'a', s[i-1-o]=y+'a';
                    v[0]=0, find(a, s, i-1);
                    repf(j, 1, v[0]) rep(k, 5)
                        if (i-o-(v[j]-k)>=5 && f[v[j]][k]!=-1) _checkmin( f[i][min(4, l)], f[v[j]][k]+2);
                }
                s[i-1-l]=c, s[i-1-o]=h;
            }

        }
        int ans=-1;
        rep(i, 5) if (f[n][i]!=-1) _checkmin(ans, f[n][i]);
        printf("Case #%d: %d\n", test, ans);
        
    }
    return 0;
}
