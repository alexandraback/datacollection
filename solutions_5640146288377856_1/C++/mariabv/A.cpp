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
    ios_base::sync_with_stdio(false);
    freopen("inputA.txt","r",stdin);
    freopen("output.out","w",stdout);
    ll N; cin >> N;

    FOR(t, N) {
        ll n; cin >> n;

        ll cops = 0;
        if ( n < 10 ) { cops += n;}
        VI V;
        while(n > 0) {V.push_back(n%10);  n/= 10;}
        ll a = 0;
        ll b = 0;
        ll c = 1;
 //       cout << V.size() << endl;
        //vols saber millor manera arribar a 991;
        for(int i = 1; i < V.size(); ++i) {
            if (i == 1) a += 1;
            a *= 10; a += V[i];
        }
        for(int j = V.size()-2; j >= 0; --j) {
            if (j == V.size()-2) b += 1;
            b *= 10; b += V[j];
        }
       //cout << a << ' ' << b << endl;
        if ( b >= a and a != 0) {++cops; cops += V[0]-1; ++cops; c = a;
            ll aux = c;
            bool trobat;
            while( aux%10 == 1 and aux > 0) {
                aux /= 10;
            }
            if (aux == 0) --cops;
        }
        else if (a != 0) {cops += V[V.size()-1]; ++cops; c = b;
            ll aux = c;
            bool trobat;
            while( aux%10 == 1 and aux > 0) {
                aux /= 10;
            }
            if (aux == 0) --cops;
        } //falta cas iguals

        //cout << cops << endl;
        ll longitud = int(V.size())-1;
        ll seguent;
        while (longitud >= 0) {

            seguent = 9;
            for(int i = 0; i < (longitud)-1; ++i) {seguent *= 10; seguent += 9;} 
            if (seguent > 9) seguent -= 8;
            else if (longitud == 0) seguent = 1;
            //cout << cops << ' ' << c << ' '  << seguent << ' ' << longitud << endl;
            cops += c-seguent;
            c = 1;
            FOR(i, longitud) { c*= 10; c += 9;}
            if ( c == 19) c = 9;
            --longitud;
        }
        ++c;
        
        cout << "Case #" << t+1 << ": " << cops << endl;
    }
}
