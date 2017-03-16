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

int c, d, v;
VI D;

int main(){
    ios_base::sync_with_stdio(false);
    freopen("inputCb.in","r",stdin);
    freopen("output2.out","w",stdout);
    int t; cin >> t;
    FOR(w, t) {
        cin >> c >> d >> v;
           //     cout << c << ' ' << d << ' ' << v << endl;
                
        D = VI(d);
        FOR(i,d) {
            cin >> D[i];
        }
          //     FOR(i, d) cout << D[i] << ' ';
        //cout << endl;
        int maxim = 0;
        FOR(i, d-1) {
            maxim = max(maxim, D[i+1]-D[i]);
        }
        if (D[d-1] < v) maxim = max(maxim, v-D[d-1]);
        maxim = max(maxim, D[0]-1);
        int add = 0;
        while ((add*(add+1))/2 < maxim ) {
            ++add;
        }
        int res = add;
        FOR(i, d) {
            if (D[i] <= add) -- res;
        }
        cout << "Case #" << w+1 << ": "  << res  << endl;
    }
}
