#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

#define I 2
#define J 3
#define K 4
using namespace std;

int op(int v, char c) {
    int sign = v>=0?1:-1;
    v = abs(v);
    if (v==1) return sign*( 
        c=='i'? I:
        c=='j'? J:
        c=='k'? K:((cerr << "ERROR" << endl), 0));
    if (v==I) return sign*(
        c=='i'?-1:
        c=='j'? K:
        c=='k'?-J:((cerr << "ERROR" << endl), 0));
    if (v==J) return sign*( 
        c=='i'?-K:
        c=='j'?-1:
        c=='k'? I:((cerr << "ERROR" << endl), 0));
    if (v==K) return sign*( 
        c=='i'? J:
        c=='j'?-I:
        c=='k'?-1:((cerr << "ERROR" << endl), 0));
    cerr << "ERROR" << endl;
}

int value(string& s) {
    int result = 1;
    for(int i=0; i<s.size(); i++) {
        result = op(result, s[i]);
    }
    return result;
}

string name(int value) {
    string s = value>=0?"":"-";
    value = abs(value);
    s += value == 1 ? "1" :
         value == I ? "i" :
         value == J ? "j" :
         value == K ? "k" : ((cerr << "ERROR" << endl), "?");
    
    return s;
}

string repeat(string s, int n) {
    ostringstream os;
    for (int i = 0; i < n; i++) {
        os << s;
    }
    return os.str();
}

bool find(string& s) {
    int ax = 1;
    for(int i=0; i<s.size(); i++) {
        ax = op(ax, s[i]);
        if (ax != I) continue;

        int bx = 1;
        for(int j=i+1; j<s.size()-1; j++) {
            bx = op(bx, s[j]);
            if (bx == J) return true;
        }
    }
    return false;
}



int main() {
    int test=0, tests; cin >> tests;

    int L, X; string s;
    while(cin >> L >> X >> s) {
        cout << "Case #" << ++test << ": ";
        if (s.size()*X<=10000) {
            string q = repeat(s, X);
            if (value(q) != -1) {
                cout << "NO" << endl;
                continue;
            }
//            cout << " " << name(value(s)) << " " << name(value(q)) << endl;
            cout << (find(q) ? "YES" : "NO") << endl;
        } else {
            cout << name(value(s)) << " " << value(s) << endl;
        }
    }
    
    
}
