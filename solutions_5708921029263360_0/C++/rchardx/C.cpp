#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;

#define _abs(x) ((x)>0?(x):-(x))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long LL;

int J,P,S,K,ans;
int jp[11][11],js[11][11],ps[11][11];
struct A {
    int j,p,s;
};
vector<A> col;

void print(int S) {
    for (int i= 0; i<col.size(); ++i) if (S&(1<<i)) {
        cout<<col[i].j+1<<' '<<col[i].p+1<<' '<<col[i].s+1<<endl;
    }
}

int check(int S) {
    memset(jp,0,sizeof(jp));
    memset(js,0,sizeof(js));
    memset(ps,0,sizeof(ps));
    int ret = 0;
    for (int i= 0; i<col.size(); ++i) if (S&(1<<i)) {
        //cout<<col[i].j<<' '<<col[i].p<<' '<<col[i].s<<endl;
        ++ret;
        jp[col[i].j][col[i].p]++;
        js[col[i].j][col[i].s]++;
        ps[col[i].p][col[i].s]++;
    }
    if (ret<=ans) return -1;
    for (int j = 0; j<J; ++j)
        for (int p = 0; p<P; ++p)
            for (int s = 0; s<S; ++s)
                if (jp[j][p]>K || js[j][s]>K || ps[p][s]>K) return -1;
    return ret;
}

int main() {
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
  
    int T; cin>>T;
    for (int loop = 1; loop<=T; ++loop) {
        printf("Case #%d: ", loop);
        cin>>J>>P>>S>>K;
        ans = 0;
        col.clear();
        if (J==3) {
            memset(jp,0,sizeof(jp));
            memset(js,0,sizeof(js));
            memset(ps,0,sizeof(ps));
            for (int j = 0; j<J; ++j)
                for (int p = 0; p<P; ++p) if (jp[j][p]<K)
                    for (int s = 0; s<S; ++s) if (jp[j][p]<K && js[j][s]<K && ps[p][s]<K) {
                        A a;
                        a.j = j; a.p = p; a.s = s;
                        col.push_back(a);
                        ans++;
                        jp[j][p]++;
                        js[j][s]++;
                        ps[p][s]++;
                    }
            cout<<ans<<endl;
            print((1<<col.size())-1);
            continue;
        }
        for (int j = 0; j<J; ++j)
            for (int p = 0; p<P; ++p)
                for (int s = 0; s<S; ++s) {
                    A a;
                    a.j = j; a.p = p; a.s = s;
                    col.push_back(a);
                }
        int cnt = col.size();
        int lim = (1<<cnt)-1,_S;
        for (int S = 0; S<=lim; ++S) {
            int tmp = check(S);
            if (tmp>ans) {
                ans = tmp;
                _S = S;
            }
        }
        cout<<ans<<endl;
        print(_S);
    }
    return 0;
}
