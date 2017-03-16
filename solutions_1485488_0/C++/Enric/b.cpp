#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
int h, n, m;
vector<vector<int> > vceil;
vector<vector<int> > vfloor;
typedef pair<int,int> P;
typedef pair<P,int> E;
#define x first
#define y second
const int INF = 1000000000;
//temps = temps*10 per estalviar decimals
//quant temps trigo a mourem des de (i,j) a temps t en la direccio d (-1 impossible)
int f(int i, int j, int t, int d) {
    int ni=i+di[d];
    int nj=j+dj[d];
    if (ni<0 or ni>=n or nj<0 or nj>=m) return -1;
    int ans=0;
    int wat=h-t;
    if (wat>vfloor[i][j]) { //puc esperar que baixi l'aigua
        //quant m'haig d'esperar
        if (vfloor[i][j]+50<=vceil[ni][nj] and
            vfloor[ni][nj]+50<=vceil[ni][nj] and
            vfloor[ni][nj]+50<=vceil[i][j]) { //si la roca NO em limtia
                int espera=0;
                if (wat+50>vceil[ni][nj]) { //haig d'esperar
                    espera=wat+50-vceil[ni][nj];
                }
                wat-=espera; //espero i l'aigua baixa
                
                if (vfloor[i][j]+20<=wat) return 10+espera;
                else return 100+espera;
            }
            else return -1; //si la roca em limita no podre passar per molt k esperi
    }
    else { //l'aigua esta per sota el meu terra
        if (vfloor[i][j]+50<=vceil[ni][nj] and
            vfloor[ni][nj]+50<=vceil[ni][nj] and
            vfloor[ni][nj]+50<=vceil[i][j]) {
                return 100; //10sec per moure el caiac
            }
            else return -1; //la roca no em deixa passar
            
    }
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(1);
    int t; cin >> t;
    for (int cas=1;cas<=t;++cas) {
        cin >> h >> n >> m;
        vceil = vfloor = vector<vector<int> > (n,vector<int>(m,0));
        for (int i=0;i<n;++i) for (int j=0;j<m;++j) cin >> vceil[i][j];
        for (int i=0;i<n;++i) for (int j=0;j<m;++j) cin >> vfloor[i][j];
        vector<vector<int> > ini(n,vector<int>(m,0));
        ini[0][0]=1;//des de quins puc comencar
        queue<P> q0;
        q0.push(P(0,0));
        while(!q0.empty()) {
            P p = q0.front(); q0.pop();
            int i = p.x, j = p.y;
            for (int d=0;d<4;++d) {
                int ni = i+di[d], nj=j+dj[d];
                if (ni<0 or ni>=n or nj<0 or nj>=m) continue;
                if (h+50<=vceil[ni][nj] and 
                    vfloor[i][j]+50<=vceil[ni][nj] and
                    vfloor[ni][nj]+50<=vceil[ni][nj] and
                    vfloor[ni][nj]+50<=vceil[i][j]) { //puc anar
                        if (not ini[ni][nj]) { //si no hi he estat ja
                            ini[ni][nj]=1;
                            q0.push(P(ni,nj));
                        }
                    }
            }
        }
        /*
        cerr << "initial positions:" << endl;
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) cout << ini[i][j];
            cout <<endl;
        }*/
        
        vector<vector<int> > M(n,vector<int> (m,INF)); //minim temps amb el que he estat a (i,j)
        queue<E> q;
        for (int i=0;i<n;++i) {
            for (int j=0;j<m;++j) if (ini[i][j]) {
                q.push(E(P(i,j),0));
                M[i][j]=0;
            }
        }
        
        
        while (!q.empty()) {
            E e = q.front(); q.pop();
            int i = e.x.x, j = e.x.y, t = e.y;
            if (M[i][j]<t) continue; //he arribat abans
            for (int d=0;d<4;++d) {
                int tt = f(i,j,t,d); //quan triga la transicio
                if (tt==-1) continue;
                int ni=i+di[d], nj=j+dj[d];
                if (t+tt<M[ni][nj]) {
                    M[ni][nj]=t+tt;
                    q.push(E(P(ni,nj), t+tt));
                }
            }
        }
        cout << "Case #" << cas << ": " << M[n-1][m-1]/10. << endl;
        
    }
}
