#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF (1<<29)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define IN(n) int n;scanf("%d",&n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define REP(i, n) FOR(i, 0, n)
#define F(n) REP(i, n)
#define FF(n) REP(j, n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N,int *A){F(N)scanf("%d",A+i);}
char s[128];
int L,h[128];
int rec(int p,int f){
    if(!~p)return !f;
    if(f^h[p])return 1+rec(p-1,!f);
    return rec(p-1,f);
}
int main(void){
    IN(tt)F(tt){
        scanf("%s",s),L=strlen(s);
        F(L)h[i]=s[L-i-1]!=45;
        printf("Case #%d: %d\n",i+1,min(rec(L-1,0),rec(L-1,1)));
    }
    return 0;
}
