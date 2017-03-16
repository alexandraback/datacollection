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
typedef vector<char> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII; //L'iterador més utiltizat
//Personalitza'l al teu gust! ^^ espero que t'agradi

int k, l, s;
VS K, L;
VS V;
int cops, nombre,total;

void funcio(int i) {

    if (i == s) {
        ++total;
        bool trobat = false;
        int nombre2 = 0;
        FOR(j, s) {
            int aux = 0;
            while (aux < l and (j+aux)<s and V[j+aux] == L[aux]) {
                ++aux;
            }
            if (aux == l) {
                ++nombre2;
                trobat = true;
            }
        }
        nombre = max(nombre, nombre2);
        cops += nombre2;
        return;
    }
    
    FOR(j, k) {
        V[i] = K[j];
        funcio(i+1);
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    freopen("inputB.txt","r",stdin);
    freopen("output.out","w",stdout);
    cout.setf(ios::fixed);
    cout.precision(11);
    int t;
    cin >> t;
    FOR(w, t) {
        cin >> k >> l >> s;
        K = VS(k);
        L = VS(l);
        FOR(i,k) cin >> K[i];    
        FOR(i,l) cin >> L[i];
        V = VS(s);    
        cops = 0; nombre = 0; total = 0; 
        funcio(0);
        cout << "Case #" << w+1 << ": "  << double(nombre) - double(cops)/double(total) << endl;
    }
}
