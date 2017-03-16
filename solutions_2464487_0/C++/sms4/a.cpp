#include <cstring>
#include <cstdlib>
#include <climits>
#include <cstdio>
#include <cctype>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>

using namespace std;
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define frd(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define ms(ar,a) memset(ar, a, sizeof(ar))
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define ler(a) scanf("%d", &a)
#define ler2(a,b) scanf("%d%d", &a, &b)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1.0);
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
#define MAXN 100
#define EPS 1e-9

unsigned long long resp , r, t, total, temp;

int main(){

	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
    int q;
    int caso = 1;
    ler(q);
    while(q--){
        cin >> r >> t ;
        resp = 0;
        total = 0;
        temp = 1;
        while(total < t){
            resp++;
            total += (2*r + (temp*temp - ( (temp-1)*(temp-1) ) ) );
            temp += 2;
        }
        if(total > t){
            resp--;
        }
        cout << "Case #" << caso << ": " <<  resp << endl;
        caso++;
    }
	return 0;
}
