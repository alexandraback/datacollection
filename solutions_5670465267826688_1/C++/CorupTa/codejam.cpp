#include <bits/stdc++.h>
#define int long long
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
#define MAXN 1001
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
pci qt[256][256];
string f;
int l,x,r;
pci fonk(pci a,pci b){
    return mp(qt[a.ff][b.ff].ff,(qt[a.ff][b.ff].ss+a.ss+b.ss)%2);
}
int solve(int a){
//cout << a << endl;
    if(a==3){
//        cout << "za\n";
        pci z,m,v;
        z=m=v=mp('1',0);
        FOR(i,r,i<l,1)
            z=fonk(z,mp(f[i],0));
        FOR(i,0,i<l,1)
            m=fonk(m,mp(f[i],0));
        x%=4;
        FOR(i,0,i<x,1)
            v=fonk(v,m);
        v=fonk(z,v);
        return (v==mp('1',(long long)0));
    }
    pci z=mp('1',0);
    int tx=0;
    while(z!=mp((char)('i'+a),(long long)0)&&tx<5){
        if(r==l){
            r=0;
            ++tx;
            if(--x<0)return 0;
        }
        while(r<l&&z!=mp((char)('i'+a),(long long)0)){
            z=fonk(z,mp(f[r],0)),++r;
        }
    }
    return (z==mp((char)('i'+a),(long long)0)?solve(a+1):0);
}
void init(){
    qt['i']['i']=mp('1',1);
    qt['j']['j']=mp('1',1);
    qt['k']['k']=mp('1',1);
    qt['1']['1']=mp('1',0);
    qt['i']['j']=mp('k',0);
    qt['j']['i']=mp('k',1);
    qt['j']['k']=mp('i',0);
    qt['k']['j']=mp('i',1);
    qt['k']['i']=mp('j',0);
    qt['i']['k']=mp('j',1);
    qt['1']['i']=mp('i',0);
    qt['1']['j']=mp('j',0);
    qt['1']['k']=mp('k',0);
    qt['i']['1']=mp('i',0);
    qt['j']['1']=mp('j',0);
    qt['k']['1']=mp('k',0);
}
main(){
    file("C-large");
    init();
    int t;
    cin >> t;
    FOR(i,1,i<=t,1){
        cin >> l >> x >> f;
        --x;
        r=0;
        cout << "Case #" << i << ": " << (solve(0)?"YES\n":"NO\n");
    }

}
