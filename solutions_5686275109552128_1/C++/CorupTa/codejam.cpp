#include <bits/stdc++.h>
//#define int long long
#define FOR(a,b,c,d) for(int a=b;c;a+=d)
#define nwit(a,b) typeof(b) a=b
#define f0r(a,b) for(nwit(a,b.begin());a!=b.end();a++)
#define imn(a,b) (a==-1||(a>b&&b!=-1))
#define mn(a,b) (imn(a,b)?b:a)
#define smin(a,b) (a=mn(a,b))
#define smax(a,b) (a=max(a,b))
#define btw(a,b,c) (a<=b&&b<=c)
#define fil(a,b) memset(a,b,sizeof(a));
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fff ff.ff
#define ffs ff.ss
#define ssf ss.ff
#define sss ss.ss
#define MAXN 1000
#define MAXLEN 131072
#define LET 26
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define dosya(a) freopen(a".gir","r",stdin);freopen(a".cik","w",stdout)
#define MOD 1000000007
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
typedef pair<pii,int> ppiii;
typedef pair<pii,pii> ppiipii;
typedef pair<string,string> pss;
typedef pair<char,int> pci;
//0-1->2
//1-2->0
//2-0->1
int d,v[MAXN],ans;
int comp(int a,int b){
    return a>b;
}
void solve(int a){
    int b=0;
    FOR(i,0,i<d,1){
        if(v[i]<=a)break;
        b+=(v[i]-1)/a;
    }
    smin(ans,a+b);
}
main(){
    file("B-large");
//    file("B-small-attempt0");
    int t;
    cin >> t;
    FOR(i,1,i<=t,1){
        cin >> d;
        FOR(i,0,i<d,1)
            cin >> v[i];
        sort(v,v+d,comp);
        ans=v[0];
        FOR(i,1,i<MAXN,1)
            solve(i);
        cout << "CASE #" << i << ": " << ans << endl;
    }

}
