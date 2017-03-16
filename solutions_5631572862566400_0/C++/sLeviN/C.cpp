#include <bits/stdc++.h>
using namespace std;

#define f(i,a)  for(int i=0;(i)<(a);++i)
#define fab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define fba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define fit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef char u8;
typedef vector <int> vi;
typedef pair <int, int> pii;

ll pw(ll b, int p){
    ll a=1;
    while(p){
        if(p&1)
            a=(a*b)%MOD;
        b=(b*b)%MOD;
        p>>=1;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T,t,l,cyc[1000],n,m1,m2,maxc,I[1000][1000],last,k,B[1000],nxt,mm,in[1000];
    cin>>T;
    f(t,T){
        cout<<"Case #"<<t+1<<": ";
        cin>>n;
        mm=maxc=0;
        f(i,n){
            cin>>B[i];
            B[i]--;
            cyc[i]=0;
            f(j,n)
                I[i][j]=0;
        }
        f(i,n){
            f(j,n)
                in[j]=0;
            nxt=i;
            in[i]=k=1;
            while(1){
                last=nxt;
                nxt=B[nxt];
                if(in[nxt])
                    break;
                in[nxt]=1;
                I[nxt][last]=max(++k,I[nxt][last]);
            }
            if(nxt==i){
                cyc[i]=k;
                if(k>maxc)
                    maxc=k;
            }
        }
        f(i,n){
            m1=0;
            if(B[B[i]]==i){
                m2=I[i][B[i]];
                f(j,n){
                    if(j!=B[i] && I[i][j]>(m1+1)){
                            m1=I[i][j]-1;
                    }
                }
                if(mm<m1+m2)
                    mm=m1+m2;
            }
        }
    l=0;
        f(i,n){
            if(!cyc[i]){
                f(j,n)
                    if(l<I[i][j])
                        l=I[i][j];
            }
        }
                
        cout<<max(max(mm,maxc),l)<<"\n";
    }
    return 0;
}
