#include<fstream>
#include<vector>
#include<unordered_map>

using namespace std;
typedef int var;

ifstream fin("pppcode.in");
ofstream fout("pppcode.out");

#define MAXN 500001

unordered_map<char, var> MAP;
var V[MAXN], n, x;

var Table[4][4] = { {
        1, 2, 3, 4
    }, {
        2, -1, 4, -3
    }, {
        3, -4, -1, 2
    }, {
        4, 3, -2, -1
    }
};

char Ch[] = {'1', 'i', 'j', 'k'};
char writeMap(var a) {
    if(a < 0) fout<<'-', a = -a;
    fout<<Ch[a-1];
}

var times(var a, var b) {
    bool sign = 0;
    if(a < 0) sign ^= 1, a = -a;
    if(b < 0) sign ^= 1, b = -b;

    if(sign)
        return -Table[a-1][b-1];
    return Table[a-1][b-1];
}

var toInt(char c) {
    return MAP[c];
}


void init() {
    MAP['1'] = 1;
    MAP['i'] = 2;
    MAP['j'] = 3;
    MAP['k'] = 4;
}

bool checkSol() {
    var prod1, prod2, prod3;
    var i=1;
    for(prod1 = 1; i <= n && prod1 != 2; prod1 = times(prod1, V[i++]));
    if(i > n)
        return false;
    for(prod2 = 1; i <= n && prod2 != 3; prod2 = times(prod2, V[i++]));
    if(i > n)
        return false;
    for(prod3 = 1; i <= n; prod3 = times(prod3, V[i++]));

    return prod3 == 4;

}

int main() {

    init();

    var t;
    char c;
    fin>>t;

    for(var tt=1; tt<=t; tt++) {
        fin>>n>>x;

        for(var i=1; i<=n; i++) {
            fin>>c;
            V[i] = toInt(c);
        }

        for(var i=2; i<=x; i++) {
            for(var j=1; j<=n; j++) {
                V[n*(i-1)+j] = V[j];
            }
        }

        n *= x;

        fout<<"Case #"<<tt<<": "<<(checkSol() ? "YES" : "NO")<<'\n';
    }

    return 0;
}
