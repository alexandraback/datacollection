#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

const int INF=1<<30;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int nc;
    cin >> nc;
    forn(c, nc) { 
        int d, mx=0;
        cin >> d;
        vector<int> v(d);
        forn(i, d) {
            cin >> v[i];
            mx=max(mx, v[i]);
        }

        int best=INF;
        forsn(comen, 1, mx+1) { //Cuantos turnos comen todos
            int act=comen;
            forn(i, d) {
                if (v[i]>comen) { //Si sacando de a 1 no llego, calculo costo de dividir este plato en mitades tal que 'comen' funque
                    if (v[i]%comen==0) act+=v[i]/comen-1;
                    else act+=v[i]/comen;
                } 
            }
            best=min(best, act);
        }

        cout << "Case #" << c+1 << ": " << best << endl;
    }

    return 0;
}
