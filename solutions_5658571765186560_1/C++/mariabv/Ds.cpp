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


int main(){
    ios_base::sync_with_stdio(false);
    freopen("inputDL.in","r",stdin);
    freopen("outputDL.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    FOR(l, T) {
        int X, R, C; cin >> X >> R >> C;
        if (R > C) swap(C,R);
        if (X == 1) cout << "Case #" << l+1 << ": GABRIEL" << endl;
        if (X == 2) {
            if ( ((R*C)%2 != 0)) cout << "Case #" << l+1 << ": RICHARD" << endl;
            else cout << "Case #" << l+1 << ": GABRIEL" << endl;
        }
        if (X == 3) {
            if ( (R < 2) or(R <= 2 and C <= 2) or ((R*C)%3 != 0)) cout << "Case #" << l+1 << ": RICHARD" << endl;
            else cout << "Case #" << l+1 << ": GABRIEL"<< endl;
        }
        if (X == 4) {
            if ( (R < 3) or(R <= 3 and C <= 3) or ((R*C)%4 != 0)) cout << "Case #" << l+1 << ": RICHARD" << endl;
            else cout << "Case #" << l+1 << ": GABRIEL" << endl;
        }
        if (X > 6) {
            cout << "Case #" << l+1 << ": RICHARD" << endl;
        }
        if (X == 5){
            if ((R < 3) or ((R*C)%5 != 0)) cout << "Case #" << l+1 << ": RICHARD" << endl;
            else cout << "Case #" << l+1 << ": GABRIEL" << endl;
        }
        if (X == 6){
            if ((R < 3) or ((R*C)%6 != 0)) cout << "Case #" << l+1 << ": RICHARD" << endl;
            else cout << "Case #" << l+1 << ": GABRIEL" << endl;
        }
    
    }
    
}
