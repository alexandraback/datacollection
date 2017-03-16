
#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<typename T1, typename T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { out << "(" << pair.FI << ", " << pair.SE << ")"; return out; }


string x;
#define maxn 1000005
string vov = "aeiou";
bool conso(char a) {
    return vov.find(string(1, a)) == string::npos;
}

int ile[maxn];
int best = -1;

LL go(int n, int k) {
    ile[n] = 0;
    best = -1;
    LL S = 0;
    fdo(i, n - 1, 0) {
        if (conso(x[i])) ile[i] = 1 + ile[i + 1];
        else ile[i] = 0;
        if (ile[i] >= k) best = i;
        //cout << i << " " << ile[i] << endl;
        
        if (best != -1) {
            S += n - best - k + 1;
        }
    }
    return S;
}

int main(){
	ios_base::sync_with_stdio(false);
    int cas;
    cin >> cas;
    fup(c, 1, cas) {
        cout << "Case #" << c << ": ";
        cin >> x;
        int n, k; 
        n = siz(x);
        cin >> k;
        cout << go(n, k) << endl;
    }

	return 0;
}

