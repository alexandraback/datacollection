#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <time.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,b,a) for(int i=(b);i>=(a);--i)
#define clr(a,x) memset(a,(x),sizeof(a))
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define lson l, m, rt << 1
#define rson m+1, r, rt << 1 | 1
#define ls rt << 1
#define rs rt << 1 | 1
const int maxn = 10000 + 5;
char S[maxn], T[maxn];
bool reduce_i[maxn];
bool reduce_j[maxn];
bool reduce_k[maxn];
int w[4][4] = {
               {0,1,2,3},
               {1,0,3,2},
               {2,3,0,1},
               {3,2,1,0}
              };
int sign[4][4] = {{0,0,0,0},{0,1,0,1},{0,1,1,0},{0,0,1,1}};

bool ok(int len)
{
    rep(i,0,len-1) if (reduce_i[i]) {
        int state = S[i+1];
        int flag = 0;
        rep(j,i+2,len) {
            if (reduce_k[j] && !flag && state == 2) return true;
            flag ^= sign[state][S[j]];
            state = w[state][S[j]];
        }
    }
    return false;
}

int main()
{
    //Getinput(); return 0;
    #ifdef ACM
        freopen("in.txt","r",stdin);
        //freopen("out.out","w",stdout);
       // freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif // ACM

    int iCas; cin >> iCas;
    rep(cas,1,iCas+1) {
        clr(reduce_i,0); clr(reduce_j,0);
        clr(reduce_k,0);
        int L, X;
        cin >> L >> X;
        scanf("%s",S);
        char * s = T;
        while (X--) {
            strcpy(s,S);
            s += L;
        }
        strcpy(S,T);
        int len = strlen(S);
        rep(i,0,len) {
           if (S[i] == 'i') S[i] = 1;
            else if (S[i] == 'j') S[i] = 2;
            else if (S[i] == 'k') S[i] = 3;
        }
        int state = S[0];
        if (state == 1) reduce_i[0] = true;
        int flag = 0;
        rep(i,1,len) {
            flag ^= sign[state][S[i]];
            state = w[state][S[i]];
            if (state == 1 && flag == 0) reduce_i[i] = true;
        }
        state = S[len-1]; flag = 0;
        if (state == 3) reduce_k[len-1] = true;
        rrep(i,len-2,0) {
            flag ^= sign[S[i]][state];
            state = w[S[i]][state];
            if (state == 3 && flag == 0) reduce_k[i] = true;
        }
        printf("Case #%d: ",cas);puts(ok(len) ? "YES": "NO");
    }
    return 0;
}

