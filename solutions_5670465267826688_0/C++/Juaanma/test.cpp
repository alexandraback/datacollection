#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define dforsn(i,s,n) for(int i=(int)(n)-1;i>=(int)(s);i--)
#define si(a) ((int)(a).size())
#define mp make_pair
typedef pair<int, char> pic;
typedef long long int tint;

pic calc(pic a, pic b) {
    char aa=a.second, bb=b.second;
    int signo=a.first*b.first;
    if (aa=='i' && bb=='j') return mp(signo, 'k');
    if (aa=='i' && bb=='k') return mp(-1*signo, 'j');
    if (aa=='j' && bb=='k') return mp(signo, 'i');
    if (aa=='j' && bb=='i') return mp(-1*signo, 'k');
    if (aa=='k' && bb=='i') return mp(signo, 'j');
    if (aa=='k' && bb=='j') return mp(-1*signo, 'i');
    if (aa=='1') return mp(signo, bb);
    if (bb=='1') return mp(signo, aa);
    return mp(-1*signo, '1'); //aa==bb
}


int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int nc;
    cin >> nc;

    forn(c, nc) {
        tint l, x;
        string s;
        cin >> l >> x >> s;

        int cant=x%4; //a^4=1, entonces simplifico cuando se repite > 4
        string s2;
        while (cant--) s2+=s;

        pic act=mp(1, '1');
        forn(i, si(s2))
            act=calc(act, mp(1, s2[i]));

        bool res = false;

        if (act==mp(-1, '1')) { //existe solucion, i*j*k=-1
            cant=(x>=4?4:0); //puede que necesitemos las repeticiones
            while (cant--) s2+=s;

            int indI=-1; //busco i en principio
            act=mp(1, '1');
            forn(i, si(s2)) {
                act = calc(act, mp(1, s2[i]));
                if (act==mp(1, 'i')) {
                    indI=i;
                    break;
                }
            }

            int indK=-1; //busco k en final
            act=mp(1, '1');
            dforsn(i, 0, si(s2)) {
                act=calc(mp(1, s2[i]), act);
                if (act==mp(1, 'k')) {
                    indK=i;
                    break;
                }
            }

            if (indI!=-1 && indK!=-1 && indI<indK+(x*l-si(s2))) //los indices son validos, entonces k esta en el medio
                res=true;
        }
    
        cout << "Case #" << c+1 << ": " << (res?"YES":"NO") << endl;
    }

    return 0;
}
