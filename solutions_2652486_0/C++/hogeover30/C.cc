#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#define REP(i,a,b) for(int i=a;i<b;++i)
using namespace std;
int main()
{
    int T; cin>>T;
    int r,n,m,K; cin>>r>>n>>m>>K;
    cout<<"Case #1:\n";
    while (r--) {
        int res=222;
        set<int> a;
        for(int i=0;i<K;++i) { int t; cin>>t; a.insert(t); }
        REP(i,2,m+1) REP(j,2,m+1) REP(k,2,m+1) {
            set<int> s;
            REP(x,0,8) {
                int c=1;
                if (x&1) c*=k;
                if ((x>>1)&1) c*=j;
                if ((x>>2)&1) c*=i;
                s.insert(c);
            }
            for(typeof(a.begin())it=a.begin();it!=a.end();++it)
                if (s.find(*it)==s.end()) goto NEXT;
            res=100*i+10*j+k; goto HOGE;
NEXT:;
        }
HOGE:
        cout<<res<<endl;
    }
    return 0;
}
