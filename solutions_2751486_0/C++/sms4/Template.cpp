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
#define MAXN 1000010
#define EPS 1e-9

int grid[MAXN];
string s;

int main(){

	freopen("a.txt","r",stdin);
	freopen("b.txt","w",stdout);
    int t, caso = 1, n;
    ler(t);
    while(t--){
        cin >> s >> n;
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u'){
            grid[0] = 0;
        }else{
            grid[0] = 1;
        }
        unsigned long long ini = 0;
        unsigned long long a, b, resp = 0;;

        if(grid[0] >= n){
            a = (((1)-n)-ini)+1;
            b = s.size();
            resp += (a*b);
            ini = (-n)+2;
        }
        for(int i=1;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                grid[i] = 0;
            }else{
                grid[i] = grid[i-1]+1;
            }
            if(grid[i] >= n){
                a = (((i+1)-n)-ini)+1;
                b = s.size()-i;
                resp += (a*b);
                ini = (i-n)+2;
            }
        }
        printf("Case #%d: ",caso++);
        cout << resp << endl;
    }

	return 0;
}
