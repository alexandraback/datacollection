#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int n;
int a[25],b[25];
ll amax[25],amin[25];
ll bmax[25],bmin[25];

ll pow[25];

ll poweroften(int x) {
    return pow[x];
}


int calcmax() {
    amax[n] = (ll)0;
    amin[n] = (ll)0;
    bmax[n] = (ll)0;
    bmin[n] = (ll)0;
    for (int i = n-1; i>=0; i--) {
        if (a[i] != -1) {
            amax[i] = amax[i+1]+(ll)a[i]*poweroften(n-1-i);
            amin[i] = amin[i+1]+(ll)a[i]*poweroften(n-1-i);
        }
        else {
            amax[i] = amax[i+1]+(ll)9*poweroften(n-1-i);
            amin[i] = amin[i+1];
        }
        if (b[i] != -1) {
            bmax[i] = bmax[i+1]+(ll)b[i]*poweroften(n-1-i);
            bmin[i] = bmin[i+1]+(ll)b[i]*poweroften(n-1-i);
        }
        else {
            bmax[i] = bmax[i+1]+(ll)9*poweroften(n-1-i);
            bmin[i] = bmin[i+1];
        }
        //printf("i=%d, amin=%lld, amax=%lld, bmin=%lld, bmax=%lld\n", i, amin[i], amax[i], bmin[i], bmax[i]);
    }
}


int bt (int k) {
    if (k == n) {

    }
}

ll abest;
ll bbest;

ll abs (ll a) {
    if (a >= 0) return a; return (ll)0-a;
}

void updateBest(ll newa, ll newb) {
    //printf("updatebest from %lld,%lld to %lld,%lld\n", abest, bbest, newa, newb);
    bool upd = false;
    if (abest == (ll)-1) upd = true;
    if (abs(abest-bbest)>abs(newa- newb)) upd = true;
    if (abs(abest-bbest)==abs(newa- newb) && abest > newa) upd = true;
    if (abs(abest-bbest)==abs(newa- newb) && abest == newa && bbest > newb) upd = true;

    if (upd) { abest = newa; bbest = newb; }
    //printf("updatebest from %lld,%lld to %lld,%lld\n", abest, bbest, newa, newb);
}

ll sofara(int l) {
    if (l == -1) return (ll)0;
    ll ans = (ll)0;
    for (int i = 0; i<=l; i++) {
        ans = ans+poweroften(n-1-i)*a[i];
    }
    return ans;
}
ll sofarb(int l) {
    if (l == -1) return (ll)0;
    ll ans = (ll)0;
    for (int i = 0; i<=l; i++) {
        ans = ans+poweroften(n-1-i)*b[i];
    }
    return ans;
}

int calculate() {
    calcmax();
    abest =-1; bbest = -1;

    abest=(ll)-1;
    bbest=(ll)-1;

    for (int i = 0; i<n; i++) {
        //printf("i %d.   %lld, %lld\n", i, sofara(i-1), sofarb(i-1));

        if (i >= 1) {
            updateBest(sofara(i-1)+amax[i], sofarb(i-1)+bmin[i]);
            updateBest(sofara(i-1)+amin[i], sofarb(i-1)+bmax[i]);

        }

        if (a[i] != -1 && b[i] != -1) continue;
        if (a[i] == -1 && b[i] == -1) {
            //0 1
            updateBest(sofara(i-1)+poweroften(n-1-i)*0+amax[i+1], sofarb(i-1)+poweroften(n-1-i)*1+bmin[i+1]);

            //1 0
            updateBest(sofara(i-1)+poweroften(n-1-i)*1+amin[i+1], sofarb(i-1)+poweroften(n-1-i)*0+bmax[i+1]);

            //0 0
            a[i] = 0; b[i] = 0;
        }
        else if (a[i] == -1) {
            int aa = b[i]-1;
            if (aa >= 0) updateBest(sofara(i-1)+poweroften(n-1-i)*aa+amax[i+1], sofarb(i-1)+poweroften(n-1-i)*b[i]+bmin[i+1]);

            aa = b[i]+1;
            if (aa <= 9) updateBest(sofara(i-1)+poweroften(n-1-i)*aa+amin[i+1], sofarb(i-1)+poweroften(n-1-i)*b[i]+bmax[i+1]);

            a[i] = b[i];
        }
        else if (b[i] == -1) {
            int bb = a[i]-1;
            if (bb >= 0) updateBest(sofara(i-1)+poweroften(n-1-i)*a[i]+amin[i+1], sofarb(i-1)+poweroften(n-1-i)*bb+bmax[i+1]);

            bb = a[i]+1;
            if (bb <= 9) updateBest(sofara(i-1)+poweroften(n-1-i)*a[i]+amax[i+1], sofarb(i-1)+poweroften(n-1-i)*bb+bmin[i+1]);

            b[i] = a[i];
        }
    }
    //printf("%lld %lld\n", abest, bbest);

    updateBest(sofara(n-1), sofarb(n-1));

    //printf("final %lld %lld\n", abest, bbest);

    int j = 0;

    if (abest > 0) while (abest < poweroften(n-1-j)) j++;
    else j = n-1;

    for (int i = 0; i<j; i++) printf("0");

    printf("%lld ", abest);

    j = 0;
    if (bbest > 0) while (bbest < poweroften(n-1-j)) j++;
    else j = n-1;

    for (int i = 0; i<j; i++) printf("0");


    printf("%lld\n", bbest);

}



int main()
{
    /*n=1;
    a[0] = -1;
    b[0] = -1;
    calculate();
    return 0;*/



    pow[0] = (ll)1;
    for (int i = 1; i<=19; i++) pow[i] = pow[i-1]*(ll)10;



    int t; scanf("%d\n", &t);

    for (int cas = 1; cas<=t; cas++) {
        n = 0; char c;
        scanf("%c", &c);
        while (c != ' ') {
            if (c == '?') a[n] = -1;
            else a[n] = c-'0';
            n++;
            scanf("%c", &c);
        }

        for (int i = 0; i<n; i++) {
            scanf("%c", &c);
            if (c == '?') b[i] = -1;
            else b[i] = c-'0';
        }

        scanf("%c", &c);

        printf("Case #%d: ", cas);
        calculate();

    }



    return 0;
}
