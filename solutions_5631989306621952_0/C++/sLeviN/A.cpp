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
    ll z;
    int T,t,n,left,right,m,x;
    char A[2200],maxc,leftc;
    string S;
    cin>>T;
    f(t,T){
        cout<<"Case #"<<t+1<<": ";
        cin>>S;
        A[1100]=S[0];
        left=1100;
        right=1100;
        leftc=maxc=S[0];
        m=0;
        fab(i,1,S.size()){
            if(S[i]>=maxc){
                maxc=S[i];
                m=i;
            }
        }
        x=1;
        if(S[0]!=maxc){
            while(S[x]!=maxc){
                if(S[x]<leftc)
                    A[++right]=S[x];
                else {
                    A[--left]=S[x];
                    leftc=S[x];
                }
                x++;
            }
        } else {
            while(x<m){
                if(S[x]<S[0])
                    A[++right]=S[x];
                else
                    A[--left]=S[x];
                x++;
            }
        }
        while(x<S.size()){
            if(S[x]==maxc)
                A[--left]=maxc;
            else
                A[++right]=S[x];
            x++;
        }
        /*if(m)
            A[--left]=S[x++];
        while(x<S.size()){
            A[++right]=S[x++];
        }*/
        A[++right]='\0';
        cout<<&A[left];
        cout<<"\n";
    }
    return 0;
}
