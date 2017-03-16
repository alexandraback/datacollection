#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

int n,R,N,M,K;
int a[111];
int r[111111];
set <int> s;

void gen(int lim) {
    n=0;
    while (n<lim) {
        for (int i=0; i<N; ++i)
            a[i]=(rand()%(M-1)) + 2;
        set<int> ss;
        for (int k=0; k<1<<N; ++k) {
            int p=1;
            for (int l=0; l<N; ++l)
                if (k>>l&1) p*=a[l];
            if (!ss.count(p) && s.count(p))
                ss.insert(p);
        }
        if (ss.size() == s.size()) {
            r[n]=a[0]*100+a[1]*10+a[2];
            ++n;
        }
    }
}

void solve(int testcase) {
    printf("Case #%d:\n", testcase);
    cin >> R >> N >> M >> K;
    for (int i=0; i<R; ++i) {
        s.clear();
        for (int j=0; j<K; ++j) {
            int p;
            cin>>p;
            s.insert(p);
        }
        int ll=1000;
        gen(ll);
        map <int,int> cc;
        int max=0,ans=-1;
        for (int j=0; j<ll; ++j) {
            cc[r[j]]++;
            if (cc[r[j]]>max) {
                ans=r[j];
                max=cc[r[j]];
            }
        }
        cout << ans << endl;
    }
}

int main() {
    srand(time(0));
    int T;
    cin >> T;
    for (int i=1; i<=T; ++i)
        solve(i);
    return 0;
}
