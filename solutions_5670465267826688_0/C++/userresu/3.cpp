#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

int T;
int L;
ll X;
char s[10001];

struct num {
    bool neg;
    char c;
    num operator*(const num &b) const {
        num ret;
        ret.neg = (neg ^ b.neg);
        if (c=='1') ret.c = b.c;
        else if (b.c=='1') ret.c = c;
        else if (c == b.c) ret.c = '1', ret.neg ^= 1;
        else if (c=='i') {
            if (b.c=='j') ret.c='k';
            else ret.c='j',ret.neg^=1;
        }
        else if (c=='j') {
            if (b.c=='i') ret.c='k',ret.neg^=1;
            else ret.c='i';
        }
        else {
            if (b.c=='i') ret.c='j';
            else ret.c='i',ret.neg^=1;
        }
        return ret;
    }
    bool operator==(const num &b) const {
        return neg==b.neg && c==b.c;
    }
};

num inverse (num i) {
    if (i.c=='1') return i;
    return (num){(i.neg^1),i.c};
}

num pref[10002];
num suf[10002];
int main () {
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
        scanf("%d %lld",&L,&X);
        scanf("%s",s);
        num all = (num){0,'1'};
        for (int i=0;i<L;++i) {
            all = all * (num){0,s[i]};
            pref[i] = all;
        }
        suf[0] = all;
        for (int i=1;i<=L;++i) {
            suf[i] = inverse(pref[i-1]) * all;
        }
        num a[4];
        a[0] = (num){0,'1'};
        a[1] = all;
        a[2] = a[1] * all;
        a[3] = a[2] * all;
        bool ok = false;
        for (int i=0;i<L && !ok;++i) for (int j=0;j<L;++j) {
            num first = (num){0,'i'} * inverse(pref[i]);
            num third = inverse(suf[j+1]) * (num){0,'k'};
            for (int p=0;p<4;++p) if (a[p]==first) {
                for (int q=0;q<4;++q) if (a[q]==third) {
                    ll left = X - p - q - 1;
                    if (left < 0) continue;
                    num second;
                    if (i<j && left%4==0) {
                        second = inverse(pref[i]) * all * inverse(suf[j+1]);
                        if (second == (num){0,'j'}) {
                            ok=true;
                            break;
                        }
                    }
                    left--;
                    if (left<0) continue;
                    second = inverse(suf[i+1]) * (num){0,'j'} * inverse(pref[j]);
                    if (a[left%4] == second) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) break;
        }
        if (ok) printf("Case #%d: YES\n",z);
        else printf("Case #%d: NO\n",z);
    }
    return 0;
}
