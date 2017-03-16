/*
 * File:   main.cpp
 * Author: Ming Qin
 *
 * Created on February 27, 2015, 8:37 PM
 */

 //#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void assert(bool expression, int code = 0) {
    if (!expression) {
        cout << "assertion fail! Code=" << code << endl;
        system("pause");
        exit(-1);
    }
}

struct Elt {
    int sign;//1 or -1
    unsigned int val;

    bool operator== ( const Elt& b ) {
        return (this->sign == b.sign) && (this->val == b.val);
    }
};
const vector<vector<Elt> > lookup = {
    {{1,0},{1,1},{1,2},{1,3}},
    {{1,1},{-1,0},{1,3},{-1,2}},
    {{1,2},{-1,3},{-1,0},{1,1}},
    {{1,3},{1,2},{-1,1},{-1,0}}
};
const Elt elt1 = {1, 0};
const Elt elti = {1, 1};
const Elt eltj = {1, 2};
const Elt eltk = {1, 3};

unsigned int mapNum(char c) {
    switch (c) {
    case '1':
        return 0;
    case 'i':
        return 1;
    case 'j':
        return 2;
    case 'k':
        return 3;
    default:
        assert(false);
        return 233;
    }
}
Elt getElt(const char c) {
    Elt e;
    e.sign = 1;
    e.val = mapNum(c);
    return e;
}
//Elt getElt(unsigned int ind) {
//    Elt e;
//    e.sign = 1;
//    e.val = ind;
//    return e;
//}

Elt mul(Elt a, Elt b) {
    Elt e = lookup[a.val][b.val];
    e.sign = e.sign * a.sign * b.sign;
    return e;
}

//c = a\b, or a*c==b
Elt leftDiv(Elt a, Elt b) { 
    Elt e;
    e.sign = a.sign;
    a.sign = 1;

    Elt minusb = b;
    minusb.sign = b.sign *( -1 );
    for (unsigned int i = 0; i < 4; ++i) {
        if (b == lookup[a.val][i]) {
            e.val = i;
            return e;
        }
    }
    for (unsigned int i = 0; i < 4; ++i) {
        if (minusb == lookup[a.val][i]) {
            e.val = i;
            e.sign *= -1;
            return e;
        }
    }
    assert(false);
    return Elt();
}
//Elt computeStr(string &s, string::iterator l, string ::iterator r) {
//    Elt e = elt1;
//    for (; l != r; ++l) {
//        e = mul(e, getElt(*l));
//    }
//    return e;
//}
int reduceX(long long x) {
    if (x <= 12) return (int)x;
    long long temp = x - 12;
    temp = temp % 4;
    temp += 12;
    if (temp > 12) {
        temp -= 4;
    }
    return (int)temp;
    //if (temp == 0) {
    //    return 12;
    //} else {
    //    return (int)( ( 12 - 4 ) + diff );
    //}
}
string canSplit(string s, long long longX) {
    int L = s.size();
    if (L == 0) return "NO";

    int X = reduceX(longX);
    //s.reserve(L*X);
    //string str = s;
    //for (int i = 1; i < L; ++i) {
    //    str += s;
    //}
    int LX = L*X;

    vector<Elt> cum;
    cum.reserve(LX);
    cum.push_back(getElt(s[0]));
    for (int i = 1; i < LX; ++i) {
        cum.push_back(mul(cum[i - 1], getElt(s.at(i%L))));
    }
    for (int a = 0; a < LX-2 && a <= 4 * L; ++a) {
        if (cum[a] == elti) {
            for (int b = a + 1; b < LX - 1 && b - a <= 4 * L; ++b) {
                if (( leftDiv(cum[a], cum[b]) == eltj ) && 
                    ( leftDiv(cum[b], cum[LX - 1]) == eltk )) {
                    return "YES";
                }
            }
        }
    }
    return "NO";

}
int main(int argc, char** argv) {
    vector<string> strv;
    int T;
    long long L,X;
    string str;

    fstream infile("in.txt");
    ofstream outfile("out.txt");

    infile >> T;
    for (int i = 0; i < T;++i){
        infile >> L >> X;
        infile >> str;
        assert(str.size() == L);
        cout << 1 + i << endl;
        outfile << "Case #" << 1+i << ": ";
        outfile << canSplit(str, X) << endl;
    }

    //long long sum = 0;
    //for (long long i = 0; i < 100000000000; ++i) {
    //    sum++;
    //}
    infile.close();
    outfile.close();
    return 0;
}


//string canSplit(string s, int X) {
//    //X can be reduced
//    X = X % 12;
//
//    int L = s.size();
//    Elt x = elt1;
//    for (char c : s) {
//        x = mul(x, getElt(c));
//    }
//    vector<Elt> tab;
//    tab.push_back(elt1);
//    tab.push_back(x);
//    tab.push_back(mul(x, x));
//    tab.push_back(mul(tab[2], x));
//
//    Elt v0, v1, v2;
//    //break into :
//    //[0,aa) [aa, bb] (bb, L)
//    for (int a = 0; a < X; ++a) {
//        v0 = tab[a % 4];
//        for (int aa = 0; aa <= L; ++aa) {
//            if (v0 == elti) {
//                //======searching for b======
//                for (int b = X - 1; b >= a; --b) {
//                    v2 = tab[( X - b - 1 ) % 4];
//                    for (int bb = L - 1; bb >= -1; --bb) {
//                        if (a == b && aa > bb) {
//                            break;//there is no middle any more
//                        }
//                        if (v2 == eltk) {
//                            if (a == b) {
//                                //v2 = computeStr(s.substr(aa, bb-aa+1));
//                                v1 = computeStr(s, s.begin() + aa, s.begin() + bb + 1);
//                            } else {
//                                //v2 = computeStr(s.substr(aa));
//                                v1 = computeStr(s, s.begin() + aa, s.end());
//                                v1 = mul(v1, tab[b - a - 1]);
//                                //v2 = mul(v2, computeStr(s.substr(0, bb + 1)));
//                                v1 = mul(v1, computeStr(s, s.begin(), s.begin() + bb + 1));
//                            }
//                            if (v1 == eltj) {
//                                return "YES";
//                            }
//                        }
//                        if (b >= 0) {
//                            v2 = mul(getElt(s[bb]), v2);
//                        }
//                    }
//                }
//                //======end of searching for b======
//            }
//            if (aa < L) {
//                v0 = mul(v0, getElt(s[aa]));
//            }
//        }
//
//    }
//    return "NO";
//
//    //if (s.size() < 3) {
//    //    return "NO";
//    //}
//    //if (s.size() == 3) {
//    //    return ( s == "ijk" ) ? "YES" : "NO";
//    //}
//}





//
////c = a\b, or a*c==b
//Elt leftDiv(Elt a, Elt b) {
//    Elt e;
//    for (e.val = 0; e.val < 4; ++e.val) {
//        e.sign = -1;
//        if (mul(a, e) == b) return e;
//        e.sign = 1;
//        if (mul(a, e) == b) return e;
//    }
//
//    //e.sign = a.sign * b.sign;
//    //a.sign = b.sign = 1;
//
//    //Elt minusb = b;
//    //minusb.sign = b.sign *( -1 );
//    //for (unsigned int i = 0; i < 4; ++i) {
//    //    if (b == lookup[a.val][i] || minusb == lookup[a.val][i]) {
//    //        e.val = i;
//    //        return e;
//    //    }
//    //}
//    assert(false);
//    return Elt();
//}