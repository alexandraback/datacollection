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
struct objeto{
    int x, y, qtd;
    string s;
    objeto(){}
    objeto(int a, int b, int c, string d):x(a),y(b),qtd(c),s(d){}
};

int x, y;

void rodar(){
    if(x > 0){
        //s = "E";
        printf("E");
        x--;
        while(x--){
            //s = s+"WE";
            printf("WE");
        }
    }else if(x < 0){
        x = -x;
        //s = "W";
        printf("W");
        x--;
        while(x--){
            //s = s+"EW";
            printf("EW");
        }
    }
    if(y > 0){
        //s = s +"SN";
        printf("SN");
        y--;
        while(y--){
            printf("SN");
            //s = s+"SN";
        }
    }else if(y < 0){
        y = -y;
        printf("NS");
       // s = s +"NS";
        y--;
        while(y--){
            printf("NS");
            //s = s+"NS";
        }
    }
    printf("\n");
}

int main(){

	freopen("a.in","r",stdin);
	freopen("b.txt","w",stdout);
    int t, caso = 1;;
    ler(t);
    while(t--){
        ler2(x,y);
        printf("Case #%d: ",caso++);
        rodar();
    }



	return 0;
}
