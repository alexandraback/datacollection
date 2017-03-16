#include<iostream>
#include<cmath>
#include<iomanip> //Per quan vulguis fer 'cout' currats (p.e. amb 4 decimals)
#include<vector>
#include<map>
#include<queue>
#include<fstream> //Per a fer que l'entrada i/o la sortida siguin fitxers
#include<algorithm>
#include<string>
#include<stack> //Poc útil
#include<numeric> //Poc útil
#include<set>
#include<sstream> //Per entrades complicades on no+ amb el cin no es pot
#include<list> //Poc útil

//cout.setf(ios::fixed);
//cout.precision(11);
// for(iMII it=M.begin();it!=M.end();++it) , per recorre map
//sort(V.begin(), V.end(), greater<int>());  // o reverse(V.begin, V.end)

#define INF 1000000000
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl //Si vols saber el valor d'una variable fas debug(a);
#define FOR(x,y) for(int x=0;x<y;x++)             //En general el 'cerr' va bé per debuguejar (p.e. cerr<<"Hey!"<<endl;
#define FORU(x,y) for(int x=1;x<=y;x++)           //Pq així saps el que has de borrar abans d'enviar i si te l'oblides a vegades no passa res
using namespace std;


typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VP;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII; //L'iterador més utiltizat
//Personalitza'l al teu gust! ^^ espero que t'agradi


int funcio(int i, int j) {

    if (i == j) return -1;
    if (i == -j) return 1;
    if (i == 1 or i == -1) return i*j;
    if (i == 2) {
        if (j == 3) return 4;
        if (j == 4) return -3;        
    }
    if (i == -2) {
        if (j == 3) return -4;
        if (j == 4) return 3;        
    }
    if (i == 3) {
        if (j == 2) return -4;
        if (j == 4) return 2;        
    }
    if (i == -3) {
        if (j == 2) return 4;
        if (j == 4) return -2;        
    }
    if (i == 4) {
        if (j == 2) return 3;
        if (j == 3) return -2;        
    }
    if (i == -4) {
        if (j == 2) return -3;
        if (j == 3) return 2;        
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    freopen("inputCL.in","r",stdin);
    freopen("outputCL.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    FOR(l, T) {
        ll L, X; cin >> L >> X;
        int res = 1;
        int V;
        bool diferent = false;
        int indicador;
        int primer;
        int darrer;
        FOR(i, L) {
            char c; cin >> c;
            if ( c == 'i') V = 2;
            if ( c == 'j') V = 3;
            if ( c == 'k') V = 4;
            if (not i) primer = V;
            if (i == L-1 ) darrer = V;
            res = funcio(res, V);
            if (not i) indicador = V;
            else if( indicador != V) diferent = true;
        }
        if (res == -1 and X%2 == 0) res = 1;   
        if (abs(res) > 1 and X%2 == 0 and X%4 != 0) res = -1; //casos en que cal (k*k) * (k*k)
        if ((L*X == 4) and (primer != 2 and darrer != 4)) res = 0;
        if (res == -1 and diferent) cout << "Case #" << l+1 << ": YES" << endl;
        else cout << "Case #" << l+1 << ": NO" << endl;
    }
}
