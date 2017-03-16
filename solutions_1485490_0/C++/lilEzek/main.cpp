// Written by lilEzek
/*
´´´´´6686666666
´´´´686666666666
´´´´666666666666
´´´´666666666666
´´´´666666666666
´´´´´8666666668
´´´´´´´66886
´´´´´´´´´´´´
´´´´´´´´´6666
´´´´´666666668
´´66666666666666
66666666666666668
666666666666666686
6666666666666666666
´6666666666666666866
´866666666666666666666
´´666666666666666666666
´´6666666666688686666686
´´6866666666666´866666666
´´´6866666666666´666666666
´´´6666666666666´´666666666
´´´´666666666666´´´66666666
´´´´´66666666666´´´´866666
´´´´´666666666666
´´´´´´66666666666´88
´´´´´´´6666666666´´´´
´´´´´´´´666666666´´´´88
´´´´´´´´666666666´´´´´´88
´´´´´´´´666666666´´´´´´´´´
´´´´´´´´666666666´´´´´´´´88
´´´´´´´´66666666´´´´´´´´´´´88
´´´´´´´´66666666´´´´´´´´´´´´´´
´´´´´´´´66666666´´´´´´´´´´´´88
´´´´´´´´66666666´´´´´´´´´´´´´´´
´´´´´´´´66666666´´´´´´´´´´´´´88
´´´´´´´´66666666´´´´´´´´´´´´´´´
´´´´´´´´66666666´´´´´´´´´´´´´´´´
´´´´´´´´66666666´´´´´´´´´´´´´´88
´´´´´´´´66666666´´´´´´´´´´´´´´´´
´´´´´´´´66666666´´´´´´´´´´´´´´´88
´´´´´´´´66666668´´´´´´´´´´´´´´´´
´´´´´´´´66666666´´´´´´´´´´´´´´´“88
´´´´´´´´66666666´´´´´´´´´´´´´´´´´
´´´´´´´´66666668´´´´´´´´´´´´´´´´´ 88
´´´´´´´´66666666´´´´´´´´´´´´´´´
´´´´´´´´6666666´´´´´´´´´´´´
*/

#include <iostream>
#include <cstdio>
#include <cctype>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <limits>
#include <queue>
#include <list>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

#ifdef _DEBUG
    #include <fstream>
    istream * in;
    ostream * out;
#endif

#define X first
#define Y second

#define INFINITE 9999999999999999.

#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define RFOR(i,a,b) for (int i = (int)b-1; i >= (int)a; i--)
#define FORMAP(tx,ty) FOR(y,0,ty) FOR(x,0,tx)

#define FILLMAP(m,tx,ty) FORMAP(tx,ty) cin >> m[y][x]
#define PRINTMAP(m,tx,ty) FOR(y,0,ty) { FOR(x,0,tx) cout << m[y][x]; cout << endl; }

#define REPEAT(i,a) for (int i = 0; i < (int)a; i++)
#define FORCASE(it,case) int case; cin >> case; FOR(it,1,case+1)

#define SSTREAMLINE(linea,sstr)     \
stringstream sstr;                  \
string linea;                       \
getline(cin,linea);                 \
sstr.str(linea);                    \

#define ALL(result, condition, loop) \
    result = true; \
    loop \
        if (!(condition)) \
        { \
            result = false; \
            break;\
        }

#define ANY(result, condition,  loop)\
    result = false;\
    loop \
        if (condition) \
        { \
            result = true; \
            break;\
        }

#define SUM(type,result,container)\
    result = 0;\
    for (type::iterator it = container.begin();\
        it != container.end();\
        it++)\
        result += *it;

#define CIN(t) t; cin >> t
#define VCIN (a,b) a(b);  FOR(i,0,b) cin >> a[i];
#define RVCIN(a,b) a(b); RFOR(i,0,b) cin >> a[i];
#define WCIN(t) t; while(cin >> t)

#define MP(a,b) make_pair(a,b)

#define DIST(pair1,pair2) sqrt((pair1.X-pair2.X)*(pair1.X-pair2.X) + (pair1.Y-pair2.Y)*(pair1.Y-pair2.Y))

int DIVUP(int a, int b)
{
    return (a%b ? 1+a/b : a/b);
}

int NICEDIV(int a, int b)
{
    double r = (double)a/(double)b;
    return (int)(r+0.5);
}

typedef long long LL;
typedef unsigned long long ULL;

typedef pair<int,int> PII;
typedef pair<int,PII> PPII;
typedef pair<string,int> PSI;

typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<PII> VPII;
typedef vector<PPII> VPPII;
typedef vector<PSI> VPSI;
typedef vector<bool> BITS;
typedef vector<BITS> VBITS;
typedef vector<string> VStr;
typedef vector<LL>     VLL;
typedef vector<double> VD;

typedef list<PII> LPII;

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef map<char,int> MCI;

typedef stack<int> SI;

typedef queue<PII> QPII;
typedef priority_queue<PII> PQPII;
typedef priority_queue<PII,vector<PII>,greater<PII> > PQPII_I;

typedef long long ll;

struct pedido
{
    ll amount;
    ll kind;
};

vector<pedido> box;
vector<pedido> toy;

ll solucion(int pedbox, int pedtoy, int pedboxleft = -1, int pedtoyleft = -1)
{
    if (pedbox >= (int)box.size())
        return 0;
    if (pedtoy >= (int)toy.size())
        return 0;
    if (pedboxleft == -1)
        pedboxleft = box[pedbox].amount;
    if (pedtoyleft == -1)
        pedtoyleft = toy[pedtoy].amount;
    if (pedboxleft < 0 or pedtoyleft < 0)
        return 0;
    if (pedboxleft == 0)
    {
        return solucion(pedbox+1,pedtoy,-1,pedtoyleft);
    }
    if (pedtoyleft == 0)
    {
        return solucion(pedbox,pedtoy+1,pedboxleft,-1);
    }
    ll sol =
        max(solucion(pedbox+1,pedtoy,-1,pedtoyleft),
            solucion(pedbox,pedtoy+1,pedboxleft,-1));
    if (box[pedbox].kind == toy[pedtoy].kind)
    {
        int cant = min(pedboxleft,pedtoyleft);
        sol =
            max(sol,
                solucion(pedbox,pedtoy,pedboxleft-cant,pedtoyleft-cant)+cant);
    }
    return sol;
}


int main(void)
{
#ifdef _DEBUG
  in = new ifstream("input.txt");
  out = new ofstream("output.txt");
  cin.rdbuf(in->rdbuf());
  cout.rdbuf(out->rdbuf());
#endif

#ifdef _GENERADOR

#else
    FORCASE(caso,casos)
    {
        cout << "Case #" << caso << ": ";
        int CIN(cajas);
        int CIN(juguetes);

        box = vector<pedido>(cajas);
        toy = vector<pedido>(juguetes);

        for (int i = 0; i < cajas; i++)
        {
            cin >> box[i].amount >> box[i].kind;
        }

        for (int i = 0; i < juguetes; i++)
        {
            cin >> toy[i].amount >> toy[i].kind;
        }

        cout << solucion(0,0) << endl;
    }
#endif
    return 0;
}
