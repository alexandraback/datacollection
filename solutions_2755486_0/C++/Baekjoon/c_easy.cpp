#include <cstdio>
#include <map>
#include <set>
using namespace std;
class rock{
    public:
        int d,n,w,e,s;
        int del_d;
        int del_p;
        int del_s;
        int cnt;
        bool operator < (const rock &v ) const {
            if (d < v.d) {
                return true;
            } else if (d == v.d) {
                return s < v.s;
            } else {
                return false;
            }
        }
};

int main() {
    int t;
    scanf("%d",&t);
    for (int tc=1; tc<=t; tc++) {
        int tot;
        scanf("%d",&tot);
        set<rock> s;
        for (int i=0; i<tot; i++) {
            rock x;
            scanf("%d %d %d %d %d %d %d %d\n",&x.d,&x.n,&x.w,&x.e,&x.s,&x.del_d,&x.del_p,&x.del_s);
            x.cnt = 0;
            s.insert(x);
        }
        map<int,int> walll;
        map<int,int> wallr;
        int ans = 0;
        while(s.size() > 0) {
            rock x = *s.begin();
            s.erase(s.begin());
            bool ok = false;
            if (wallr[x.w] < x.s) ok = true;
            if (walll[x.e] < x.s) ok = true;
            if (ok) goto asdf;
            for (int i=x.w+1; i<=x.e-1; i++) {
                if (walll[i] < x.s || wallr[i] < x.s) {
                    ok = true;
                    break;
                }
            }
asdf:;
            if (ok) {
                ans += 1;
                wallr[x.w] = max(wallr[x.w],x.s);
                for (int i=x.w+1; i<=x.e-1; i++) {
                    walll[i] = max(walll[i],x.s);
                    wallr[i] = max(wallr[i],x.s);
                }
                walll[x.e] = max(walll[x.e],x.s);
            }
            if (x.cnt+1 < x.n) {
                x.d+=x.del_d;
                x.w+=x.del_p;
                x.e+=x.del_p;
                x.s+=x.del_s;
                x.cnt+=1;
                s.insert(x);
            }
        }
        printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}
