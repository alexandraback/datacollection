#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define f(i,beg,end) for(int i=beg; i<=end; i++)
#define F(i,beg,end) for(int i=beg; i>=end; i--)

#define input(file) freopen(file,"r",stdin)
#define output(file) freopen(file,"w",stdout)

#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll mod = 1000000000 + 7;

map<char, map<char,char> > multipleTable;
map<char, map<char,int> > signTable;
pair<char,int> exprValue;

string inp;
int l, x;

void precompute();
void init();
void solve(int);

int main() {
//    input("test.txt");
    input("Dijkstra.in");
    output("Dijkstra.out");
    precompute();

    int tests = 1; cin >> tests;
    f(i,1,tests) {
        init();
        solve(i);
    }

    return 0;
}
void init() {
    cin >> l >> x;
    cin.ignore();
    cin >> inp;
}

inline void multiply(pair<char,int> &p, char ch) {
    char old = p.first;
    p.first = multipleTable[old][ch];
    p.second *= signTable[old][ch];
}

pair<char,int> compute(string s) {
    pair<char,int> res = mp('1',1);
    f(i,0,s.size()-1) {
        multiply(res, s[i]);
    }
    return res;
}

void solve(int testNumber) {
    string ans[2] = {"NO", "YES"};
    int ind = 0;
    exprValue = mp('1', 1);

    string expr = "";
    f(i,1,x)
        expr += inp;
//    cout << expr << endl;
    int n = expr.size();

    pair<char,int> total = compute(expr);
    if (expr.size()<3 || (!(total.first == '1' && total.second == -1))) {
        ind = 0;
    }
    else {
        pair<char,int> curr = mp('1',1);
        int fromIndex = -1;
        f(i,0,n-3) {
            multiply(curr,expr[i]);
            if (curr.first == 'i' && curr.second == 1) {
//                cout << "i = value[" << 0 << " to " << i << "]\n";
                fromIndex = i+1;
                break;
            }
        }
        if (fromIndex == -1) {
            ind = 0;
        }
        else {
            curr = mp('1',1);
            f(j,fromIndex,n-2) {
                multiply(curr,expr[j]);
                if (curr.first == 'j' && curr.second==1) {
//                    cout << "j = value[" << fromIndex << " to " << j << "]\n";
                    ind = 1;
                    break;
                }
            }
        }
    }

    printf("Case #%d: %s\n", testNumber, ans[ind].c_str());
}

void precompute() {
map<char,char> oneToResult;
    oneToResult['1'] = '1';
    oneToResult['i'] = 'i';
    oneToResult['j'] = 'j';
    oneToResult['k'] = 'k';
    multipleTable['1'] = oneToResult;
    map<char,char> iToResult;
    iToResult['1'] = 'i';
    iToResult['i'] = '1';
    iToResult['j'] = 'k';
    iToResult['k'] = 'j';
    multipleTable['i'] = iToResult;
    map<char,char> jToResult;
    jToResult['1'] = 'j';
    jToResult['i'] = 'k';
    jToResult['j'] = '1';
    jToResult['k'] = 'i';
    multipleTable['j'] = jToResult;
    map<char,char> kToResult;
    kToResult['1'] = 'k';
    kToResult['i'] = 'j';
    kToResult['j'] = 'i';
    kToResult['k'] = '1';
    multipleTable['k'] = kToResult;

    map<char,int> signs;
    signs['1'] = 1;
    signs['i'] = 1;
    signs['j'] = 1;
    signs['k'] = 1;
    signTable['1'] = signs;
    map<char,int> signs2;
    signs2['1'] = 1;
    signs2['i'] = -1;
    signs2['j'] = 1;
    signs2['k'] = -1;
    signTable['i'] = signs2;
    map<char,int> signs3;
    signs3['1'] = 1;
    signs3['i'] = -1;
    signs3['j'] = -1;
    signs3['k'] = 1;
    signTable['j'] = signs3;
    map<char,int> signs4;
    signs4['1'] = 1;
    signs4['i'] = 1;
    signs4['j'] = -1;
    signs4['k'] = -1;
    signTable['k'] = signs4;
}
