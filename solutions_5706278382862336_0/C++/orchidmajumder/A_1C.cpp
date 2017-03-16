#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mem(a,p) memset(a,p,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define bitcount __builtin_popcount
#define gcd __gcd
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(a) a.begin(),a.end()
#define sz(a) ((int)(a.size()))
#define DREP(a) sort(all(a));a.erase(unique(all(a)),a.end())
#define debug(x,y) cerr<<x<<" "<<y<<" "<<endl;
#define ns ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
#define VI vector<int>
#define PII pair<int,int>
#define MAX 2000
using namespace std;
long long int B[50];
void gen() {
    long  long int i = 1,j;
    B[0] = i;
    for(j=1; j<=44; j++) {
        i *= 2;
        B[j] = i;
    }
}

int main() {
    int T,j,k;
    long long int P,Q,W;
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    gen();
    char c;
    for(k=1; k<=T; k++) {
        scanf("%lld %c %lld",&P,&c,&Q);
        W = gcd(Q,P);
        P /= W;
        Q /= W;
        if(binary_search(B,B+41,Q)) {
            j = 1;
            bool o = true;
            if(P>Q) {
                printf("Case #%d: impossible\n",k);
                o = false;
            }
            while(j<=40 && o) {
                if(P>=Q/2) {
                    printf("Case #%d: %d\n",k,j);
                    o = false;
                }
                Q /= 2;
                j++;
            }
            if(o==true)
                printf("Case #%d : impossible\n",k);
        } else
            printf("Case #%d: impossible\n",k);
    }
    return 0;
}
